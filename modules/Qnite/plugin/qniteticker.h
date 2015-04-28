#ifndef QNITETICKER_H
#define QNITETICKER_H

#include <QObject>

class QniteTicker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<qreal> values READ values WRITE setValues NOTIFY valuesChanged)
    Q_PROPERTY(QList<qreal> minorTicks READ minorTicks WRITE setMinorTicks)
    Q_PROPERTY(QList<qreal> midTicks READ midTicks WRITE setMidTicks)
    Q_PROPERTY(QList<qreal> majorTicks READ majorTicks WRITE setMajorTicks NOTIFY majorTicksChanged)
    Q_PROPERTY(int numSteps READ numSteps WRITE setNumSteps)

Q_SIGNALS:
    void valuesChanged();
    void minorTicksChanged();
    void midTicksChanged();
    void majorTicksChanged();
    void numStepsChanged();

public:
    explicit QniteTicker(QObject * parent=0);
    virtual ~QniteTicker() {}

    virtual void reset();
    virtual void setValues(const QList<qreal>&);
    void setBoundaries(qreal lower, qreal upper);
    void setMinorTicks(const QList<qreal>&);
    void setMidTicks(const QList<qreal>&);
    void setMajorTicks(const QList<qreal>&);
    void setNumSteps(int);

    virtual QList<qreal> values() const;
    QList<qreal> minorTicks() const;
    QList<qreal> midTicks() const;
    QList<qreal> majorTicks() const;
    qreal lower() const { return m_lowerBound; }
    qreal upper() const { return m_upperBound; }
    int numSteps() const { return m_numSteps; }

protected:
    virtual void buildTicks() = 0;

    QList<qreal> m_minorTicks;
    QList<qreal> m_midTicks;
    QList<qreal> m_majorTicks;
    QList<qreal> m_values;

    qreal m_lowerBound;
    qreal m_upperBound;

    int m_numSteps;
};

#endif // QNITETICKER_H

