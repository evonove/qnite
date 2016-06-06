#ifndef QNITE_ARTIST_H
#define QNITE_ARTIST_H


#include "qnitepen.h"
#include "qnanoquickitem.h"


class QniteAxes;
class QniteArtist: public QNanoQuickItem
{
  Q_OBJECT
  Q_PROPERTY(QniteAxes* axes READ axes NOTIFY axesChanged)
  Q_PROPERTY(bool selectable READ selectable WRITE setSelectable NOTIFY selectableChanged)
  Q_PROPERTY(bool selected READ selected NOTIFY selectedChanged)
  Q_PROPERTY(bool propagateSelection READ propagateSelection WRITE setPropagateSelection NOTIFY propagateSelectionChanged)
  Q_PROPERTY(QnitePen* pen READ pen CONSTANT)
  Q_PROPERTY(QnitePen* selectedPen READ selectedPen CONSTANT)

public:
  explicit QniteArtist(QQuickItem* parent = Q_NULLPTR);
  virtual ~QniteArtist();

  QniteAxes* axes() const;
  bool selectable() const { return m_selectable; }
  bool selected() const;
  virtual bool select(const QPoint);
  virtual bool select(const QList<QPoint>&);
  bool propagateSelection() const { return m_propagate_selection; }

  void setAxes(QniteAxes* axes);
  void setSelectable(bool selectable);
  virtual void clearSelection() {}
  void setPropagateSelection(bool);

  QnitePen* pen() const { return m_pen; }
  QnitePen* selectedPen() const { return m_selectedPen; }

  QNanoQuickItemPainter* createItemPainter() const Q_DECL_OVERRIDE { return nullptr; }

public Q_SLOTS:
  virtual void processData() = 0;

Q_SIGNALS:
  void axesChanged();
  void selectableChanged();
  void selectedChanged();
  void propagateSelectionChanged();

protected:
  virtual void updateAxes();
  virtual bool isSelected() const { return false; }

private:
  QniteAxes* m_axes;
  bool m_selectable;
  bool m_propagate_selection;
  QnitePen* m_pen;
  QnitePen* m_selectedPen;
};

#endif // QNITE_ARTIST_H

