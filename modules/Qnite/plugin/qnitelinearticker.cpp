#include "qnitelinearticker.h"

#include <algorithm>
#include <QDebug>

// defines
#define DEFAULT_NUM_STEPS 10
#define DEFAULT_LOOSENESS true


namespace {

  double nice(double x, bool round)
  {
    int exp;
    double f;
    double nicef;

    exp = floor(log10(x));
    f = x / pow(10., exp);

    if (round) {
      if (f<1.5) nicef=1.;
      else if (f<3.) nicef=2.;
      else if (f<7.) nicef=5.;
      else nicef=10.;
    }
    else {
      if (f<=1.) nicef=1.;
      else if (f<=2.) nicef=2.;
      else if (f<=5.) nicef=5.;
      else nicef=10.;
    }

    return nicef*pow(10., exp);
  }

  void fill(QList<qreal>& ticks, qreal min, qreal max, int steps)
  {
    double range = nice(max-min, false);
    double d = nice(range/(steps-1), true);
    double graph_min = floor(min/d) * d;  // loose version of the algo
    double graph_max = ceil(max/d) * d;  // loose version of the algo
    // nFrac is the number of decimal numbers it'd be nice to show
    // not used at the moment
    // double nFrac = std::max(-floor(log10(d)), 0.);

    for (double x=graph_min; x<=graph_max + .5*d; x+=d) {
      ticks.append(x);
    }
  }

}


QniteLinearTicker::QniteLinearTicker(QObject *parent)
  : QniteTicker(parent),
    m_loose{DEFAULT_LOOSENESS}
{
  setNumSteps(DEFAULT_NUM_STEPS);
}

void QniteLinearTicker::buildTicks()
{
  if (lower() >= upper()) {
    qWarning() << QString("Illegal values for ticker bounds: %1,%2")
                          .arg(lower()).arg(upper());
    return;
  }

  QList<qreal> majorTicks;
  fill(majorTicks, lower(), upper(), numSteps());
  setMajorTicks(majorTicks);

  QList<qreal> segment;
  // build mid ticks for the first segment of major ones
  fill(segment, majorTicks[0], majorTicks[1], numSteps());
  // get rid of the boundaries
  segment.removeFirst(); segment.removeLast();
  // start building midTicks
  QList<qreal> midTicks(segment);
  // translate first segment into the whole range
  for (int i=0; i<majorTicks.size()-2; i++) {
    foreach(qreal val, segment) {
      midTicks.append(val + majorTicks[i]);
    }
  }
  setMidTicks(midTicks);

  // same as above
  segment.clear();
  fill(segment, midTicks[0], midTicks[1], numSteps());
  segment.removeFirst(); segment.removeLast();
  QList<qreal> minorTicks(segment);
  for (int i=0; i<midTicks.size()-2; i++) {
    foreach(qreal val, segment) {
      minorTicks.append(val + midTicks[i]);
    }
  }
  setMinorTicks(minorTicks);
}

void QniteLinearTicker::setLooseNiceness(bool is_loose)
{
  m_loose = is_loose;
}

bool QniteLinearTicker::looseNiceness() const
{
  return m_loose;
}

void QniteLinearTicker::reset()
{
  QniteTicker::reset();
  m_loose = DEFAULT_LOOSENESS;
  setNumSteps(DEFAULT_NUM_STEPS);
}

