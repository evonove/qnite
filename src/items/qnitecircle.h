#ifndef QNITE_CIRCLE_H
#define QNITE_CIRCLE_H

#include "qnitexyartist.h"

class QniteCircle : public QniteXYArtist
{
    Q_OBJECT
    Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(qreal selectedRadius READ selectedRadius WRITE setSelectedRadius NOTIFY selectedRadiusChanged)
    Q_PROPERTY(qreal highlightedRadius READ highlightedRadius WRITE setHighlightedRadius NOTIFY highlightedRadiusChanged)
    Q_PROPERTY(QList<int> selectedIndexes READ selectedIndexes)
    Q_PROPERTY(int highlightedIndex READ highlightedIndex)

public:
    explicit QniteCircle(QQuickItem *parent = 0);
    virtual ~QniteCircle();

    qreal radius() const;
    qreal selectedRadius() const;
    qreal highlightedRadius() const;
    void setRadius(qreal radius);
    void setSelectedRadius(qreal radius);
    void setHighlightedRadius(qreal radius);

    QList<int> selectedIndexes() const { return m_selectedPoints.toList(); }
    int highlightedIndex() const { return m_highlightedPoint; }

    bool select(const QList<QPoint>&) Q_DECL_OVERRIDE;
    bool select(const QPoint) Q_DECL_OVERRIDE;
    Q_INVOKABLE void clearSelection() Q_DECL_OVERRIDE;

    Q_INVOKABLE void select(QList<int> indexes);
    Q_INVOKABLE void highlight(int index);

    QNanoQuickItemPainter* createItemPainter() const Q_DECL_OVERRIDE;

Q_SIGNALS:
    void radiusChanged();
    void selectedRadiusChanged();
    void highlightedRadiusChanged();

private:
    qreal m_radius;
    qreal m_selectedRadius;
    qreal m_highlightedRadius;

    QSet<int> m_selectedPoints; //! here we store the indexes of selected points
    int m_highlightedPoint;
};


#endif // QNITE_CIRCLE_H

