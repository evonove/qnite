#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitebar.h"
#include "qnitebarnode.h"

#include <algorithm>
#include <QDebug>
#include <QSGNode>

QniteBar::QniteBar(QQuickItem *parent):
  QniteXYArtist(parent),
  m_barsNode{nullptr},
  m_selectedIndex{-1}
{
  setFlag(ItemHasContents, true);
}

QniteBar::~QniteBar()
{
}

bool QniteBar::select(QPoint p)
{
  auto accepted = false;

  if (xProcessed().size() < 1) {
    m_selectedIndex = -1;
  } else {
    auto upper = std::upper_bound(xProcessed().begin(), xProcessed().end(), p.x());
    auto i = static_cast<int>(std::distance(xProcessed().begin(), upper) - 1);
    m_selectedIndex = std::max(0, i);
    accepted = true;
  }

  emit selectedChanged();
  update();

  return accepted;
}

bool QniteBar::select(const QList<QPoint>& path)
{
  if (path.size()) {
    return select(path.first());
  }

  return false;
}

// TODO: selection should be cleared when data change
void QniteBar::clearSelection()
{
  m_selectedIndex = -1;
  emit selectedChanged();
  update();
}

bool QniteBar::isSelected() const
{
  return m_selectedIndex >= 0;
}

QSGNode* QniteBar::updatePaintNode(QSGNode* node, UpdatePaintNodeData*)
{
  processData();

  auto dataSize = xProcessed().size();
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

  auto dataSize = xProcessed().size();
  for(int i = 0; i < dataSize; ++i) {
    qreal cx = xProcessed().at(i);
    qreal cy = yProcessed().at(i);

    auto c = (i == m_selectedIndex) ? selectionColor() : color();
    m_barsNode->appendChildNode(new QniteBarNode(cx, cy, baseline, 10, c));
  }
}
