#include <QtTest/QtTest>
#include <QDebug>

#include "../../../modules/Qnite/plugin/qnitelinearticker.h"

class TestQniteLinearTicker: public QObject
{
    Q_OBJECT

    QniteLinearTicker ticker;
    QList<qreal> alist;

private slots:
    void initTestCase()
    {
        alist << 105. << 343. << 443. << 543.;
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
        QList<qreal> l;
        l << 100. << 200. << 300. << 400. << 500. << 600.;
        QCOMPARE(ticker.majorTicks(), l);
    }

};
QTEST_MAIN(TestQniteLinearTicker)
#include "tst_qnitelinearticker.moc"
