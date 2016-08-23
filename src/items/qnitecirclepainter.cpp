#include <QLoggingCategory>

#include "qnitecirclepainter.h"
#include "qnitecircle.h"


Q_LOGGING_CATEGORY(qnitecirclepainter, "qnite.circle.painter")


QniteCirclePainter::QniteCirclePainter()
    : QNanoQuickItemPainter{}
{
}

void QniteCirclePainter::synchronize(QNanoQuickItem* item)
{
    qCDebug(qnitecirclepainter) << "synchronizing qnitecircle";

    auto circleItem = static_cast<QniteCircle*>(item);
    if (circleItem != Q_NULLPTR) {
        circleItem->processData();

        // TODO: here we could share painting data using a class
        // which is copied with all its members in a local instance.
        m_xs = circleItem->xProcessed();
        m_ys = circleItem->yProcessed();

        // make a local copy of the pen
        m_pen = circleItem->pen()->data();
        m_selectedPen = circleItem->selectedPen()->data();
        m_highlightedPen = circleItem->highlightedPen()->data();
        m_selected = circleItem->selected();

        // circle specific properties
        m_selectedPoints = circleItem->selectedIndexes();
        m_highlightedPoint = circleItem->highlightedIndex();
    }
}

void QniteCirclePainter::paint(QNanoPainter* painter)
{
    qCDebug(qnitecirclepainter) << "painting qnitecircle";

    auto dataSize = m_xs.size();
    if (dataSize < 1)
        return;

    painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
    painter->setLineWidth(m_pen.width);
    painter->setLineJoin(m_pen.join);
    painter->setLineCap(m_pen.cap);

    // draw unselected points
    for(auto i = 0; i < dataSize; ++i) {
        // we do not draw selected or highlighted indexes because we draw them later
        if (m_selectedPoints.contains(i) || m_highlightedPoint == i) {
            continue;
        }
        painter->beginPath();
        painter->circle(m_xs.at(i), m_ys.at(i), m_pen.radius);
        painter->fill();
        painter->stroke();
    }

    // draw selected points
    if (m_selectedPoints.size() > 0) {
        painter->setStrokeStyle(QNanoColor::fromQColor(m_selectedPen.stroke));
        painter->setFillStyle(QNanoColor::fromQColor(m_selectedPen.fill));
        painter->setLineWidth(m_selectedPen.width);
        painter->setLineJoin(m_selectedPen.join);
        painter->setLineCap(m_selectedPen.cap);

        for(auto i : m_selectedPoints) {
            // we don't draw highlighted indexes here
            if (i == m_highlightedPoint) {
                continue;
            }

            painter->beginPath();
            painter->circle(m_xs.at(i), m_ys.at(i), m_selectedPen.radius);
            painter->fill();
            painter->stroke();
        }
    }

    // draw highlighted points
    if (m_highlightedPoint > -1) {
        painter->setStrokeStyle(QNanoColor::fromQColor(m_highlightedPen.stroke));
        painter->setFillStyle(QNanoColor::fromQColor(m_highlightedPen.fill));
        painter->setLineWidth(m_highlightedPen.width);
        painter->setLineJoin(m_highlightedPen.join);
        painter->setLineCap(m_highlightedPen.cap);

        painter->beginPath();
        painter->circle(m_xs.at(m_highlightedPoint), m_ys.at(m_highlightedPoint), m_highlightedPen.radius);
        painter->fill();
        painter->stroke();
    }
}
