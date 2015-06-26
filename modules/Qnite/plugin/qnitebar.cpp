#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitebar.h"
#include "qnitebarnode.h"

#include <QDebug>
#include <QSGNode>

QniteBar::QniteBar(QQuickItem *parent):
  QniteXYArtist(parent),
  m_barsNode{nullptr}
{
  setFlag(ItemHasContents, true);
}

QniteBar::~QniteBar()
{
}

QSGNode* QniteBar::updatePaintNode(QSGNode* node, UpdatePaintNodeData*)
{
  processData();

  int dataSize = xProcessed().size();
  if (dataSize < 1)
    return nullptr;

  if (node == nullptr)
    node = new QSGNode;

  updateBars(node);

  return node;
}

void QniteBar::updateBars(QSGNode* node)
{
  if (m_barsNode == nullptr) {
    m_barsNode = new QSGNode;
    node->appendChildNode(m_barsNode);
  }

  m_barsNode->removeAllChildNodes();
  qreal baseline = axes()->leftAxis()->position();

  int dataSize = xProcessed().size();
  for(int i = 0; i < dataSize; ++i) {
    qreal cx = xProcessed().at(i);
    qreal cy = yProcessed().at(i);

    m_barsNode->appendChildNode(new QniteBarNode(cx, cy, baseline, 10, color()));
  }
}
