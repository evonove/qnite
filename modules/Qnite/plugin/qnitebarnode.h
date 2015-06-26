#ifndef QNITE_BAR_NODE_H
#define QNITE_BAR_NODE_H

#include <QColor>

#include <QSGGeometryNode>
#include <QSGGeometry>

class QniteBarNode: public QSGGeometryNode
{
public:
  QniteBarNode(qreal x, qreal y, qreal baseline, qreal size, const QColor& color);
};

#endif // QNITE_BAR_NODE_H
