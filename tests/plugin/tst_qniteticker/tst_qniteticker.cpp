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
      m_majorTicks.clear();
      for (int i=0; i<m_numSteps; ++i) {
          m_majorTicks << i * 1.5;
      }
  }
};


class TestQniteTicker: public QObject
{
  Q_OBJECT

  FooTicker ticker;
  QList<qreal> alist;
  QList<qreal> anotherlist;
  QList<qreal> anotherlistagain;

private slots:
    void initTestCase()
    {
        alist << 1. << 2. << 3. << 4.;
        anotherlist << -1. << 1.1 << 1.2;
        anotherlistagain << -1. << 1.1 << 1.2 << 2. << 2.2;
    }

    void testBoundaries()
    {
        ticker.reset();
        QList<qreal> b;
        b << -1. << 1.;
        ticker.setBoundaries(b);

        QCOMPARE(ticker.lower(), -1.);
        QCOMPARE(ticker.upper(), 1.);
    }

    void testSetValues()
    {
        ticker.reset();
        ticker.setValues(alist);

        QList<qreal> l;

        QCOMPARE(ticker.values(), alist);
        QCOMPARE(ticker.lower(), 1.);
        QCOMPARE(ticker.upper(), 4.);
        QCOMPARE(ticker.majorTicks(), l);

        ticker.setNumSteps(3);
        // build l according to builTicks() implementation from FooTicker
        l << 0. << 1.5 << 3.0;
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
        QCOMPARE(ticker.values(), QList<qreal>());
        QCOMPARE(ticker.minorTicks(), QList<qreal>());
        QCOMPARE(ticker.midTicks(), QList<qreal>());
        QCOMPARE(ticker.majorTicks(), QList<qreal>());
    }

    void testDefaults()
    {
        FooTicker foo;
        QCOMPARE(foo.numSteps(), 0);
        QCOMPARE(foo.lower(), 0.);
        QCOMPARE(foo.upper(), 0.);
        QCOMPARE(foo.values(), QList<qreal>());
        QCOMPARE(foo.minorTicks(), QList<qreal>());
        QCOMPARE(foo.midTicks(), QList<qreal>());
        QCOMPARE(foo.majorTicks(), QList<qreal>());
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
