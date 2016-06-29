#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

#include "qnitepathselectiontool.h"
#include "qnitepathpainter.h"
#include "qniteartist.h"
#include "qnitepen.h"


QnitePathSelectionTool::QnitePathSelectionTool(QQuickItem* parent)
    : QniteSelectionTool(parent)
    , m_pen{new QnitePen}
{
    m_pen->setFill("#e3f2fd");
    m_pen->setStroke("#2196f3");
    m_pen->setWidth(2.0);
}

QVariantList QnitePathSelectionTool::selectionPath() const
{
  QVariantList values;
  for(auto& p: m_selection)
    values.push_back(QVariant{p});
  return values;
}

void QnitePathSelectionTool::begin(const QPoint &point)
{
  m_selection << point;
  clearSelection();  // TODO: this is a "select exclusive" behaviour, should not be hardcoded
  select();
  emit selectionPathChanged();
  update();
}

void QnitePathSelectionTool::append(const QPoint &point)
{
  m_selection << point;
  select();
  emit selectionPathChanged();
  update();
}

void QnitePathSelectionTool::end()
{
  m_selection.clear();
  emit selectionPathChanged();
  update();
}

QNanoQuickItemPainter* QnitePathSelectionTool::createItemPainter() const
{
    return new QnitePathPainter;
}

void QnitePathSelectionTool::mousePressEvent(QMouseEvent *event)
{
  begin(event->pos());
}

void QnitePathSelectionTool::mouseMoveEvent(QMouseEvent *event)
{
  append(event->pos());
}

void QnitePathSelectionTool::mouseReleaseEvent(QMouseEvent *)
{
  end();
}

//QSGNode* QnitePathSelectionTool::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
//{
//  auto node = static_cast<QSGGeometryNode*>(oldNode);
//  QSGGeometry* geometry;

//  if (!node) {
//    node = new QSGGeometryNode;
//    geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), m_selection.size());
//    geometry->setDrawingMode(GL_TRIANGLE_FAN);
//    node->setGeometry(geometry);
//    node->setFlag(QSGNode::OwnsGeometry);

//    QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
//    material->setColor(QColor(119, 204, 204, 50)); // TODO: this color should be a property
//    node->setMaterial(material);
//    node->setFlag(QSGNode::OwnsMaterial);
//  } else {
//    geometry = node->geometry();
//    geometry->allocate(m_selection.size());
//  }

//  QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
//  for(int i = 0; i < m_selection.size(); ++i) {
//    auto& f = m_selection.at(i);
//    vertices[i].set(f.x(), f.y());
//  }

//  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

//  return node;
//}

bool QnitePathSelectionTool::doSelect(QniteArtist * artist)
{
  return artist->select(m_selection);
}
