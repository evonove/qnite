#ifndef QNITECIRCLEPAINTER_H
#define QNITECIRCLEPAINTER_H


#include "qnanoquickitempainter.h"
#include "qnitepen.h"


class QniteCirclePainter : public QNanoQuickItemPainter
{
public:
    QniteCirclePainter();

    void synchronize(QNanoQuickItem* item) Q_DECL_OVERRIDE;
    void paint(QNanoPainter* painter) Q_DECL_OVERRIDE;

private:
    // base artist data
    bool m_selected;
    QnitePen::PenData m_pen;
    QnitePen::PenData m_selectedPen;
    QnitePen::PenData m_highlightedPen;

    // xy artist data
    QList<qreal> m_xs;
    QList<qreal> m_ys;

    // circle data
    qreal m_radius;
    QList<int> m_selectedPoints;
    int m_highlightedPoint;
};

#endif /* QNITECIRCLEPAINTER_H */
