#include <QtTest/QtTest>

#include "qniteaxes.h"

class TestQniteAxes: public QObject
{
  Q_OBJECT

private slots:
  void testDefaults();

};

void TestQniteAxes::testDefaults()
{
  QniteAxes axes;
  QCOMPARE(axes.canvas()->clip(), true);
}

QTEST_MAIN(TestQniteAxes)
#include "tst_qniteaxes.moc"
