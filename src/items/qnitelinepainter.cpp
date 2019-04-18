#include <QLoggingCategory>

#include "qniteline.h"
#include "qnitelinepainter.h"

#include "qniteaxes.h"
#include "qniteaxis.h"

Q_LOGGING_CATEGORY(qnitelinepainter, "qnite.line.painter")

QniteLinePainter::QniteLinePainter()
    : QNanoQuickItemPainter{}, m_selected{false}, m_drawSymbols{false},
      m_drawStepped{false} {}

void QniteLinePainter::synchronize(QNanoQuickItem *item) {
  qCDebug(qnitelinepainter) << "synchronizing qniteline";

  auto lineItem = static_cast<QniteLine *>(item);
  if (lineItem != Q_NULLPTR) {
    lineItem->processData();

    // TODO: here we could share painting data using a class
    // which is copied with all its members in a local instance.
    m_xs = lineItem->xProcessed();
    m_ys = lineItem->yProcessed();

    // we need to save mapped points to draw symbols
    // because processed points could be more because
    // of interpolation.
    m_mappedXs = lineItem->xMapped();
    m_mappedYs = lineItem->yMapped();

    // make a local copy of the pen data (stroke, fill)
    m_pen = lineItem->pen()->data();
    m_selectedPen = lineItem->selectedPen()->data();
    m_selected = lineItem->selected();

    // the baseline is the position of the y axis
    // this is needed to compute a fill polygon for the line.
    m_baseline = lineItem->axes()->axisY()->position();

    m_drawSymbols = lineItem->drawSymbols();

    m_drawStepped = lineItem->drawStepped();
  }
}

void QniteLinePainter::paint(QNanoPainter *painter) {
  qCDebug(qnitelinepainter) << "painting qniteline";

  auto dataSize = m_xs.size();
  if (dataSize < 2)
    return;

  auto &pen = m_selected ? m_selectedPen : m_pen;
  painter->setStrokeStyle(QNanoColor::fromQColor(pen.stroke));
  if (pen.fill.isValid()) {
    painter->setFillStyle(QNanoColor::fromQColor(pen.fill));
  }
  painter->setLineWidth(pen.width);
  painter->setLineJoin(pen.join);
  painter->setLineCap(pen.cap);

  // first we draw the fill when a valid fill color is available
  if (pen.fill.isValid()) {
    painter->beginPath();
    painter->moveTo(m_xs.at(0), m_baseline);
    painter->lineTo(m_xs.at(0), m_ys.at(0));
    for (auto i = 1; i < dataSize; ++i) {
      if (m_drawStepped) {
        painter->lineTo(m_xs.at(i), m_ys.at(i - 1));
      }
      painter->lineTo(m_xs.at(i), m_ys.at(i));
    }
    painter->lineTo(m_xs.at(dataSize - 1), m_baseline);
    painter->fill();
  }

  painter->beginPath();
  painter->moveTo(m_xs.at(0), m_ys.at(0));
  for (auto i = 1; i < dataSize; ++i) {
    if (m_drawStepped) {
      painter->lineTo(m_xs.at(i), m_ys.at(i - 1));
    }
    painter->lineTo(m_xs.at(i), m_ys.at(i));
  }
  painter->stroke();

  // draw symbols
  if (m_drawSymbols) {
    // we force a solid color so that the line under the symbol
    // is hidden
    if (pen.fill.isValid()) {
      auto symbolColor = pen.fill;
      symbolColor.setAlphaF(1.0);
      painter->setFillStyle(QNanoColor::fromQColor(symbolColor));
    }
    auto ids = m_mappedXs.keys();
    for (auto id : ids) {
      painter->beginPath();
      painter->circle(m_mappedXs.value(id), m_mappedYs.value(id),
                      pen.width * 2.5);
      painter->fill();
      painter->stroke();
    }
  }
}
