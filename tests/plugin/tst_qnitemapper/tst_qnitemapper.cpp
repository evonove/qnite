#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>

#include "../../../modules/Qnite/plugin/qnitemapper.h"


class FooMapper : public QniteMapper
{
  Q_OBJECT

public:
  FooMapper(QObject *parent = 0): QniteMapper(parent) {}

  qreal factor() const { return 1.0; }
  qreal transform(qreal value) { return value; };
};


class TestQniteMapper: public QObject
{
  Q_OBJECT

  FooMapper mapper;

private slots:
    void testFactorChangedSignal();
};


// tests that the factorChanged signal is emitted
// when at least one of the min, max, size and flip
// properties changes
void TestQniteMapper::testFactorChangedSignal()
{
    QSignalSpy spy(&mapper, SIGNAL(factorChanged()));

    mapper.setMin(1);
    QCOMPARE(spy.count(), 1);

    mapper.setMax(1);
    QCOMPARE(spy.count(), 2);

    mapper.setSize(1);
    QCOMPARE(spy.count(), 3);

    mapper.setFlip(true);
    QCOMPARE(spy.count(), 4);
}

QTEST_MAIN(TestQniteMapper)
#include "tst_qnitemapper.moc"
