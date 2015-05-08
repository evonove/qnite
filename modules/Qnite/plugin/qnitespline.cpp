#include "qnitespline.h"

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
  QniteXYArtist(parent)
{
  setFlag(ItemHasContents, true);
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

  m_xMapped = xs;
  m_yMapped = ys;
}

QSGNode* QniteSpline::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*)
{
  QSGGeometryNode *node = 0;
  QSGGeometry *geometry = 0;

  // TODO: processdata should be triggered only when data changes
  processData();
  int dataSize = xMapped().size();

  if (!oldNode) {
    node = new QSGGeometryNode;
    geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), dataSize);
    geometry->setLineWidth(2);
    geometry->setDrawingMode(GL_LINE_STRIP);
    node->setGeometry(geometry);
    node->setFlag(QSGNode::OwnsGeometry);

    QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
    material->setColor(color());
    node->setMaterial(material);
    node->setFlag(QSGNode::OwnsMaterial);
  } else {
    node = static_cast<QSGGeometryNode *>(oldNode);
    geometry = node->geometry();
    geometry->allocate(dataSize);
  }

  QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
  for(int i = 0; i < dataSize; ++i) {
    vertices[i].set(xMapped().at(i), yMapped().at(i));
  }

  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

  return node;
}
