#include <QtTest/QtTest>

#include "qnitelinearticker.h"

class TestQniteLinearTicker : public QObject {
  Q_OBJECT

  QniteLinearTicker ticker;
  QList<qreal> alist;

private slots:
  void initTestCase() { alist << 105. << 343. << 443. << 543.; }

  void testReset() {
    ticker.setLooseNiceness(false);
    ticker.reset();
    QCOMPARE(ticker.looseNiceness(), true);
    QCOMPARE(ticker.numSteps(), 10);
  }

  void testDefaults() {
    QniteLinearTicker t;
    QCOMPARE(t.looseNiceness(), true);
    QCOMPARE(ticker.numSteps(), 10);
  }

  void testLooseProperty() {
    ticker.reset();
    ticker.setLooseNiceness(false);
    QCOMPARE(ticker.looseNiceness(), false);
  }

  void testBuildTicks() {
    ticker.reset();
    ticker.setNumSteps(5);
    ticker.setValues(alist);

    QList<qreal> l{100, 200, 300, 400, 500, 600};
    QCOMPARE(ticker.majorTicks(), l);

    QList<qreal> l2{150, 250, 350, 450, 550};
    QCOMPARE(ticker.minorTicks(), l2);
  }

  void testBuildTicksDefault() {
    ticker.reset();
    ticker.setBoundaries(0, 10);

    QList<qreal> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    QCOMPARE(ticker.majorTicks(), l);

    QList<qreal> l2{0.2, 0.4, 0.6, 0.8, 1.2, 1.4, 1.6, 1.8, 2.2, 2.4,
                    2.6, 2.8, 3.2, 3.4, 3.6, 3.8, 4.2, 4.4, 4.6, 4.8,
                    5.2, 5.4, 5.6, 5.8, 6.2, 6.4, 6.6, 6.8, 7.2, 7.4,
                    7.6, 7.8, 8.2, 8.4, 8.6, 8.8, 9.2, 9.4, 9.6, 9.8};
    QCOMPARE(ticker.minorTicks(), l2);
  }
};
QTEST_MAIN(TestQniteLinearTicker)
#include "tst_qnitelinearticker.moc"
