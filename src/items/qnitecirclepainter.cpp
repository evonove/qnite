#include <QLoggingCategory>

#include "qnitecircle.h"
#include "qnitecirclepainter.h"

Q_LOGGING_CATEGORY(qnitecirclepainter, "qnite.circle.painter")

QniteCirclePainter::QniteCirclePainter() : QNanoQuickItemPainter{} {}

void QniteCirclePainter::synchronize(QNanoQuickItem *item) {
  qCDebug(qnitecirclepainter) << "synchronizing qnitecircle";

  auto circleItem = static_cast<QniteCircle *>(item);
  if (circleItem != Q_NULLPTR) {
    circleItem->processData();

    // TODO: here we could share painting data using a class
    // which is copied with all its members in a local instance.
    m_xs = circleItem->xMapped();
    m_ys = circleItem->yMapped();

    // make a local copy of the pen
    m_pen = circleItem->pen()->data();
    m_selectedPen = circleItem->selectedPen()->data();
    m_highlightedPen = circleItem->highlightedPen()->data();
    m_selected = circleItem->selected();

    // circle specific properties
    m_selectedIds = circleItem->selectedIds();
    m_highlightedId = circleItem->highlightedId();
  }
}

void QniteCirclePainter::paint(QNanoPainter *painter) {
  qCDebug(qnitecirclepainter) << "painting qnitecircle";

  if (m_xs.size() < 1) {
    return;
  }

  painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
  painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
  painter->setLineWidth(m_pen.width);
  painter->setLineJoin(m_pen.join);
  painter->setLineCap(m_pen.cap);

  // draw unselected points
  auto ids = m_xs.keys();
  for (auto id : ids) {
    // we do not draw selected or highlighted ids because we draw them later
    if (m_selectedIds.contains(id) || m_highlightedId == id) {
      continue;
    }
    painter->beginPath();
    painter->circle(m_xs.value(id), m_ys.value(id), m_pen.radius);
    painter->fill();
    painter->stroke();
  }

  // draw selected points
  if (m_selectedIds.size() > 0) {
    painter->setStrokeStyle(QNanoColor::fromQColor(m_selectedPen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_selectedPen.fill));
    painter->setLineWidth(m_selectedPen.width);
    painter->setLineJoin(m_selectedPen.join);
    painter->setLineCap(m_selectedPen.cap);

    for (auto id : m_selectedIds) {
      // we don't draw highlighted ids here, nor those currently not visible
      if (id == m_highlightedId || !ids.contains(id)) {
        continue;
      }

      painter->beginPath();
      painter->circle(m_xs.value(id), m_ys.value(id), m_selectedPen.radius);
      painter->fill();
      painter->stroke();
    }
  }

  // draw highlighted point if visible
  if (m_highlightedId > -1 && ids.contains(m_highlightedId)) {
    painter->setStrokeStyle(QNanoColor::fromQColor(m_highlightedPen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_highlightedPen.fill));
    painter->setLineWidth(m_highlightedPen.width);
    painter->setLineJoin(m_highlightedPen.join);
    painter->setLineCap(m_highlightedPen.cap);

    painter->beginPath();
    painter->circle(m_xs.value(m_highlightedId), m_ys.value(m_highlightedId),
                    m_highlightedPen.radius);
    painter->fill();
    painter->stroke();
  }
}
