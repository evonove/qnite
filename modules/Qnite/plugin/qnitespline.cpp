#include "qnitespline.h"
#include "qniteaxes.h"
#include "qniteaxis.h"

#include <QtMath>
#include <QDebug>

#include <QSGGeometry>
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>

namespace {

double CosineInterpolate(
   double y1,double y2,
   double mu)
{
   double mu2;

   mu2 = (1-cos(mu*M_PI))/2;
   return(y1*(1-mu2)+y2*mu2);
}

double CubicInterpolate(
   double y0,double y1,
   double y2,double y3,
   double mu)
{
   double a0,a1,a2,a3,mu2;

   mu2 = mu*mu;
   a0 = y3 - y2 - y0 + y1;
   a1 = y0 - y1 - a0;
   a2 = y2 - y0;
   a3 = y1;

   return(a0*mu*mu2+a1*mu2+a2*mu+a3);
}

double CatmullRomInterpolate(
   double y0,double y1,
   double y2,double y3,
   double mu)
{
   double a0,a1,a2,a3,mu2;

   mu2 = mu*mu;
   a0 = -0.5*y0 + 1.5*y1 - 1.5*y2 + 0.5*y3;
   a1 = y0 - 2.5*y1 + 2*y2 - 0.5*y3;
   a2 = -0.5*y0 + 0.5*y2;
   a3 = y1;

   return(a0*mu*mu2+a1*mu2+a2*mu+a3);
}

double HermiteInterpolate(
   double y0,double y1,
   double y2,double y3,
   double mu,
   double tension = 0,
   double bias = 0)
{
   double m0,m1,mu2,mu3;
   double a0,a1,a2,a3;

   mu2 = mu * mu;
   mu3 = mu2 * mu;
   m0  = (y1-y0)*(1+bias)*(1-tension)/2;
   m0 += (y2-y1)*(1-bias)*(1-tension)/2;
   m1  = (y2-y1)*(1+bias)*(1-tension)/2;
   m1 += (y3-y2)*(1-bias)*(1-tension)/2;
   a0 =  2*mu3 - 3*mu2 + 1;
   a1 =    mu3 - 2*mu2 + mu;
   a2 =    mu3 -   mu2;
   a3 = -2*mu3 + 3*mu2;

   return(a0*y1+a1*m0+a2*m1+a3*y2);
}

}

QniteSpline::QniteSpline(QQuickItem *parent):
  QniteLine(parent),
  m_interpolation{Interpolation::Cubic},
  m_tension{0},
  m_bias{0}
{
}

QniteSpline::~QniteSpline()
{
}

void QniteSpline::setInterpolation(Interpolation i)
{
  if (m_interpolation != i) {
    m_interpolation = i;
    emit interpolationChanged();
    update();
  }
}

void QniteSpline::setTension(qreal t)
{
  if (m_tension != t) {
    m_tension = t;
    emit tensionChanged();
    update();
  }
}

void QniteSpline::setBias(qreal b)
{
  if (m_bias != b) {
    m_bias = b;
    emit biasChanged();
    update();
  }
}

void QniteSpline::processData()
{
  QniteXYArtist::processData();

  switch(m_interpolation) {
    case Interpolation::Cosine:
      cosineInterpolation();
      break;
    case Interpolation::Cubic:
    case Interpolation::CatmullRom:
    case Interpolation::Hermite:
      cubicInterpolation();
      break;
  }

}

void QniteSpline::cosineInterpolation()
{
  QList<qreal> xs;
  QList<qreal> ys;

  const auto& xv = xMapped();
  const auto& yv = yMapped();

  int n = xv.size() - 1;
  int res = 2;

  for(int i = 0; i < n; ++i) {
    qreal distance = xv.at(i+1) - xv.at(i);
    int steps = distance / res;
    qreal step = 1. / steps;

    for (int j = 0; j <= steps; ++j) {
      qreal s = step * j;
      qreal x = xv.at(i) + (xv.at(i+1) - xv.at(i)) * s;
      qreal y = CosineInterpolate(yv.at(i), yv.at(i+1), s);

      xs.push_back(x);
      ys.push_back(y);
    }
  }

  qDebug() << "cosine input size" << xv.size();
  qDebug() << "cosine output size" << xs.size();

  m_xProcessed = xs;
  m_yProcessed = ys;
}

void QniteSpline::cubicInterpolation()
{
  QList<qreal> xs;
  QList<qreal> ys;

  auto xv = xMapped();
  auto yv = yMapped();

  auto n = xv.size();
  auto res = 2;

  // dream up two extra points at the start and at the end
  // of the sequence. These are needed by the cubic interpolation
  // algorithm
  xv.insert(0, xv.at(0) - (xv.at(1) - xv.at(0)));
  yv.insert(0, yv.at(0) - (yv.at(1) - yv.at(0)));

  auto l = xv.size() - 1;
  xv.append(xv.at(l) + (xv.at(l) - xv.at(l-1)));
  yv.append(yv.at(l) + (yv.at(l) - yv.at(l-1)));

  for(int i = 1; i < n; ++i) {
    qreal distance = xv.at(i+1) - xv.at(i);
    int steps = distance / res;
    qreal step = 1. / steps;

    for (int j = 0; j <= steps; ++j) {
      qreal s = step * j;
      qreal x = xv.at(i) + (xv.at(i+1) - xv.at(i)) * s;
      qreal y;
      if (m_interpolation == Interpolation::Hermite) {
        y = HermiteInterpolate(yv.at(i-1), yv.at(i), yv.at(i+1), yv.at(i+2), s, m_tension, m_bias);
      } else if (m_interpolation == Interpolation::Cubic) {
        y = CubicInterpolate(yv.at(i-1), yv.at(i), yv.at(i+1), yv.at(i+2), s);
      } else {
        y = CatmullRomInterpolate(yv.at(i-1), yv.at(i), yv.at(i+1), yv.at(i+2), s);
      }

      xs.push_back(x);
      ys.push_back(y);
    }
  }

  qDebug() << "cubic input size" << xv.size();
  qDebug() << "cubic output size" << xs.size();

  m_xProcessed = xs;
  m_yProcessed = ys;
}
