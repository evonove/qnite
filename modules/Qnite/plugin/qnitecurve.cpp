#include "qnitecurve.h"
#include "qnitemapper.h"
#include "qniteaxes.h"
#include "qniteaxis.h"

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

  // TODO: move the transform into a pipeline
  qreal xLower = axes()->bottomAxis()->lowerBound();
  qreal xUpper = axes()->bottomAxis()->upperBound();
  qreal yLower = axes()->leftAxis()->lowerBound();
  qreal yUpper = axes()->leftAxis()->upperBound();

  QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
  for(int i = 0; i < dataSize; ++i) {
    // TODO: this is bad here! move transformation in the setters
    qreal cx = xMapper()->mapTo(xLower, xUpper, 0, width(), xValues().at(i));
    qreal cy = yMapper()->mapTo(yLower, yUpper, 0, height(), yValues().at(i), true);

    vertices[i].set(cx, cy);
  }

  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

  return node;
}

