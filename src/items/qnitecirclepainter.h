#ifndef QNITECIRCLEPAINTER_H
#define QNITECIRCLEPAINTER_H

#include "qnanoquickitempainter.h"
#include "qnitepen.h"

class QniteCirclePainter : public QNanoQuickItemPainter {
public:
  QniteCirclePainter();

  void synchronize(QNanoQuickItem *item) Q_DECL_OVERRIDE;
  void paint(QNanoPainter *painter) Q_DECL_OVERRIDE;

private:
  // base artist data
  bool m_selected;
  QnitePen::PenData m_pen;
  QnitePen::PenData m_selectedPen;
  QnitePen::PenData m_highlightedPen;

  // xy artist data
  QMap<int, qreal> m_xs;
  QMap<int, qreal> m_ys;

  // circle data
  qreal m_radius;
  qreal m_selectedRadius;
  qreal m_highlightedRadius;
  QList<int> m_selectedIds;
  int m_highlightedId;
};

#endif /* QNITECIRCLEPAINTER_H */
