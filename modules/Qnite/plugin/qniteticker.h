#ifndef QNITETICKER_H
#define QNITETICKER_H

#include <QObject>
#include <QVariant>


class QniteTicker : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QniteTicker)

    Q_PROPERTY(QVariantList values READ values WRITE setValues NOTIFY valuesChanged)
    Q_PROPERTY(QVariantList minorTicks READ minorTicks WRITE setMinorTicks)
    Q_PROPERTY(QVariantList midTicks READ midTicks WRITE setMidTicks)
    Q_PROPERTY(QVariantList majorTicks READ majorTicks WRITE setMajorTicks)

signals:
    void valuesChanged();

public:
    explicit QniteTicker(QObject * parent=0);
    virtual ~QniteTicker() {}

    void setValues(QVariantList&);
    void setBoundaries(float lower, float upper);
    void setMinorTicks(QVariantList&);
    void setMidTicks(QVariantList&);
    void setMajorTicks(QVariantList&);

    QVariantList values() const;
    QVariantList minorTicks() const;
    QVariantList midTicks() const;
    QVariantList majorTicks() const;

    float lower() const { return lowerBound_; }
    float upper() const { return upperBound_; }

protected:
    virtual void buildTicks() = 0;

    QList<float> minorTicks_;
    QList<float> midTicks_;
    QList<float> majorTicks_;
    QList<float> values_;

    float lowerBound_;
    float upperBound_;
};

#endif // QNITETICKER_H

