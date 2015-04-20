#ifndef QNITETICKER_H
#define QNITETICKER_H

#include <QObject>

class QniteTicker : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QniteTicker)

    Q_PROPERTY(QVariantList xValues READ xValues WRITE setXValues NOTIFY xValuesChanged)

public:
    explicit QniteTicker(QObject * parent=0);
    virtual ~QniteTicker() {}

protected:
    virtual void buildTicks() = 0;

};

#endif // QNITETICKER_H

