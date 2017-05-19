#include <QLoggingCategory>

#include "qnitegridpainter.h"
#include "qnitegrid.h"

#include "qniteaxes.h"
#include "qniteaxis.h"


Q_LOGGING_CATEGORY(qnitegridpainter, "qnite.grid.painter")


QniteGridPainter::QniteGridPainter()
    : QNanoQuickItemPainter{}
{
}

void QniteGridPainter::synchronize(QNanoQuickItem* item)
{
    qCDebug(qnitegridpainter) << "synchronizing grid";

    auto grid = static_cast<QniteGrid*>(item);
    if (grid != Q_NULLPTR) {
        // make a local copy of the pen
        m_pen = grid->pen()->data();

        // copy the tick values from both axes
        m_xs = grid->axes()->axisX()->majorTicks();
        m_ys = grid->axes()->axisY()->majorTicks();

        m_xsize = grid->axes()->axisX()->size();
        m_ysize = grid->axes()->axisY()->size();

        m_drawX = grid->drawXAxes();
        m_drawY = grid->drawYAxes();
    }
}

void QniteGridPainter::paint(QNanoPainter *painter)
{
    qCDebug(qnitegridpainter) << "painting grid" << m_xs << m_ys;

    painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
    painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
    painter->setLineWidth(m_pen.width);
    painter->setLineJoin(m_pen.join);
    painter->setLineCap(m_pen.cap);

    painter->beginPath();
    if(m_drawX) { //draw x axes
        for(auto y : m_ys) {
            painter->moveTo(0, y);
            painter->lineTo(m_xsize, y);
        }
        painter->stroke();
    }else if(m_drawY) { //draw y axes
        for(auto x : m_xs) {
            painter->moveTo(x, 0);
            painter->lineTo(x, m_ysize);
        }
        painter->stroke();
    }

    for(auto x : m_xs) {
        painter->moveTo(x, 0);
        painter->lineTo(x, m_ysize);
    }
    for(auto y : m_ys) {
        painter->moveTo(0, y);
        painter->lineTo(m_xsize, y);
    }
    painter->stroke();
}
