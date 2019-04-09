#ifndef QNITEBARPAINTER_H
#define QNITEBARPAINTER_H

#include "qnanoquickitempainter.h"
#include "qnitepen.h"

class QniteBarPainter : public QNanoQuickItemPainter {
public:
  QniteBarPainter();

  void synchronize(QNanoQuickItem *item) Q_DECL_OVERRIDE;
  void paint(QNanoPainter *painter) Q_DECL_OVERRIDE;

private:
  void drawBar(qreal x, qreal y);

  // base artist data
  bool m_selected;
  QnitePen::PenData m_pen;
  QnitePen::PenData m_selectedPen;

  // xy artist data
  QMap<int, qreal> m_xs;
  QMap<int, qreal> m_ys;

  // bar data
  qreal m_baseline;
  qreal m_fixedWidth;
  int m_selectedId;
};

#endif /* QNITEBARPAINTER_H */
