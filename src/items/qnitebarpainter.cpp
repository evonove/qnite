#include <QLoggingCategory>

#include "qnitebarpainter.h"

#include "qniteaxes.h"
#include "qniteaxis.h"

Q_LOGGING_CATEGORY(qnitebarpainter, "qnite.bar.painter")

QniteBarPainter::QniteBarPainter() : QNanoQuickItemPainter{} {}

void QniteBarPainter::synchronize(QNanoQuickItem *item) {
  qCDebug(qnitebarpainter) << "synchronizing qnitebar";

  auto barItem = static_cast<QniteBar *>(item);
  if (barItem != Q_NULLPTR) {
    barItem->processData();

    // TODO: here we could share painting data using a class
    // which is copied with all its members in a local instance.
    m_xs = barItem->xMapped();
    m_ys = barItem->yMapped();

    // make a local copy of the pen
    m_pen = barItem->pen()->data();
    m_selectedPen = barItem->selectedPen()->data();
    m_selected = barItem->selected();

    // bar specific properties
    m_fixedWidth = barItem->fixedWidth();
    m_selectedId = barItem->selectedId();
    m_labelAlign = barItem->labelAlign();
    m_labelsText = barItem->labelsText();
    // the baseline is the position of the y axis
    // this is needed to compute a the starting point of the bar
    m_baseline = barItem->axes()->axisY()->position();
  }
}

void QniteBarPainter::paint(QNanoPainter *painter) {
  qCDebug(qnitebarpainter) << "painting qnitebar";

  auto dataSize = m_xs.size();
  if (dataSize < 1)
    return;

  painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
  painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
  painter->setLineWidth(m_pen.width);
  painter->setLineJoin(m_pen.join);
  painter->setLineCap(m_pen.cap);

  // draw unselected points
  auto ids = m_xs.keys();
  for (auto id : ids) {
    // we do not draw selected ids because we draw it later
    // with a different pen
    if (id == m_selectedId) {
      continue;
    }

    drawBar(m_xs.value(id), m_ys.value(id));
  }

  // Draw selected items only they're currently visible
  if (m_selectedId >= 0 && ids.contains(m_selectedId)) {
    // use the selectedPen
    painter->setStrokeStyle(QNanoColor::fromQColor(m_selectedPen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_selectedPen.fill));
    painter->setLineWidth(m_selectedPen.width);
    painter->setLineJoin(m_selectedPen.join);
    painter->setLineCap(m_selectedPen.cap);

    drawBar(m_xs.value(m_selectedId), m_ys.value(m_selectedId));
  }

  // Draw some text inside bar items. The text is aligned in the position
  // passed as q_property.
  switch (m_labelAlign) {
  case QniteBar::NONE:
    break;
  case QniteBar::TOP:
    QNanoFont font(QNanoFont::DEFAULT_FONT_BOLD);
    font.setPixelSize(14);
    painter->setFont(font);
    painter->setTextAlign(QNanoPainter::ALIGN_CENTER);
    painter->setTextBaseline(QNanoPainter::BASELINE_TOP);
    painter->setPixelAlignText(QNanoPainter::PIXEL_ALIGN_FULL);

    for (auto id : ids) {
      auto cx = m_xs.value(id);
      auto height = m_ys.value(id) - m_baseline;

      // For now we want to see label in items that has an
      // height higher or lower to zero.
      if (!qFuzzyCompare(height, 0)) {
        drawText(m_xs.value(id), m_ys.value(id), m_labelsText.value(id));
      }
    }
    break;
  }
}

void QniteBarPainter::drawBar(qreal x, qreal y) {
  auto cx = x - m_fixedWidth / 2.0;
  auto height = y - m_baseline;
  painter()->beginPath();
  painter()->rect(cx, m_baseline, m_fixedWidth, height);
  painter()->fill();
  painter()->stroke();
}

void QniteBarPainter::drawText(qreal x, qreal y, const QString &text) {
  auto cx = x - m_fixedWidth / 2.0;
  auto height = (y - m_baseline) / 2.0;

  painter()->beginPath();
  m_pen.fill = QColor(255, 255, 255);
  painter()->setFillStyle(QNanoColor::fromQColor(m_pen.fill));

  painter()->fillText(text,
                      QRect(x - m_fixedWidth / 2.0, y, m_fixedWidth, height));
  painter()->fill();
  painter()->stroke();
}
