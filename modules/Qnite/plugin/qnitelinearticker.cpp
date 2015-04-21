#include "qnitelinearticker.h"

// defines
#define DEFAULT_NUM_STEPS 10


QniteLinearTicker::QniteLinearTicker(QObject *parent)
    : QniteTicker(parent)
{
    numSteps_ = DEFAULT_NUM_STEPS;
}

void QniteLinearTicker::buildTicks()
{

}
