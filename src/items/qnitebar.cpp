#include "qnitebar.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitebarpainter.h"

#include <QSGNode>
#include <algorithm>
#include <cmath>

QniteBar::QniteBar(QQuickItem *parent)
    : QniteXYArtist(parent), m_fixedWidth{10}, m_leftPadding{0},
      m_rightPadding{0}, m_selectedId{-1}, m_selectedIndex{-1}, m_labelAlign{
                                                                    NONE} {}

void QniteBar::setFixedWidth(qreal w) {
  if (m_fixedWidth != w) {
    m_fixedWidth = w;
    emit fixedWidthChanged();

    update();
  }
}

void QniteBar::setLeftPadding(qreal leftPadding) {

  if (m_leftPadding != leftPadding) {
    m_leftPadding = leftPadding;
    emit leftPaddingChanged();

    update();
  }
}

void QniteBar::setRightPadding(qreal rightPadding) {

  if (m_rightPadding != rightPadding) {
    m_rightPadding = rightPadding;
    emit rightPaddingChanged();

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

void QniteBar::setLabelAlign(const LabelAlign &position) {
  if (m_labelAlign != position) {
    m_labelAlign = position;
    emit labelAlignChanged();
  }
}

void QniteBar::setLabelsText(const QStringList &labels) {
  if (m_labelsText != labels) {
    m_labelsText = labels;
    emit labelsTextChanged();
  }
}

bool QniteBar::select(QPoint p) {
  auto accepted = false;

  if (m_xMapped.size() < 1) {
    m_selectedId = -1;
  } else {
    // select the nearest bar
    auto upper = std::upper_bound(m_xMapped.cbegin(), m_xMapped.cend(), p.x());
    auto selected = upper;
    if (upper != m_xMapped.cbegin() 
        && std::fabs((upper-1).value() - p.x()) < std::fabs(upper.value() - p.x()))
      selected = upper-1;
    
    m_selectedId = selected.key();
    m_selectedIndex = static_cast<int>(std::distance(m_xMapped.cbegin(), selected));

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
