#include <QLoggingCategory>

#include "qnitegrid.h"
#include "qnitegridpainter.h"


Q_LOGGING_CATEGORY(qnitegrid, "qnite.grid")


QniteGrid::QniteGrid(QQuickItem* parent)
    : QniteArtist{parent}
{
    // we set a nicer default for a background grid
    pen()->setWidth(1);
    pen()->setStroke("#bdbdbd");
}

QNanoQuickItemPainter* QniteGrid::createItemPainter() const
{
    return new QniteGridPainter;
}
