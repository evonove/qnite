#include <QLoggingCategory>

#include "qnitebar.h"
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
    m_xs = barItem->xProcessed();
    m_ys = barItem->yProcessed();

    // make a local copy of the pen
    m_pen = barItem->pen()->data();
    m_selectedPen = barItem->selectedPen()->data();
    m_selected = barItem->selected();

    // bar specific properties
    m_fixedWidth = barItem->fixedWidth();
    m_selectedIndex = barItem->selectedIndex();
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
  for (auto i = 0; i < dataSize; ++i) {
    // we do not draw selected index because we draw it later
    // with a different pen
    if (i == m_selectedIndex) {
      continue;
    }
    drawBar(m_xs.at(i), m_ys.at(i));
  }

  if (m_selectedIndex >= 0) {
    // use the selectedPen
    painter->setStrokeStyle(QNanoColor::fromQColor(m_selectedPen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_selectedPen.fill));
    painter->setLineWidth(m_selectedPen.width);
    painter->setLineJoin(m_selectedPen.join);
    painter->setLineCap(m_selectedPen.cap);

    drawBar(m_xs.at(m_selectedIndex), m_ys.at(m_selectedIndex));
  }
}

void QniteBarPainter::drawBar(qreal x, qreal y) {
  auto cx = x - m_fixedWidth / 2.0;
  auto height = m_baseline - y;
  painter()->beginPath();
  painter()->rect(cx, m_baseline, m_fixedWidth, height);
  painter()->fill();
  painter()->stroke();
}
