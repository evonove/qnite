#ifndef QNITE_BAR_H
#define QNITE_BAR_H

#include "qnitexyartist.h"
#include <QColor>

class QniteBar : public QniteXYArtist
{
  Q_OBJECT
  Q_PROPERTY(int selectedIndex READ selectedIndex)

public:
  explicit QniteBar(QQuickItem *parent = 0);
  virtual ~QniteBar();

  bool select(QPoint);
  bool select(const QList<QPoint>&);
  void clearSelection();

  int selectedIndex() const { return m_selectedIndex; }

protected:
  virtual bool isSelected() const;

  QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);
  void updateBars(QSGNode* node);

private:
  QSGNode* m_barsNode;

  int m_selectedIndex;
};


#endif // QNITE_BAR_H

