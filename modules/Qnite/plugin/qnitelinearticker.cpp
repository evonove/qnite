#include "qnitelinearticker.h"

#include <algorithm>

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

}


QniteLinearTicker::QniteLinearTicker(QObject *parent)
    : QniteTicker(parent),
    m_loose{DEFAULT_LOOSENESS}
{
    setNumSteps(DEFAULT_NUM_STEPS);
}

void QniteLinearTicker::buildTicks()
{
  QList<qreal> majorTicks;

  double range = nice(upper()-lower(), false);
  double d = nice(range/(numSteps()-1), true);
  double graph_min = floor(lower()/d) * d;  // loose version of the algo
  double graph_max = ceil(upper()/d) * d;  // loose version of the algo
  // double nFrac = std::max(-floor(log10(d)), 0.);

  for (double x=graph_min; x<=graph_max + .5*d; x+=d) {
    majorTicks.append(x);
    // TODO show nFrac fraction digits
  }

  setMajorTicks(majorTicks);
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

