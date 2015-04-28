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
    }

};
QTEST_MAIN(TestQniteLinearTicker)
#include "tst_qnitelinearticker.moc"
