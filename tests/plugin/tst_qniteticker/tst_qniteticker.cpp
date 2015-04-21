#include <QtTest/QtTest>
#include <QDebug>

#include "../../../modules/Qnite/plugin/qniteticker.h"


class FooTicker : public QniteTicker
{
    Q_OBJECT

public:
    FooTicker(QObject * p=0) : QniteTicker(p) {}
    void buildTicks() {}
};


class TestQniteTicker: public QObject
{
    Q_OBJECT

    FooTicker ticker;

private slots:
    void initTestCase()
    {

    }

    void testSetValues()
    {
        QCOMPARE(ticker.lower(), 0.);
    }
};

QTEST_MAIN(TestQniteTicker)
#include "tst_qniteticker.moc"
