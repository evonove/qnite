#ifndef QNITELINEARTICKER_H
#define QNITELINEARTICKER_H

#include "qniteticker.h"

class QniteLinearTicker: public QniteTicker
{
    Q_OBJECT
    Q_DISABLE_COPY(QniteLinearTicker)

public:
    explicit QniteLinearTicker(QObject * parent=0);
    virtual ~QniteLinearTicker() {}

protected:
    virtual void buildTicks();
};

#endif // QNITELINEARTICKER_H
