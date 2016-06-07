#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitebar.h"
#include "qnitebarpainter.h"

#include <algorithm>
#include <QDebug>
#include <QSGNode>


QniteBar::QniteBar(QQuickItem *parent):
  QniteXYArtist(parent),
  m_fixedWidth{10},
  m_selectedIndex{-1}
{
}

void QniteBar::setFixedWidth(qreal w)
{
  if (m_fixedWidth != w) {
    m_fixedWidth = w;
    emit fixedWidthChanged();

    update();
  }
}

void QniteBar::setCategories(const QStringList& c)
{
  if (m_categories != c) {
    m_categories = c;
    emit categoriesChanged();

    // updated the xValues according to the category list
    auto values = QList<qreal>{};
    auto step = 1.0 / (m_categories.size() + 1);
    for(auto i = 0; i < m_categories.size(); ++i)
      values.push_back(step*(i+1));
    setXValues(values);

    update();
  }
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

void QniteBar::clearSelection()
{
  m_selectedIndex = -1;
  emit selectedChanged();
  update();
}

QNanoQuickItemPainter* QniteBar::createItemPainter() const
{
    return new QniteBarPainter;
}

bool QniteBar::isSelected() const
{
  return m_selectedIndex >= 0;
}

//QSGNode* QniteBar::updatePaintNode(QSGNode* node, UpdatePaintNodeData*)
//{
  //processData();

  //auto dataSize = xProcessed().size();
  //if (dataSize < 1)
    //return nullptr;

  //if (node == nullptr) {
    //node = new QSGNode;
    //m_barsNode = new QSGNode;
    //node->appendChildNode(m_barsNode);
  //}
  //updateBars();

  //return node;
//}

//void QniteBar::updateBars()
//{
  //m_barsNode->removeAllChildNodes();

  //qreal baseline = axes()->axisY()->position();

  //auto dataSize = xProcessed().size();
  //for(int i = 0; i < dataSize; ++i) {
    //qreal cx = xProcessed().at(i);
    //qreal cy = yProcessed().at(i);

    //auto c = (i == m_selectedIndex) ? selectedPen()->fill() : pen()->fill();
    //m_barsNode->appendChildNode(new QniteBarNode(cx, cy, baseline, fixedWidth(), c));
  //}
//}
