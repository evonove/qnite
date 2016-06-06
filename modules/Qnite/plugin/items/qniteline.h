#ifndef QNITE_LINE_H
#define QNITE_LINE_H

#include "qnitexyartist.h"

#include <QColor>

class QniteLine : public QniteXYArtist
{
    Q_OBJECT

public:
    explicit QniteLine(QQuickItem *parent = 0);
    virtual ~QniteLine();

    bool select(const QList<QPoint>&) Q_DECL_OVERRIDE;
    bool select(const QPoint) Q_DECL_OVERRIDE;
    void clearSelection() Q_DECL_OVERRIDE;

    QNanoQuickItemPainter* createItemPainter() const Q_DECL_OVERRIDE;

protected:
    virtual bool isSelected() const Q_DECL_OVERRIDE { return m_selected; }

private:
    bool m_selected;
};


#endif // QNITE_LINE_H

