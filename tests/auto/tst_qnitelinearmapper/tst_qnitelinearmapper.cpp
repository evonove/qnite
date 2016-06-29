#include <QtTest/QtTest>

#include "qnitelinearmapper.h"


class TestQniteLinearMapper: public QObject
{
  Q_OBJECT

  QniteLinearMapper mapper;

private slots:
    void testMapTo_data();
    void testMapTo();
    void testMapToMulti();
};

void TestQniteLinearMapper::testMapTo_data()
{
  QTest::addColumn<qreal>("sourceLower");
  QTest::addColumn<qreal>("sourceUpper");
  QTest::addColumn<qreal>("destLower");
  QTest::addColumn<qreal>("destUpper");
  QTest::addColumn<bool>("flip");
  QTest::addColumn<qreal>("value");
  QTest::addColumn<qreal>("result");

  QTest::newRow("invalid source") << 0.0 << 0.0 << 1.0 << 5.0 << false << 1.0 << 0.0;
  QTest::newRow("invalid dest") << 1.0 << 5.0 << 0.0 << 0.0 << false << 1.0 << 0.;
  QTest::newRow("positive") << 0.0 << 10.0 << 0.0 << 100.0 << false << 1.5 << 15.0;
  QTest::newRow("negative") << -10.0 << -5.0 << 0.0 << 100.0 << false << -9.0 << 20.0;
  QTest::newRow("flipped positive") << 0.0 << 10.0 << 0.0 << 100.0 << true << 1.5 << 85.0;
  QTest::newRow("flipped negative") << -10.0 << -5.0 << 0.0 << 100.0 << true << -9.0 << 80.0;
}

void TestQniteLinearMapper::testMapTo()
{
  QFETCH(qreal, sourceLower);
  QFETCH(qreal, sourceUpper);
  QFETCH(qreal, destLower);
  QFETCH(qreal, destUpper);
  QFETCH(bool, flip);
  QFETCH(qreal, value);
  QFETCH(qreal, result);

  auto r = mapper.mapTo(sourceLower, sourceUpper, destLower, destUpper, value, flip);
  QCOMPARE(r, result);
}

void TestQniteLinearMapper::testMapToMulti()
{
  auto r = mapper.mapTo(0.0, 10.0, 0.0, 100.0, {1.5, 3.5});
  QCOMPARE(r.at(0), 15.0);
  QCOMPARE(r.at(1), 35.0);
}

QTEST_MAIN(TestQniteLinearMapper)
#include "tst_qnitelinearmapper.moc"
