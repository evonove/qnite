#pragma once

#include "qnanoquickitempainter.h"
#include "qnitepen.h"

class QniteZoomPainter : public QNanoQuickItemPainter {
public:
  QniteZoomPainter();

  void synchronize(QNanoQuickItem *item) Q_DECL_OVERRIDE;
  void paint(QNanoPainter *painter) Q_DECL_OVERRIDE;

private:
  QRectF m_rect;
  QnitePen::PenData m_pen;
};
