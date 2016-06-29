#ifndef QNITEPATHPAINTER_H
#define QNITEPATHPAINTER_H


#include "qnanoquickitempainter.h"
#include "qnitepen.h"


class QnitePathPainter : public QNanoQuickItemPainter
{
public:
    QnitePathPainter();

    void synchronize(QNanoQuickItem* item) Q_DECL_OVERRIDE;
    void paint(QNanoPainter* painter) Q_DECL_OVERRIDE;

private:
    QList<QPoint> m_points;

    QnitePen::PenData m_pen;
};

#endif // QNITEPATHPAINTER_H
