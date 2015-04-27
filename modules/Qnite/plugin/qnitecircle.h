#ifndef QNITE_CIRCLE_H
#define QNITE_CIRCLE_H

#include "qniteartist.h"

class QniteCircle : public QniteArtist
{
    Q_OBJECT
    Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
  public:
    explicit QniteCircle(QQuickItem *parent = 0);
    virtual ~QniteCircle();

    qreal radius() const;
    void setRadius(qreal radius);

  Q_SIGNALS:
    void radiusChanged();

  protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);

  private:
    qreal m_radius;
};


#endif // QNITE_CIRCLE_H

