#ifndef QNITELINEPAINTER_H
#define QNITELINEPAINTER_H


#include "qnanoquickitempainter.h"
#include "qnitepen.h"


class QniteLinePainter : public QNanoQuickItemPainter
{
public:
    QniteLinePainter();

    void synchronize(QNanoQuickItem* item) Q_DECL_OVERRIDE;
    void paint(QNanoPainter* painter) Q_DECL_OVERRIDE;

private:
    void drawCircles();

    // xy artist data
    QList<qreal> m_xs;
    QList<qreal> m_ys;
    QColor m_selectionColor;
    QnitePen::PenData m_pen;

    qreal m_baseline;
};

#endif /* QNITELINEPAINTER_H */
