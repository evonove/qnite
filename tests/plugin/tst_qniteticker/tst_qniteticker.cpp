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
        majorTicks_ << 10. << 20. << 30.;
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
        l << QVariant(10.) << QVariant(20.) << QVariant(30.);

        QCOMPARE(ticker.values(), alist);
        QCOMPARE(ticker.lower(), 1.);
        QCOMPARE(ticker.upper(), 4.);
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

};
QTEST_MAIN(TestQniteTicker)
#include "tst_qniteticker.moc"
