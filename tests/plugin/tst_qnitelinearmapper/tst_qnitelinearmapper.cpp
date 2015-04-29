#include <QtTest/QtTest>
#include <QDebug>

#include "../../../modules/Qnite/plugin/qnitelinearmapper.h"


class TestQniteLinearMapper: public QObject
{
  Q_OBJECT

  QniteLinearMapper mapper;

private slots:
    void testFactor_data();
    void testFactor();

    void testTransform_data();
    void testTransform();
};

void TestQniteLinearMapper::testFactor_data()
{
  QTest::addColumn<qreal>("min");
  QTest::addColumn<qreal>("max");
  QTest::addColumn<qreal>("size");
  QTest::addColumn<qreal>("result");

  QTest::newRow("nodata nosize") << 0.0 << 0.0 << 0.0 << 0.0;
  QTest::newRow("nodata") << 0.0 << 0.0 << 1.0 << 0.0;
  QTest::newRow("valid") << 0.0 << 10.0 << 100.0 << 10.0;
  QTest::newRow("negative range") << -10.0 << -5.0 << 100.0 << 20.0;
}

void TestQniteLinearMapper::testFactor()
{
  QFETCH(qreal, min);
  QFETCH(qreal, max);
  QFETCH(qreal, size);
  QFETCH(qreal, result);

  mapper.setMin(min);
  mapper.setMax(max);
  mapper.setSize(size);

  QCOMPARE(mapper.factor(), result);
}

void TestQniteLinearMapper::testTransform_data()
{
  QTest::addColumn<qreal>("min");
  QTest::addColumn<qreal>("max");
  QTest::addColumn<qreal>("size");
  QTest::addColumn<bool>("flip");
  QTest::addColumn<qreal>("value");
  QTest::addColumn<qreal>("result");

  QTest::newRow("nosize") << 0.0 << 0.0 << 0.0 << false << 1.0 << 0.0;
  QTest::newRow("nodata") << 0.0 << 0.0 << 1.0 << false << 1.0 << 0.0;
  QTest::newRow("positive") << 0.0 << 10.0 << 100.0 << false << 1.5 << 15.0;
  QTest::newRow("negative") << -10.0 << -5.0 << 100.0 << false << -9.0 << 20.0;
  QTest::newRow("flipped positive") << 0.0 << 10.0 << 100.0 << true << 1.5 << 85.0;
  QTest::newRow("flipped negative") << -10.0 << -5.0 << 100.0 << true << -9.0 << 80.0;
}

void TestQniteLinearMapper::testTransform()
{
  QFETCH(qreal, min);
  QFETCH(qreal, max);
  QFETCH(qreal, size);
  QFETCH(bool, flip);
  QFETCH(qreal, value);
  QFETCH(qreal, result);

  mapper.setMin(min);
  mapper.setMax(max);
  mapper.setSize(size);
  mapper.setFlip(flip);

  QCOMPARE(mapper.transform(value), result);
}

QTEST_MAIN(TestQniteLinearMapper)
#include "tst_qnitelinearmapper.moc"
