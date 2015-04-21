/*!
    \qmltype Ticker
    \instantiates QniteTicker
    \ingroup scaling
    \inqmlmodule Qnite
    \brief Divide axes scales into tickers

    TODO: add a long description
*/
#include "qniteticker.h"


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
    : QObject(parent)
{

}

QVariantList QniteTicker::values() const
{
    return toVariantList<float>(values_);
}

void QniteTicker::setValues(QVariantList& values)
{
    values_ = fromVariantList<float>(values);

    // compute min and max bounds
    qSort(values_.begin(), values_.end(), std::greater<float>());
    lowerBound_ = values_.first();
    upperBound_ = values_.last();

    emit valuesChanged();
}

void QniteTicker::setMinorTicks(QVariantList& ticks)
{
    minorTicks_ = fromVariantList<float>(ticks);
}

void QniteTicker::setMidTicks(QVariantList& ticks)
{
    midTicks_ = fromVariantList<float>(ticks);
}

void QniteTicker::setMajorTicks(QVariantList& ticks)
{
    majorTicks_ = fromVariantList<float>(ticks);
}

QVariantList QniteTicker::minorTicks() const
{
    return toVariantList<float>(minorTicks_);
}

QVariantList QniteTicker::midTicks() const
{
    return toVariantList<float>(midTicks_);
}

QVariantList QniteTicker::majorTicks() const
{
    return toVariantList<float>(majorTicks_);
}
