#include <QLoggingCategory>

#include "qnitezoompainter.h"
#include "qnitezoomtool.h"

Q_LOGGING_CATEGORY(qnitezoompainter, "qnite.zoom.painter")

QniteZoomPainter::QniteZoomPainter() : QNanoQuickItemPainter{} {}

void QniteZoomPainter::synchronize(QNanoQuickItem *item) {
  qCDebug(qnitezoompainter) << "synchronizing qnitezoom";

  auto zoom = static_cast<QniteZoomTool *>(item);
  if (zoom) {
    m_rect = zoom->rect();
    m_pen = zoom->pen()->data();
  }
}

void QniteZoomPainter::paint(QNanoPainter *painter) {
  qCDebug(qnitezoompainter) << "painting qnitezoom";

  if (m_rect.isNull()) {
    return;
  }

  painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
  if (m_pen.fill.isValid()) {
    painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
  }
  painter->setLineWidth(static_cast<float>(m_pen.width));
  painter->setLineJoin(m_pen.join);
  painter->setLineCap(m_pen.cap);

  painter->beginPath();
  painter->moveTo(m_rect.topLeft());
  painter->lineTo(m_rect.topRight());
  painter->lineTo(m_rect.bottomRight());
  painter->lineTo(m_rect.bottomLeft());
  painter->closePath();
  painter->fill();
  painter->stroke();
}
