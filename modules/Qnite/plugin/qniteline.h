#ifndef QNITE_LINE_H
#define QNITE_LINE_H

#include "qnitexyartist.h"

#include <QColor>

class QniteLineNode;
class QniteFillNode;
class QniteLine : public QniteXYArtist
{
    Q_OBJECT
    Q_PROPERTY(bool fill READ fill WRITE setFill NOTIFY fillChanged)
    Q_PROPERTY(QColor fillColor READ fillColor WRITE setFillColor NOTIFY fillColorChanged)
    Q_PROPERTY(qreal lineWidth READ lineWidth WRITE setLineWidth NOTIFY lineWidthChanged)

public:
    explicit QniteLine(QQuickItem *parent = 0);
    virtual ~QniteLine();

    bool fill() const { return m_fill; }
    void setFill(bool fill);
    QColor fillColor() const { return m_fillColor; }
    void setFillColor(QColor fillColor);

    qreal lineWidth() const { return m_lineWidth; }
    void setLineWidth(qreal lineWidth);

    bool select(const QList<QPoint>&) Q_DECL_OVERRIDE;
    bool select(const QPoint) Q_DECL_OVERRIDE;
    void clearSelection() Q_DECL_OVERRIDE;

Q_SIGNALS:
    void fillChanged();
    void fillColorChanged();
    void lineWidthChanged();

protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*) Q_DECL_OVERRIDE;
    void updateCircles(QSGNode* node);
    virtual bool isSelected() const Q_DECL_OVERRIDE { return m_selected; }

private:
    QniteLineNode* m_lineNode;
    QniteFillNode* m_fillNode;
    QSGNode* m_circlesNode;

    QColor m_fillColor;
    bool m_fill;
    bool m_selected;
    qreal m_lineWidth;
};


#endif // QNITE_LINE_H

