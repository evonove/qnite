#include "qnitecirclenode.h"

#include <QtMath>
#include <QColor>
#include <QSGFlatColorMaterial>

QniteCircleNode::QniteCircleNode(qreal cx, qreal cy, qreal radius, int segments, QColor color)
{
  auto geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), segments);
  geometry->setLineWidth(2);
  geometry->setDrawingMode(GL_TRIANGLE_FAN);
  setGeometry(geometry);
  setFlag(QSGNode::OwnsGeometry);

  auto material = new QSGFlatColorMaterial;
  material->setColor(color);
  setMaterial(material);
  setFlag(QSGNode::OwnsMaterial);

  // draw the circle
  QSGGeometry::Point2D* vertices = geometry->vertexDataAsPoint2D();

  // tranform matrix factors
  qreal t = 2.0 * M_PI / static_cast<qreal>(segments);
  qreal c = qCos(t);
  qreal s = qSin(t);

  // set the first point
  qreal x = radius;
  qreal y = 0;

  for(int i = 0; i < segments; ++i) {
    vertices[i].set(x + cx, y + cy);

    // transform
    qreal xp = x;
    x = x * c - y * s;
    y = xp * s + y * c;
  }
}
