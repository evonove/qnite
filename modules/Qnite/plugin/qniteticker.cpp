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

/*!
  \qmltype Ticker
  \instantiates QniteTicker
  \ingroup scaling
  \inqmlmodule Qnite
  \brief Divide axes scales into tickers

TODO: add a long description
*/

QniteTicker::QniteTicker(QObject * parent):
  QObject(parent),
  m_lowerBound{DEFAULT_LOWER_B},
  m_upperBound{DEFAULT_UPPER_B},
  m_numSteps{DEFAULT_NUM_STEPS}
{

}

QList<qreal> QniteTicker::values() const
{
  return m_values;
}
void QniteTicker::setValues(const QList<qreal>& values)
{
  if (m_values != values) {
    m_values = values;

    // compute min and max bounds
    std::sort(m_values.begin(), m_values.end(), std::less<qreal>());
    m_lowerBound = m_values.first();
    m_upperBound = m_values.last();

    // build ticks
    buildTicks();

    // notify
    emit valuesChanged();
  }
}

QList<qreal> QniteTicker::minorTicks() const
{
  return m_minorTicks;
}
void QniteTicker::setMinorTicks(const QList<qreal>& ticks)
{
  if (m_minorTicks != ticks) {
    m_minorTicks = ticks;
    emit minorTicksChanged();
  }
}

QList<qreal> QniteTicker::midTicks() const
{
  return m_midTicks;
}
void QniteTicker::setMidTicks(const QList<qreal>& ticks)
{
  if (m_midTicks != ticks) {
    m_midTicks = ticks;
    emit midTicksChanged();
  }
}

QList<qreal> QniteTicker::majorTicks() const
{
  return m_majorTicks;
}
void QniteTicker::setMajorTicks(const QList<qreal>& ticks)
{
  if (m_majorTicks != ticks) {
    m_majorTicks = ticks;
    emit majorTicksChanged();
  }
}

void QniteTicker::setNumSteps(int steps)
{
  m_numSteps = steps;

  if (m_majorTicks.size() != steps) {
    // rebuild ticks if needed
    buildTicks();
    emit valuesChanged();
  }
}

void QniteTicker::setBoundaries(qreal lower, qreal upper)
{
  m_lowerBound = lower;
  m_upperBound = upper;
}

void QniteTicker::reset()
{
  m_lowerBound = DEFAULT_LOWER_B;
  m_upperBound = DEFAULT_UPPER_B;
  m_numSteps = DEFAULT_NUM_STEPS;
  m_values.clear();
  m_minorTicks.clear();
  m_midTicks.clear();
  m_majorTicks.clear();
}
