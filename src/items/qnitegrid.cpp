#include <QLoggingCategory>

#include "qnitegrid.h"
#include "qnitegridpainter.h"


Q_LOGGING_CATEGORY(qnitegrid, "qnite.grid")


QniteGrid::QniteGrid(QQuickItem* parent)
    : QniteArtist{parent}
    , m_drawXAxes{false}
    , m_drawYAxes{false}
{
    // we set a nicer default for a background grid
    pen()->setWidth(1);
    pen()->setStroke("#bdbdbd");
}

QNanoQuickItemPainter* QniteGrid::createItemPainter() const
{
    return new QniteGridPainter;
}

void QniteGrid::setDrawXAxes(bool value)
{
    m_drawXAxes = value;
    emit drawXAxesChanged();
}

void QniteGrid::setDrawYAxes(bool value)
{
    m_drawYAxes = value;
    emit drawYAxesChanged();
}
