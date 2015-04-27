#ifndef QNITE_CIRCLE_NODE_H
#define QNITE_CIRCLE_NODE_H

#include <QSGGeometryNode>

class QniteCircleNode: public QSGGeometryNode
{
  public:
    QniteCircleNode(qreal cx, qreal cy, qreal radius, qreal segments, QColor color);
};

#endif // QNITE_CIRCLE_NODE_H
