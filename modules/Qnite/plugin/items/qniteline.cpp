#include "qniteline.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitelinepainter.h"

#include <QLoggingCategory>
#include <QSGNode>


Q_LOGGING_CATEGORY(qniteline, "qnite.line")


constexpr auto SELECTION_TOLERANCE = 50;


QniteLine::QniteLine(QQuickItem *parent)
    : QniteXYArtist(parent)
    , m_selected{false}
{
}

QniteLine::~QniteLine()
{
}

//QSGNode* QniteLine::updatePaintNode(QSGNode* node, UpdatePaintNodeData* upnd)
//{
    //qCDebug(qniteline) << "update paint node";
    //// to draw a line we should have at least two points
    //if (xValues().size() < 2)
        //return nullptr;

    //// TODO: processdata should be triggered only when data changes
    //// so we can avoid the unecessary updateGeometry
    //processData();

    //return QNanoQuickItem::updatePaintNode(node, upnd);
//}

    //if (!node) {
        //node = new QSGNode;

        //m_circlesNode = new QSGNode;
        //node->appendChildNode(m_circlesNode);

        //m_lineNode = new QniteLineNode(m_lineWidth, color());
        //node->appendChildNode(m_lineNode);

        //if (m_fill) {
            //m_fillNode = new QniteFillNode(QColor(m_fillColor));
            //node->prependChildNode(m_fillNode);
        //} else {
            //m_fillNode = nullptr;
        //}
    //}

    //// add the fill node when required
    //if (m_fill) {
        //qreal ya = axes()->axisY()->position();
        //m_fillNode->updateGeometry(xProcessed(), yProcessed(), ya);
    //}

    //updateCircles(node);
    //m_lineNode->updateGeometry(xProcessed(), yProcessed());

    //// TODO: update material should only be called when color changes
    //// e.g. when selection occurs. At the moment the guard is inside the updateMaterial
    //// method
    //m_lineNode->updateMaterial(isSelected() ? selectionColor() : color());

    //return node;
//}

//void QniteLine::updateCircles(QSGNode*)
//{
    //int dataSize = xMapped().size();
    //if (dataSize < 1)
        //return;

    //// get the circle size from the lineWidth to ensure it depends
    //// on device pixel density
    //auto circleSize = lineWidth() * 1.5;

    //m_circlesNode->removeAllChildNodes();
    //for(int i = 0; i < dataSize; ++i) {
        //qreal cx = xMapped().at(i);
        //qreal cy = yMapped().at(i);

        //// TODO: optimal number of segments should be  computed runtime
        //QColor c = isSelected() ? selectionColor() : color();
        //m_circlesNode->appendChildNode(new QniteCircleNode(cx, cy, circleSize, 32, c));
    //}
//}

/*!
  Temporary implementation of the selection logic for lines.

TODO: fix the implementation
TODO: can we assume data is alwayws already mapped at this point?
*/
bool QniteLine::select(QPoint p)
{
    bool accepted = false;

    // get the distance from the first point on the path
    int dataSize = xMapped().size();
    for(int i = 0; i < dataSize; ++i) {
        QPoint cp(xMapped().at(i), yMapped().at(i));
        QPoint d = p - cp;
        if (d.manhattanLength() < SELECTION_TOLERANCE) {
            m_selected = true;
            accepted = true;
            axes()->setOnTop(this);
            emit selectedChanged();
            update();
            break;
        }
    }

    return accepted;
}

bool QniteLine::select(const QList<QPoint>& path)
{
    if (path.size()) {
        return select(path.first());
    }

    return false;
}

void QniteLine::clearSelection()
{
    m_selected = false;
    emit selectedChanged();
    update();
}


QNanoQuickItemPainter* QniteLine::createItemPainter() const
{
    qCDebug(qniteline) << "creating item painter";
    return new QniteLinePainter();
}
