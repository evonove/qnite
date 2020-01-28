#ifndef QNITE_CIRCLE_H
#define QNITE_CIRCLE_H

#include "qnitexyartist.h"

class QniteCircle : public QniteXYArtist {
  Q_OBJECT
  Q_PROPERTY(QList<int> selectedIndexes READ selectedIndexes)
  Q_PROPERTY(int highlightedIndex READ highlightedIndex)

public:
  explicit QniteCircle(QQuickItem *parent = nullptr);
  virtual ~QniteCircle() Q_DECL_OVERRIDE;

  QList<int> selectedIndexes() const { return m_selectedIndexes.values(); }
  int highlightedIndex() const { return m_highlightedIndex; }

  QList<int> selectedIds() const { return m_selectedIds.values(); }
  int highlightedId() const { return m_highlightedId; }

  bool select(const QList<QPoint> &) Q_DECL_OVERRIDE;
  bool select(const QPoint) Q_DECL_OVERRIDE;
  Q_INVOKABLE void clearSelection() Q_DECL_OVERRIDE;

  Q_INVOKABLE void select(QList<int> indexes);
  Q_INVOKABLE void highlight(int index);

  QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE;

private:
  QSet<int> m_selectedIds; //! here we store the ids of selected points
  int m_highlightedId;

  QSet<int> m_selectedIndexes;
  int m_highlightedIndex;
};

#endif // QNITE_CIRCLE_H
