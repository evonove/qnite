#include "qnitespline.h"
#include "qnitefillnode.h"
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

}


QniteSpline::QniteSpline(QQuickItem *parent):
  QniteLine(parent)
{
}

QniteSpline::~QniteSpline()
{
}

void QniteSpline::processData()
{
  QniteXYArtist::processData();

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

  qDebug() << "input size" << xv.size();
  qDebug() << "output size" << xs.size();

  m_xProcessed = xs;
  m_yProcessed = ys;
}

