#include <QtTest/QtTest>
#include <QDebug>

#include "../../../modules/Qnite/plugin/qniteticker.h"


class FooTicker : public QniteTicker
{
    Q_OBJECT

public:
    FooTicker(QObject * p=0) : QniteTicker(p) {}
    void buildTicks()
    {
        majorTicks_.clear();
        for (int i=0; i<numSteps_; ++i) {
            majorTicks_ << i * 1.5;
        }
    }
};


class TestQniteTicker: public QObject
{
    Q_OBJECT

    FooTicker ticker;
    QVariantList alist;
    QVariantList anotherlist;
    QVariantList anotherlistagain;

private slots:
    void initTestCase()
    {
        alist << QVariant(1.) << QVariant(2.) << QVariant(3.) << QVariant(4.);
        anotherlist << QVariant(-1.) << QVariant(1.1) << QVariant(1.2);
        anotherlistagain << QVariant(-1.) << QVariant(1.1) << QVariant(1.2) <<
                            QVariant(2.) << QVariant(2.2);
    }

    void testBoundaries()
    {
        ticker.reset();
        ticker.setBoundaries(-1., 1.);

        QCOMPARE(ticker.lower(), -1.);
        QCOMPARE(ticker.upper(), 1.);
    }

    void testSetValues()
    {
        ticker.reset();
        ticker.setValues(alist);

        QVariantList l;

        QCOMPARE(ticker.values(), alist);
        QCOMPARE(ticker.lower(), 1.);
        QCOMPARE(ticker.upper(), 4.);
        QCOMPARE(ticker.majorTicks(), l);

        ticker.setNumSteps(3);
        // build l according to builTicks() implementation from FooTicker
        l << QVariant(0.) << QVariant(1.5) << QVariant(3.0);
        QCOMPARE(ticker.majorTicks(), l);
    }

    void testSetTicks()
    {
        ticker.reset();
        ticker.setMinorTicks(alist);
        ticker.setMidTicks(anotherlist);
        ticker.setMajorTicks(anotherlistagain);

        QCOMPARE(ticker.minorTicks(), alist);
        QCOMPARE(ticker.midTicks(), anotherlist);
        QCOMPARE(ticker.majorTicks(), anotherlistagain);
    }

    void testReset()
    {
        ticker.setValues(alist);
        ticker.setNumSteps(5);
        ticker.buildTicks();

        ticker.reset();

        QCOMPARE(ticker.numSteps(), 0);
        QCOMPARE(ticker.lower(), 0.);
        QCOMPARE(ticker.upper(), 0.);
        QCOMPARE(ticker.values(), QVariantList());
        QCOMPARE(ticker.minorTicks(), QVariantList());
        QCOMPARE(ticker.midTicks(), QVariantList());
        QCOMPARE(ticker.majorTicks(), QVariantList());
    }

    void testDefaults()
    {
        FooTicker foo;
        QCOMPARE(foo.numSteps(), 0);
        QCOMPARE(foo.lower(), 0.);
        QCOMPARE(foo.upper(), 0.);
        QCOMPARE(foo.values(), QVariantList());
        QCOMPARE(foo.minorTicks(), QVariantList());
        QCOMPARE(foo.midTicks(), QVariantList());
        QCOMPARE(foo.majorTicks(), QVariantList());
    }

    void testSetNumSteps()
    {
        ticker.reset();
        ticker.setNumSteps(5);
        ticker.setValues(alist);
        QCOMPARE(ticker.majorTicks().size(), 5);
        ticker.setNumSteps(6);
        QCOMPARE(ticker.majorTicks().size(), 6);
    }

};
QTEST_MAIN(TestQniteTicker)
#include "tst_qniteticker.moc"
