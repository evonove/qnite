#include "qnitecircle.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitecirclepainter.h"
#include "qniteclipper.h"
#include "qnitemapper.h"

#include <QLoggingCategory>
#include <QPolygon>

Q_LOGGING_CATEGORY(qnitecircle, "qnite.circle")

constexpr auto SELECTION_TOLERANCE = 20;

QniteCircle::QniteCircle(QQuickItem *parent)
    : QniteXYArtist(parent), m_highlightedId{-1}, m_highlightedIndex{-1} {
  setFlag(ItemHasContents, true);
  setClipper(new QniteClipper(this));
}

QniteCircle::~QniteCircle() {}

bool QniteCircle::select(const QList<QPoint> &path) {
  // nothing to select
  if (path.isEmpty()) {
    return false;
  }

  // when there are less than 3 point we use the point selection
  // algorithm which should select the nearest point
  if (path.size() < 3) {
    return select(path.first());
  }

  // create a polygon with the path so it is easier to check
  // if a point is in the path or not
  auto polygonPath = QPolygonF(QVector<QPoint>::fromList(path));

  // cycle through all the points and save those contained
  // in the polygon
  m_selectedIds.clear();
  auto ids = m_xMapped.keys();
  for (auto id : ids) {
    QPointF cp(m_xMapped.value(id), m_yMapped.value(id));

    if (polygonPath.containsPoint(cp, Qt::OddEvenFill)) {
      m_selectedIds << id;
    }
  }

  // no points have been selected
  if (m_selectedIds.isEmpty()) {
    return false;
  }

  emit selectedChanged();
  update();
  return true;
}

bool QniteCircle::select(const QPoint p) {
  // these variables are needed to keep
  // track of the nearest point during the search
  auto nearestId = -1;
  // we only evaluate points whose distance is below a
  // predefined tolerance
  qreal nearestDistance = SELECTION_TOLERANCE;

  auto ids = m_xMapped.keys();
  auto index = 0;
  for (auto id : ids) {
    QPointF cp(m_xMapped.value(id), m_yMapped.value(id));
    QPointF d = p - cp;
    auto distance = d.manhattanLength();
    if (distance < nearestDistance) {
      nearestId = id;
      nearestDistance = distance;
    }
    index++;
  }

  // add the index to the selected points pool
  if (nearestId >= 0) {
    m_selectedIds.insert(nearestId);
    auto nearestIndex = m_xValues.keys().indexOf(nearestId);
    m_selectedIndexes.insert(nearestIndex);
    emit selectedChanged();
    update();
    return true;
  }

  return false;
}

void QniteCircle::clearSelection() {
  m_selectedIds.clear();
  m_selectedIndexes.clear();
  m_highlightedId = -1;
  m_highlightedIndex = -1;
  emit selectedChanged();
  update();
}

void QniteCircle::select(QList<int> indexes) {
  m_selectedIds.clear();
  m_selectedIndexes.clear();
  for (auto i : indexes) {
    if (i >= 0 && i < m_xValues.size()) {
      auto it = m_xValues.constBegin();
      it = it + i;
      m_selectedIds << it.key();
      m_selectedIndexes << i;
    }
  }
  // TODO: should emit selectedChanged???
  update();
}

void QniteCircle::highlight(int index) {
  if (index >= 0 && index < m_xValues.size()) {
    auto it = m_xValues.constBegin();
    it = it + index;
    m_highlightedId = it.key();
    m_highlightedIndex = index;
  }

  update();
}

QNanoQuickItemPainter *QniteCircle::createItemPainter() const {
  return new QniteCirclePainter;
}
