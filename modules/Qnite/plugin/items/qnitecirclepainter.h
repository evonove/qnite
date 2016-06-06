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
    // xy artist data
    QList<qreal> m_xs;
    QList<qreal> m_ys;
    QnitePen::PenData m_pen;
    QColor m_selectionColor;

    // circle data
    qreal m_radius;
    QList<int> m_selectedPoints;
};

#endif /* QNITECIRCLEPAINTER_H */
