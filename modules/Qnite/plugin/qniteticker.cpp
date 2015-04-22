/*!
    \qmltype Ticker
    \instantiates QniteTicker
    \ingroup scaling
    \inqmlmodule Qnite
    \brief Divide axes scales into tickers

    TODO: add a long description
*/
#include "qniteticker.h"

#define DEFAULT_NUM_STEPS 0
#define DEFAULT_LOWER_B 0
#define DEFAULT_UPPER_B 0

// utility functions
namespace {

    template<typename T>
    QList<T> fromVariantList(const QVariantList& in)
    {
        QList<T> out;
        foreach(QVariant val, in) {
            out.append(val.value<T>());
        }
        return out;
    }

    template<typename T>
    QVariantList toVariantList(const QList<T>& in)
    {
        QVariantList out;
        foreach(T val, in) {
            out.append(QVariant(val));
        }
        return out;
    }

}

QniteTicker::QniteTicker(QObject * parent)
    : QObject(parent), lowerBound_(DEFAULT_LOWER_B),
      upperBound_(DEFAULT_UPPER_B), numSteps_(DEFAULT_NUM_STEPS)
{

}

QVariantList QniteTicker::values() const
{
    return toVariantList<double>(values_);
}

void QniteTicker::setValues(QVariantList& values)
{
    values_ = fromVariantList<double>(values);

    // compute min and max bounds
    std::sort(values_.begin(), values_.end(), std::less<double>());
    lowerBound_ = values_.first();
    upperBound_ = values_.last();

    // build ticks
    buildTicks();

    // notify
    emit valuesChanged();
}

void QniteTicker::setMinorTicks(QVariantList& ticks)
{
    minorTicks_ = fromVariantList<double>(ticks);
}

void QniteTicker::setMidTicks(QVariantList& ticks)
{
    midTicks_ = fromVariantList<double>(ticks);
}

void QniteTicker::setMajorTicks(QVariantList& ticks)
{
    majorTicks_ = fromVariantList<double>(ticks);
}

QVariantList QniteTicker::minorTicks() const
{
    return toVariantList<double>(minorTicks_);
}

QVariantList QniteTicker::midTicks() const
{
    return toVariantList<double>(midTicks_);
}

QVariantList QniteTicker::majorTicks() const
{
    return toVariantList<double>(majorTicks_);
}

void QniteTicker::setNumSteps(int steps)
{
    numSteps_ = steps;

    if (majorTicks_.size() != steps) {
        // rebuild ticks if needed
        buildTicks();
        emit valuesChanged();
    }
}

void QniteTicker::setBoundaries(double lower, double upper)
{
    lowerBound_ = lower;
    upperBound_ = upper;
}

void QniteTicker::reset()
{
    lowerBound_ = DEFAULT_LOWER_B;
    upperBound_ = DEFAULT_UPPER_B;
    numSteps_ = DEFAULT_NUM_STEPS;
    values_.clear();
    minorTicks_.clear();
    midTicks_.clear();
    majorTicks_.clear();
}
