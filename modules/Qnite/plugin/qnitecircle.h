#ifndef QNITE_CIRCLE_H
#define QNITE_CIRCLE_H

#include "qnitexyartist.h"

class QniteCircle : public QniteXYArtist
{
    Q_OBJECT
    Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
public:
    explicit QniteCircle(QQuickItem *parent = 0);
    virtual ~QniteCircle();

    qreal radius() const;
    void setRadius(qreal radius);

    bool select(const QList<QPoint>&);
    bool select(const QPoint);
    void clearSelection();

Q_SIGNALS:
    void radiusChanged();

protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);

private:
    qreal m_radius;

    QVector<int> m_selectedPoints; //! here we store the indexes of selected points
};


#endif // QNITE_CIRCLE_H

