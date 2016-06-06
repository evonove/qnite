#ifndef QNITEGRIDPAINTER_H
#define QNITEGRIDPAINTER_H


#include "qnanoquickitempainter.h"
#include "qnitepen.h"


class QniteGridPainter : public QNanoQuickItemPainter
{
public:
    QniteGridPainter();

    void synchronize(QNanoQuickItem* item) Q_DECL_OVERRIDE;
    void paint(QNanoPainter* painter) Q_DECL_OVERRIDE;

private:
    QList<qreal> m_xs;
    QList<qreal> m_ys;

    QnitePen::PenData m_pen;
    qreal m_xsize;
    qreal m_ysize;
};

#endif // QNITEGRIDPAINTER_H
