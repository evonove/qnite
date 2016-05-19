#ifndef QNITE_CIRCLE_H
#define QNITE_CIRCLE_H

#include "qnitexyartist.h"

class QniteCircle : public QniteXYArtist
{
    Q_OBJECT
    Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(QList<int> selectedIndexes READ selectedIndexes)

public:
    explicit QniteCircle(QQuickItem *parent = 0);
    virtual ~QniteCircle();

    qreal radius() const;
    void setRadius(qreal radius);

    QList<int> selectedIndexes() const { return m_selectedPoints.toList(); }

    bool select(const QList<QPoint>&) Q_DECL_OVERRIDE;
    bool select(const QPoint) Q_DECL_OVERRIDE;
    void clearSelection() Q_DECL_OVERRIDE;

    Q_INVOKABLE void select(QList<int> indexes);

Q_SIGNALS:
    void radiusChanged();

protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*) Q_DECL_OVERRIDE;

private:
    qreal m_radius;

    QSet<int> m_selectedPoints; //! here we store the indexes of selected points
};


#endif // QNITE_CIRCLE_H

