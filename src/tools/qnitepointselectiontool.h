#ifndef QNITEPOINTSELECTIONTOOL_H
#define QNITEPOINTSELECTIONTOOL_H

#include "qniteselectiontool.h"

class QnitePointSelectionTool : public QniteSelectionTool {
  Q_OBJECT

public:
  explicit QnitePointSelectionTool(QQuickItem *parent = 0);
  virtual ~QnitePointSelectionTool() {}

  void select(const QPoint &point);

protected:
  using QniteSelectionTool::select;

  virtual bool doSelect(QniteArtist *);
  virtual void mousePressEvent(QMouseEvent *) {}
  virtual void mouseReleaseEvent(QMouseEvent *event);

private:
  QPoint m_selection;
};

#endif // QNITEPOINTSELECTIONTOOL_H
