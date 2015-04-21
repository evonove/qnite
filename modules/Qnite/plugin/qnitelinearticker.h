#ifndef QNITELINEARTICKER_H
#define QNITELINEARTICKER_H

#include "qniteticker.h"

class QniteLinearTicker: public QniteTicker
{
    Q_OBJECT
    Q_DISABLE_COPY(QniteLinearTicker)

    Q_PROPERTY(bool looseNiceness READ looseNiceness WRITE setLooseNiceness)

public:
    explicit QniteLinearTicker(QObject * parent=0);
    virtual ~QniteLinearTicker() {}

    void setLooseNiceness(bool);
    bool looseNiceness() const;

protected:
    virtual void buildTicks();

    bool loose_;
};

#endif // QNITELINEARTICKER_H
