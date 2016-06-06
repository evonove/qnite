#include <QLoggingCategory>

#include "qnitelinepainter.h"
#include "qniteline.h"

#include "qniteaxes.h"
#include "qniteaxis.h"


Q_LOGGING_CATEGORY(qnitelinepainter, "qnite.line.painter")


QniteLinePainter::QniteLinePainter()
    : QNanoQuickItemPainter{}
    , m_selected{false}
{
}

void QniteLinePainter::synchronize(QNanoQuickItem* item)
{
    qCDebug(qnitelinepainter) << "synchronizing qniteline";

    auto lineItem = static_cast<QniteLine*>(item);
    if (lineItem != Q_NULLPTR) {
        lineItem->processData();

        // TODO: here we could share painting data using a class
        // which is copied with all its members in a local instance.
        m_xs = lineItem->xProcessed();
        m_ys = lineItem->yProcessed();

        // make a local copy of the pen data (stroke, fill)
        m_pen = lineItem->pen()->data();
        m_selectedPen = lineItem->selectedPen()->data();
        m_selected = lineItem->selected();

        // the baseline is the position of the y axis
        // this is needed to compute a fill polygon for the line.
        m_baseline = lineItem->axes()->axisY()->position();
    }
}

void QniteLinePainter::paint(QNanoPainter* painter)
{
    qCDebug(qnitelinepainter) << "painting qniteline";

    auto dataSize = m_xs.size();
    if (dataSize < 2)
        return;

    auto& pen = m_selected ? m_selectedPen : m_pen;
    painter->setStrokeStyle(QNanoColor::fromQColor(pen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(pen.fill));
    painter->setLineWidth(pen.width);
    painter->setLineJoin(pen.join);
    painter->setLineCap(pen.cap);

    painter->beginPath();
    painter->moveTo(m_xs.at(0), m_ys.at(0));
    for(auto i = 1; i < dataSize; ++i) {
        painter->lineTo(m_xs.at(i), m_ys.at(i));
    }
    painter->stroke();

    // draw the fill when we have a valid color
    if (pen.fill.isValid()) {
        painter->beginPath();
        painter->moveTo(m_xs.at(0), m_baseline);
        for(auto i = 0; i < dataSize; ++i) {
            painter->lineTo(m_xs.at(i), m_ys.at(i));
        }
        painter->lineTo(m_xs.at(dataSize - 1), m_baseline);
        painter->fill();
    }
}
