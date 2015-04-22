#include <QtTest/QtTest>
#include <QDebug>

#include "../../../modules/Qnite/plugin/qnitelinearticker.h"

class TestQniteLinearTicker: public QObject
{
    Q_OBJECT

    QniteLinearTicker ticker;
    QVariantList alist;

private slots:
    void initTestCase()
    {
        alist << QVariant(105.) << QVariant(343.)
              << QVariant(443.) << QVariant(543.);
    }

    void testReset()
    {
        ticker.setLooseNiceness(false);
        ticker.reset();
        QCOMPARE(ticker.looseNiceness(), true);
        QCOMPARE(ticker.numSteps(), 10);
    }

    void testDefaults()
    {
        QniteLinearTicker t;
        QCOMPARE(t.looseNiceness(), true);
        QCOMPARE(ticker.numSteps(), 10);
    }

    void testLooseProperty()
    {
        ticker.reset();
        ticker.setLooseNiceness(false);
        QCOMPARE(ticker.looseNiceness(), false);
    }

    void testBuildTicks()
    {
        ticker.reset();
        ticker.setNumSteps(5);
        ticker.setValues(alist);
        QVariantList l;
        l << QVariant(100.) << QVariant(200.) << QVariant(300.)
          << QVariant(400.) << QVariant(500.) << QVariant(600.);
        QCOMPARE(ticker.majorTicks(), l);
    }

};
QTEST_MAIN(TestQniteLinearTicker)
#include "tst_qnitelinearticker.moc"
