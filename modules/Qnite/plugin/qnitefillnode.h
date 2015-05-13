#ifndef QNITE_FILL_NODE_H
#define QNITE_FILL_NODE_H

#include <QColor>

#include <QSGGeometryNode>
#include <QSGGeometry>

class QniteFillNode: public QSGGeometryNode
{
  public:
    QniteFillNode(QColor color);

    void updateGeometry(const QList<qreal>& xs, const QList<qreal>& ys, qreal yBaseline);

  private:
    QSGGeometry m_geometry;
};

#endif // QNITE_FILL_NODE_H
