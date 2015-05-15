#include "qniteselecttool.h"

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

#include <QDebug>

QniteSelectTool::QniteSelectTool(QQuickItem* parent):
  QniteTool(parent)
{
  setAcceptedMouseButtons(Qt::LeftButton);
  setFlag(ItemHasContents, true);
}

QVariantList QniteSelectTool::selection() const
{
  QVariantList values;
  for(auto& p: m_selection)
    values.push_back(QVariant{p});
  return values;
}

void QniteSelectTool::begin(const QPoint &point)
{
  m_selection << point;
  emit selectionChanged();
}

void QniteSelectTool::append(const QPoint &point)
{
  m_selection << point;
  emit selectionChanged();
  update();
}

void QniteSelectTool::end()
{
  m_selection.clear();
  emit selectionChanged();
  update();
}

void QniteSelectTool::mousePressEvent(QMouseEvent *event)
{
  begin(event->pos());
}

void QniteSelectTool::mouseMoveEvent(QMouseEvent *event)
{
  append(event->pos());
}

void QniteSelectTool::mouseReleaseEvent(QMouseEvent *)
{
  end();
}

QSGNode* QniteSelectTool::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
  auto node = static_cast<QSGGeometryNode*>(oldNode);
  QSGGeometry* geometry;

  if (!node) {
    node = new QSGGeometryNode;
    geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), m_selection.size());
    geometry->setDrawingMode(GL_TRIANGLE_FAN);
    node->setGeometry(geometry);
    node->setFlag(QSGNode::OwnsGeometry);

    QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
    material->setColor(QColor(119, 204, 204, 50)); // TODO: this color should be a property
    node->setMaterial(material);
    node->setFlag(QSGNode::OwnsMaterial);
  } else {
    geometry = node->geometry();
    geometry->allocate(m_selection.size());
  }

  QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
  for(int i = 0; i < m_selection.size(); ++i) {
    auto& f = m_selection.at(i);
    vertices[i].set(f.x(), f.y());
  }

  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

  return node;
}
