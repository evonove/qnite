#include "qnitecurve.h"
#include "qnitemapper.h"

#include <QDebug>

#include <QSGGeometry>
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>


QniteCurve::QniteCurve(QQuickItem *parent):
  QniteArtist(parent)
{
  setFlag(ItemHasContents, true);
}

QniteCurve::~QniteCurve()
{
}

QSGNode* QniteCurve::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*)
{
  QSGGeometryNode *node = 0;
  QSGGeometry *geometry = 0;

  int dataSize = qMin(xValues().size(), yValues().size());
  if (xValues().size() != yValues().size())
    qWarning() << "xValues and yValues size for the artists are different";

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
    // TODO: this is bad here! move transformation in the setters
    auto vx = xValues().at(i);
    auto vy = yValues().at(i);
    float x;
    if (xMapper() != nullptr)
      x = xMapper()->transform(vx);
    else
      x = vx;
    float y;
    if (yMapper() != nullptr)
      y = yMapper()->transform(vy);
    else
      y = vy;

    vertices[i].set(x, y);
    qDebug() << "point" << x << y;
  }

  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

  return node;
}

