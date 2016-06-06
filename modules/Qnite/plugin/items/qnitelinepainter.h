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
    // base artist data
    bool m_selected;
    QnitePen::PenData m_pen;
    QnitePen::PenData m_selectedPen;

    // xy artist data
    QList<qreal> m_xs;
    QList<qreal> m_ys;

    // line data
    qreal m_baseline;
};

#endif /* QNITELINEPAINTER_H */
