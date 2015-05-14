#include <QtTest/QtTest>

#include "qniteaxes.h"
#include "tools/qnitetool.h"

class TestQniteAxes: public QObject
{
  Q_OBJECT

private slots:
  void testDefaults();

  void testAppendTool();

};

void TestQniteAxes::testDefaults()
{
  QniteAxes axes;
  QCOMPARE(axes.canvas()->clip(), true);
}

void TestQniteAxes::testAppendTool()
{
  QniteAxes axes;
  QniteTool tool;

  auto property = axes.tools();
  property.append(&property, &tool);

  // axes has been set
  QCOMPARE(tool.axes(), &axes);
  // tool has been visually parented to axes canvas
  QCOMPARE(axes.canvas(), tool.parentItem());
}

QTEST_MAIN(TestQniteAxes)
#include "tst_qniteaxes.moc"
