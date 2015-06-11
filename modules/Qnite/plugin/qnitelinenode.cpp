#include "qnitelinenode.h"

#include <QColor>
#include <QSGFlatColorMaterial>

QniteLineNode::QniteLineNode(float size, const QColor &color):
  m_geometry(QSGGeometry::defaultAttributes_Point2D(), 0)
{
  setGeometry(&m_geometry);
  m_geometry.setLineWidth(size);
  m_geometry.setDrawingMode(GL_LINE_STRIP);

  auto material = new QSGFlatColorMaterial;
  material->setColor(color);
  setMaterial(material);
  setFlag(OwnsMaterial);
}

void QniteLineNode::updateGeometry(const QList<qreal>& xs, const QList<qreal>& ys)
{
  int dataSize = xs.size();
  m_geometry.allocate(dataSize);

  QSGGeometry::Point2D *v = m_geometry.vertexDataAsPoint2D();
  for (int i = 0; i < dataSize; ++i)
    v[i].set(xs.at(i), ys.at(i));

  markDirty(QSGNode::DirtyGeometry);
}

