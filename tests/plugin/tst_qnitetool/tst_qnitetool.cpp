#include <QtTest/QtTest>

#include "tools/qnitetool.h"

class FooTool: public QniteTool
{
  Q_OBJECT
public:
  FooTool(QQuickItem* parent = 0):
    QniteTool(parent)
  {}
};

class TestQniteTool: public QObject
{
  Q_OBJECT

private slots:

  void testInstance();

};

void TestQniteTool::testInstance()
{
  FooTool f;
}

QTEST_MAIN(TestQniteTool)
#include "tst_qnitetool.moc"
