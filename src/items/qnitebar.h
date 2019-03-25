#ifndef QNITE_BAR_H
#define QNITE_BAR_H

#include "qnitexyartist.h"
#include <QColor>

class QniteBar : public QniteXYArtist {
  Q_OBJECT
  Q_PROPERTY(qreal fixedWidth READ fixedWidth WRITE setFixedWidth NOTIFY
                 fixedWidthChanged)
  Q_PROPERTY(int selectedIndex READ selectedIndex)
  Q_PROPERTY(QStringList categories READ categories WRITE setCategories NOTIFY
                 categoriesChanged)

public:
  explicit QniteBar(QQuickItem *parent = 0);
  virtual ~QniteBar() {}

  qreal fixedWidth() const { return m_fixedWidth; }
  void setFixedWidth(qreal w);

  const QStringList &categories() const { return m_categories; }
  void setCategories(const QStringList &c);

  bool select(const QPoint) Q_DECL_OVERRIDE;
  bool select(const QList<QPoint> &) Q_DECL_OVERRIDE;
  void clearSelection() Q_DECL_OVERRIDE;

  int selectedIndex() const { return m_selectedIndex; }

  QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE;

Q_SIGNALS:
  void fixedWidthChanged();
  void categoriesChanged();

protected:
  virtual bool isSelected() const Q_DECL_OVERRIDE;

private:
  qreal m_fixedWidth;
  int m_selectedIndex;

  QStringList m_categories;
};

#endif // QNITE_BAR_H
