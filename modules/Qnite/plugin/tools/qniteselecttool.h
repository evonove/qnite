#ifndef QNITE_SELECT_TOOL_H
#define QNITE_SELECT_TOOL_H

#include "qnitetool.h"

class QniteSelectTool: public QniteTool
{
  Q_OBJECT
  Q_PROPERTY(QVariantList selection READ selection NOTIFY selectionChanged)

public:
  explicit QniteSelectTool(QQuickItem* parent = 0);
  virtual ~QniteSelectTool() {}

  QVariantList selection() const;

  virtual void begin(const QPoint &point);
  virtual void append(const QPoint &point);
  virtual void end();

Q_SIGNALS:
  void selectionChanged();

protected:
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);

  QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

  QList<QPoint> m_selection;
};

#endif // QNITE_SELECT_TOOL_H
