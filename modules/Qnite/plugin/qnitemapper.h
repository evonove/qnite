#ifndef QNITE_MAPPER_H
#define QNITE_MAPPER_H

#include <QObject>

class QniteMapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal min READ min WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(qreal max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(qreal size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(bool flip READ flip WRITE setFlip NOTIFY flipChanged)
    Q_PROPERTY(qreal factor READ factor NOTIFY factorChanged)

  public:
    explicit QniteMapper(QObject *parent = 0);
    virtual ~QniteMapper();

    qreal min() const;
    void setMin(qreal min);
    qreal max() const;
    void setMax(qreal max);
    qreal size() const;
    void setSize(qreal size);
    bool flip() const;
    void setFlip(bool flip);

    qreal factor() const;

    Q_INVOKABLE qreal transform(qreal value);

  Q_SIGNALS:
    void minChanged();
    void maxChanged();
    void sizeChanged();
    void flipChanged();
    void factorChanged();

  private:
    qreal m_min;
    qreal m_max;
    qreal m_size;
    bool m_flip;
};

#endif // QNITE_MAPPER_H

