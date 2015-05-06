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

    /*void testBuildTicks()
    {
        ticker.reset();
        ticker.setNumSteps(5);
        ticker.setValues(alist);

        QList<qreal> l;
        l << 100. << 200. << 300. << 400. << 500. << 600.;
        QCOMPARE(ticker.majorTicks(), l);

        l.clear();
        l << 120. << 140. << 160. << 180. << 220. << 240. << 260. << 280.
          << 320. << 340. << 360. << 380. << 420. << 440. << 460. << 480.
          << 520. << 540. << 560. << 580.;
        QCOMPARE(ticker.midTicks(), l);

        l.clear();
        l << 125. << 130. << 135. << 245. << 250. << 255. << 265. << 270.
          << 275. << 285. << 290. << 295. << 305. << 310. << 315. << 345.
          << 350. << 355. << 365. << 370. << 375. << 385. << 390. << 395.
          << 405. << 410. << 415. << 445. << 450. << 455. << 465. << 470.
          << 475. << 485. << 490. << 495. << 505. << 510. << 515. << 545.
          << 550. << 555. << 565. << 570. << 575. << 585. << 590. << 595.
          << 605. << 610. << 615. << 645. << 650. << 655. << 665. << 670.
          << 675.;
        QCOMPARE(ticker.minorTicks(), l);
    }*/

    void testNasty()
    {
      ticker.reset();
      ticker.setNumSteps(5);
      ticker.setBoundaries(0, 10);

      QList<qreal> l {0, 2, 4, 6, 8, 10};
      QCOMPARE(ticker.majorTicks(), l);

      QList<qreal> l2 {0.5, 1, 1.5, 2.5, 3, 3.5, 4.5, 5, 5.5, 6.5, 7, 7.5,
                       8.5, 9, 9.5};
      QCOMPARE(ticker.midTicks(), l2);

      QList<qreal> l3 {0.1, 0.2, 0.3, 0.4, 0.6, 0.7, 0.8, 0.9, 1.1, 1.2, 1.3,
                       1.4, 1.6, 1.7, 1.8, 1.9, 2.1, 2.2, 2.3, 2.4, 2.6, 2.7,
                       2.8, 2.9, 3.1, 3.2, 3.3, 3.4, 3.6, 3.7, 3.8, 3.9, 4.1,
                       4.2, 4.3, 4.4, 4.6, 4.7, 4.8, 4.9, 5.1, 5.2, 5.3, 5.4,
                       5.6, 5.7, 5.8, 5.9, 6.1, 6.2, 6.3, 6.4, 6.6, 6.7, 6.8,
                       6.9, 7.1, 7.2, 7.3, 7.4, 7.6, 7.7, 7.8, 7.9, 8.1, 8.2,
                       8.3, 8.4, 8.6, 8.7, 8.8, 8.9, 9.1, 9.2, 9.3, 9.4, 9.6,
                       9.7, 9.8, 9.9};
      QCOMPARE(ticker.minorTicks(), l3);
    }

};
QTEST_MAIN(TestQniteLinearTicker)
#include "tst_qnitelinearticker.moc"
