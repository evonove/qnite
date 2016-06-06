#include <QLoggingCategory>

#include "qnitecirclepainter.h"
#include "qnitecircle.h"

Q_LOGGING_CATEGORY(qnitecirclepainter, "qnite.circle.painter")

QniteCirclePainter::QniteCirclePainter()
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
        m_selectionColor = circleItem->selectionColor();

        // circle specific properties
        m_radius = circleItem->radius();
        m_selectedPoints = circleItem->selectedIndexes();

        // make a local copy of the pen
        m_pen = circleItem->pen()->data();
    }
}

void QniteCirclePainter::paint(QNanoPainter* painter)
{
    qCDebug(qnitecirclepainter) << "painting qnitecircle";

    auto dataSize = m_xs.size();
    if (dataSize < 2)
        return;

    painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
    painter->setLineWidth(m_pen.width);
    painter->setLineJoin(m_pen.join);
    painter->setLineCap(m_pen.cap);

    // draw circles
    for(auto i = 1; i < dataSize; ++i) {
        painter->beginPath();
        painter->circle(m_xs.at(i), m_ys.at(i), m_radius);
        painter->stroke();
        painter->fill();
    }
}
