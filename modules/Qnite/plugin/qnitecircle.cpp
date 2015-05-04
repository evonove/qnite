#include "qnitecircle.h"
#include "qnitemapper.h"
#include "qnitecirclenode.h"
#include "qniteaxes.h"
#include "qniteaxis.h"

#include <QDebug>


QniteCircle::QniteCircle(QQuickItem *parent):
  QniteArtist(parent),
  m_radius{10}
{
  setFlag(ItemHasContents, true);
}

QniteCircle::~QniteCircle()
{
}

qreal QniteCircle::radius() const
{
  return m_radius;
}

void QniteCircle::setRadius(qreal radius)
{
  if (m_radius != radius) {
    m_radius = radius;
    emit radiusChanged();
  }
}

QSGNode* QniteCircle::updatePaintNode(QSGNode* node, UpdatePaintNodeData*)
{
  if (!node) {
    node = new QSGNode;
  }

  // TODO: processdata should be triggered only when data changes
  processData();
  int dataSize = xMapped().size();

  // TODO: find a better approach. removing and creating all nodes is bad
  node->removeAllChildNodes();
  for(int i = 0; i < dataSize; ++i) {
    qreal cx = xMapped().at(i);
    qreal cy = yMapped().at(i);

    // TODO: optimal number of segments should be  computed runtime
    node->appendChildNode(new QniteCircleNode(cx, cy, m_radius, 32, color()));
  }

  return node;
}

