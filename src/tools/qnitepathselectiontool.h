#ifndef QNITE_SELECT_TOOL_H
#define QNITE_SELECT_TOOL_H


#include "qniteselectiontool.h"


class QnitePen;
class QniteArtist;
class QnitePathSelectionTool: public QniteSelectionTool
{
  Q_OBJECT
  Q_PROPERTY(QVariantList selectionPath READ selectionPath NOTIFY selectionPathChanged)
  Q_PROPERTY(QnitePen* pen READ pen CONSTANT)

public:
  explicit QnitePathSelectionTool(QQuickItem* parent = 0);
  virtual ~QnitePathSelectionTool() {}

  QVariantList selectionPath() const;

  QnitePen* pen() const { return m_pen; }

  virtual void begin(const QPoint &point);
  virtual void append(const QPoint &point);
  virtual void end();

  QNanoQuickItemPainter* createItemPainter() const Q_DECL_OVERRIDE;

Q_SIGNALS:
  void selectionPathChanged();

protected:
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);
  virtual bool doSelect(QniteArtist*);

//  QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

  QList<QPoint> m_selection;

private:
  friend class QnitePathPainter;

  QnitePen* m_pen;

};

#endif // QNITE_SELECT_TOOL_H
