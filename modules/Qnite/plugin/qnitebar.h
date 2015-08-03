#ifndef QNITE_BAR_H
#define QNITE_BAR_H

#include "qnitexyartist.h"
#include <QColor>

class QniteBar : public QniteXYArtist
{
  Q_OBJECT
  Q_PROPERTY(int selectedIndex READ selectedIndex)
  Q_PROPERTY(QStringList categories READ categories WRITE setCategories NOTIFY categoriesChanged)

public:
  explicit QniteBar(QQuickItem *parent = 0);
  virtual ~QniteBar() {}

  const QStringList& categories() const { return m_categories; }
  void setCategories(const QStringList& c);

  bool select(QPoint);
  bool select(const QList<QPoint>&);
  void clearSelection();

  int selectedIndex() const { return m_selectedIndex; }

Q_SIGNALS:
  void categoriesChanged();

protected:
  virtual bool isSelected() const;

  QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);
  void updateBars();

private:
  QSGNode* m_barsNode;

  int m_selectedIndex;

  QStringList m_categories;
};


#endif // QNITE_BAR_H

