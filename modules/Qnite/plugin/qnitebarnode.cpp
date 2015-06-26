#include "qnitebarnode.h"

#include <QDebug>
#include <QColor>
#include <QSGFlatColorMaterial>

QniteBarNode::QniteBarNode(qreal x, qreal y, qreal baseline, qreal size, const QColor &color)
{
  auto geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 4);
  geometry->setDrawingMode(GL_TRIANGLE_STRIP);
  setGeometry(geometry);
  setFlag(QSGNode::OwnsGeometry);

  auto material = new QSGFlatColorMaterial;
  material->setColor(color);
  setMaterial(material);
  setFlag(QSGNode::OwnsMaterial);

  QSGGeometry::Point2D *v = geometry->vertexDataAsPoint2D();
  v[0].set(x, baseline);
  v[1].set(x, y);
  v[2].set(x + size, baseline);
  v[3].set(x + size, y);

  markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);
}
