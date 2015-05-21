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
  m_fill{false},
  m_selected{false}
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

  // TODO: handle selection highlight in a proper way
  QSGFlatColorMaterial * material = new QSGFlatColorMaterial;
  if (selected()) {
    material->setColor(color().lighter(200));
  }
  else {
    material->setColor(color());
  }

  if (!oldNode) {
    node = new QSGGeometryNode;
    geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), dataSize);
    geometry->setLineWidth(2);
    geometry->setDrawingMode(GL_LINE_STRIP);
    node->setGeometry(geometry);
    node->setFlag(QSGNode::OwnsGeometry);
    node->setFlag(QSGNode::OwnsMaterial);
  } else {
    node = static_cast<QSGGeometryNode *>(oldNode);
    geometry = node->geometry();
    geometry->allocate(dataSize);
  }
  node->setMaterial(material);

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

/*!
  Temporary implementation of the selection logic for lines.

  TODO: fix the implementation
  TODO: can we assume data is alwayws already mapped at this point?
 */
bool QniteLine::select(QPoint p)
{
  bool accepted = false;

  // get the distance from the first point on the path
  int dataSize = xMapped().size();
  for(int i = 0; i < dataSize; ++i) {
    QPoint cp(xMapped().at(i), yMapped().at(i));
    QPoint d = p - cp;
    if (d.manhattanLength() < 10) {
      m_selected = true;
      accepted = true;
      axes()->setOnTop(this);
      update();
      break;
    }
  }

  return accepted;
}

bool QniteLine::select(const QList<QPoint>& path)
{
  if (path.size()) {
    return select(path.first());
  }

  return false;
}

void QniteLine::clearSelection()
{
  m_selected = false;
  update();
}
