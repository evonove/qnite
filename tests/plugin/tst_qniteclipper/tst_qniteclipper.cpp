#include <algorithm>
#include <random>

#include <QtTest/QtTest>

#include "../../../modules/Qnite/plugin/qniteclipper.h"


class TestQniteClipper: public QObject
{
  Q_OBJECT

  QniteClipper clipper;
  QList<qreal> m_xValues;
  QList<qreal> m_yValues;

  private slots:
    void initTestCase();
    void testClip();
};

void TestQniteClipper::initTestCase()
{
  int n = 10000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> d(0, 10);
  std::uniform_real_distribution<double> o(-10, 0);

  for(int i = 0; i < n; ++i) {
    m_xValues.append(d(gen));
    m_xValues.append(o(gen));
    m_yValues.append(d(gen));
    m_yValues.append(o(gen));
  }

  std::sort(m_xValues.begin(), m_xValues.end());
}

void TestQniteClipper::testClip()
{
  QList<qreal> outX;
  QList<qreal> outY;

  QBENCHMARK {
    outX.clear();
    outY.clear();
    clipper.clip(m_xValues, m_yValues, 0., 10., 0., 10., outX, outY);
  }

  QCOMPARE(outX.size(), 5000);
  QCOMPARE(outY.size(), 5000);
}

QTEST_MAIN(TestQniteClipper)
#include "tst_qniteclipper.moc"
