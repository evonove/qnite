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
    Q_PROPERTY(int numSteps READ numSteps WRITE setNumSteps)

signals:
    void valuesChanged();

public:
    explicit QniteTicker(QObject * parent=0);
    virtual ~QniteTicker() {}

    virtual void reset();
    virtual void setValues(QVariantList&);
    void setBoundaries(double lower, double upper);
    void setMinorTicks(QVariantList&);
    void setMidTicks(QVariantList&);
    void setMajorTicks(QVariantList&);
    void setNumSteps(int);

    virtual QVariantList values() const;
    QVariantList minorTicks() const;
    QVariantList midTicks() const;
    QVariantList majorTicks() const;
    double lower() const { return lowerBound_; }
    double upper() const { return upperBound_; }
    int numSteps() const { return numSteps_; }

protected:
    virtual void buildTicks() = 0;

    QList<double> minorTicks_;
    QList<double> midTicks_;
    QList<double> majorTicks_;
    QList<double> values_;

    double lowerBound_;
    double upperBound_;

    int numSteps_;
};

#endif // QNITETICKER_H

