#include "qnitelinearticker.h"

#include <algorithm>

// defines
#define DEFAULT_NUM_STEPS 10


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
    : QniteTicker(parent), loose_(true)
{
    numSteps_ = DEFAULT_NUM_STEPS;
}

void QniteLinearTicker::buildTicks()
{
    majorTicks_.clear();

    double range = nice(upperBound_-lowerBound_, false);
    double d = nice(range/(numSteps_-1), true);
    double graph_min = floor(lowerBound_/d) * d;  // loose version of the algo
    double graph_max = ceil(upperBound_/d) * d;  // loose version of the algo
    // double nFrac = std::max(-floor(log10(d)), 0.);

    for (double x=graph_min; x<=graph_max + .5*d; x+=d) {
        majorTicks_.append(x);
        // TODO show nFrac fraction digits
    }

    qDebug() << majorTicks_;
}

void QniteLinearTicker::setLooseNiceness(bool is_loose)
{
    loose_ = is_loose;
}

bool QniteLinearTicker::looseNiceness() const
{
    return loose_;
}

