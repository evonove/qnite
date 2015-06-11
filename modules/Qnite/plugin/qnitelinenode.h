#ifndef QNITE_LINE_NODE_H
#define QNITE_LINE_NODE_H

#include <QSGGeometryNode>

class QniteLineNode: public QSGGeometryNode
{
public:
  QniteLineNode(float size, const QColor &color);

  void updateGeometry(const QList<qreal>& xs, const QList<qreal>& ys);

private:
  QSGGeometry m_geometry;
};

#endif // QNITE_LINE_NODE_H
