#include <QLoggingCategory>

#include "qnitelinepainter.h"
#include "qniteline.h"

#include "qniteaxes.h"
#include "qniteaxis.h"


Q_LOGGING_CATEGORY(qnitelinepainter, "qnite.line.painter")


QniteLinePainter::QniteLinePainter()
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
        m_selectionColor = lineItem->selectionColor();

        // make a local copy of the pen data (stroke, fill)
        m_pen = lineItem->pen()->data();

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

    painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
    painter->setLineWidth(m_pen.width);
    painter->setLineJoin(m_pen.join);
    painter->setLineCap(m_pen.cap);

    painter->beginPath();
    painter->moveTo(m_xs.at(0), m_ys.at(0));
    for(auto i = 1; i < dataSize; ++i) {
        painter->lineTo(m_xs.at(i), m_ys.at(i));
    }
    painter->stroke();

    // draw the fill when we have a valid color
    if (m_pen.fill.isValid()) {
        painter->beginPath();
        painter->moveTo(m_xs.at(0), m_baseline);
        for(auto i = 0; i < dataSize; ++i) {
            painter->lineTo(m_xs.at(i), m_ys.at(i));
        }
        painter->lineTo(m_xs.at(dataSize - 1), m_baseline);
        painter->fill();
    }
}
