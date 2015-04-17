#ifndef QNITE_SCALE_MAP_H
#define QNITE_SCALE_MAP_H

#include <QObject>

class QniteScaleMap : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QniteScaleMap)

    Q_PROPERTY(qreal min READ min WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(qreal max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(qreal size READ size WRITE setSize NOTIFY sizeChanged)

  public:
    explicit QniteScaleMap(QObject *parent = 0);
    virtual ~QniteScaleMap();

    qreal min() const;
    void setMin(qreal min);

    qreal max() const;
    void setMax(qreal max);

    qreal size() const;
    void setSize(qreal size);

    Q_INVOKABLE qreal transform(qreal value);

  signals:
    void minChanged();
    void maxChanged();
    void sizeChanged();

  private:
    qreal m_min;
    qreal m_max;

    qreal m_size;
};

#endif // QNITE_SCALE_MAP_H

