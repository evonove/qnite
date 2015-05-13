#include "qniteline.h"
#include "qnitefillnode.h"
#include "qniteaxes.h"
#include "qniteaxis.h"

#include <QDebug>

#include <QSGGeometry>
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>


QniteLine::QniteLine(QQuickItem *parent):
  QniteXYArtist(parent),
  m_fillNode{nullptr},
  m_fill{false}
{
  setFlag(ItemHasContents, true);
}

QniteLine::~QniteLine()
{
}

void QniteLine::setFill(bool fill)
{
  if (m_fill != fill) {
    m_fill = fill;
    emit fillChanged();
  }
}

void QniteLine::setFillColor(QColor fillColor)
{
  if (m_fillColor != fillColor) {
    m_fillColor = fillColor;
    emit fillColorChanged();
  }
}

QSGNode* QniteLine::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*)
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

  if (m_fill) {
    if (m_fillNode == nullptr) {
      m_fillNode = new QniteFillNode(QColor(m_fillColor));
      node->appendChildNode(m_fillNode);
    }

    qreal ya = axes()->leftAxis()->position();
    m_fillNode->updateGeometry(xMapped(), yMapped(), ya);
  }

  QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
  for(int i = 0; i < dataSize; ++i) {
    vertices[i].set(xMapped().at(i), yMapped().at(i));
  }

  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);
  return node;
}

