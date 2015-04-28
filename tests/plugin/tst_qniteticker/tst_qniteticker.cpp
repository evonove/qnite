#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>

#include "../../../modules/Qnite/plugin/qniteticker.h"


class FooTicker : public QniteTicker
{
  Q_OBJECT

public:
  FooTicker(QObject * p=0) : QniteTicker(p) {}
  void buildTicks()
  {
    QList<qreal> t;
    for (int i=0; i<numSteps(); ++i) {
      t << i * 1.5;
    }

    setMajorTicks(t);
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

    QSignalSpy spy(&ticker, SIGNAL(boundariesChanged()));
    QSignalSpy buildSpy(&ticker, SIGNAL(tickersBuilt()));

    ticker.setBoundaries(b);
    ticker.setBoundaries(b); // ensure the signal isn't emitted twice

    QCOMPARE(ticker.lower(), -1.);
    QCOMPARE(ticker.upper(), 1.);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(buildSpy.count(), 1);

    b << 0; // add a third value
    ticker.setBoundaries(b);
    QCOMPARE(buildSpy.count(), 1); // boundaries were not set with bad input
  }

  void testSetValues()
  {
    ticker.reset();

    QSignalSpy spy(&ticker, SIGNAL(valuesChanged()));
    QSignalSpy buildSpy(&ticker, SIGNAL(tickersBuilt()));

    ticker.setValues(alist);
    ticker.setValues(alist); // ensure the signal isn't emitted twice

    QList<qreal> l;

    QCOMPARE(ticker.values(), alist);
    QCOMPARE(ticker.lower(), 1.);
    QCOMPARE(ticker.upper(), 4.);
    QCOMPARE(ticker.majorTicks(), l);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(buildSpy.count(), 1);
  }

  void testSetTicks()
  {
    ticker.reset();

    QSignalSpy spy1(&ticker, SIGNAL(minorTicksChanged()));
    QSignalSpy spy2(&ticker, SIGNAL(midTicksChanged()));
    QSignalSpy spy3(&ticker, SIGNAL(midTicksChanged()));

    ticker.setMinorTicks(alist);
    ticker.setMinorTicks(alist); // ensure the signal isn't emitted twice
    ticker.setMidTicks(anotherlist);
    ticker.setMidTicks(anotherlist); // idem
    ticker.setMajorTicks(anotherlistagain);
    ticker.setMajorTicks(anotherlistagain); // idem

    QCOMPARE(ticker.minorTicks(), alist);
    QCOMPARE(ticker.midTicks(), anotherlist);
    QCOMPARE(ticker.majorTicks(), anotherlistagain);
    QCOMPARE(spy1.count(), 1);
    QCOMPARE(spy2.count(), 1);
    QCOMPARE(spy3.count(), 1);
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

    QSignalSpy spy(&ticker, SIGNAL(numStepsChanged()));
    QSignalSpy buildSpy(&ticker, SIGNAL(tickersBuilt()));

    ticker.setNumSteps(5);
    QCOMPARE(buildSpy.count(), 1); // ensure the build was triggered

    ticker.setValues(alist);
    QCOMPARE(ticker.majorTicks().size(), 5);
    ticker.setNumSteps(6);
    ticker.setNumSteps(6); // ensure the signal isn't emitted twice
    QCOMPARE(ticker.majorTicks().size(), 6);
    QCOMPARE(spy.count(), 2);
  }

};
QTEST_MAIN(TestQniteTicker)
#include "tst_qniteticker.moc"
