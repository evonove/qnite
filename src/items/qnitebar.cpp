#include "qnitebar.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitebarpainter.h"

#include <QSGNode>
#include <algorithm>

QniteBar::QniteBar(QQuickItem *parent)
    : QniteXYArtist(parent), m_fixedWidth{10}, m_selectedId{-1},
      m_selectedIndex{-1} {}

void QniteBar::setFixedWidth(qreal w) {
  if (m_fixedWidth != w) {
    m_fixedWidth = w;
    emit fixedWidthChanged();

    update();
  }
}

void QniteBar::setCategories(const QStringList &c) {
  if (m_categories != c) {
    m_categories = c;
    emit categoriesChanged();

    // updated the xValues according to the category list
    auto values = QList<qreal>{};
    auto step = 1.0 / (m_categories.size() + 1);
    for (auto i = 0; i < m_categories.size(); ++i)
      values.push_back(step * (i + 1));
    setXValues(values);

    update();
  }
}

bool QniteBar::select(QPoint p) {
  auto accepted = false;

  if (m_xMapped.size() < 1) {
    m_selectedId = -1;
  } else {
    auto upper = std::upper_bound(m_xMapped.cbegin(), m_xMapped.cend(), p.x());
    if (upper != m_xMapped.cbegin()) {
      upper--;
    }
    m_selectedId = upper.key();
    m_selectedIndex = static_cast<int>(std::distance(upper, m_xMapped.cend()));

    accepted = true;
  }

  emit selectedChanged();
  update();

  return accepted;
}

bool QniteBar::select(const QList<QPoint> &path) {
  if (path.size()) {
    return select(path.first());
  }

  return false;
}

void QniteBar::clearSelection() {
  m_selectedId = -1;
  m_selectedIndex = -1;
  emit selectedChanged();
  update();
}

QNanoQuickItemPainter *QniteBar::createItemPainter() const {
  return new QniteBarPainter;
}

bool QniteBar::isSelected() const { return m_selectedId >= 0; }
