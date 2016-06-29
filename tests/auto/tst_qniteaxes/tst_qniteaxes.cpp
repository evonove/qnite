#include <QtTest/QtTest>

#include "qniteaxes.h"
#include "tools/qnitetool.h"

#include "qniteartist.h"


class FooArtist : public QniteArtist
{
  Q_OBJECT

public Q_SLOTS:
  void processData() {}

public:
  bool sel;

  FooArtist(QQuickItem * p=0) : QniteArtist(p), sel(false) {}
  void clearSelection() { sel = false; }
  bool isSelected() const { return sel; }
};


class TestQniteAxes: public QObject
{
  Q_OBJECT

private slots:
  void testDefaults();

  void testAppendTool();
  void testSetOnTop();

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

void TestQniteAxes::testSetOnTop()
{
  QniteAxes axes;
  FooArtist a1, a2;

  auto prop = axes.artists();
  prop.append(&prop, &a1);
  prop.append(&prop, &a2);

  QList<QQuickItem*> l{&a1, &a2};
  QCOMPARE(l, axes.canvas()->childItems());

  axes.setOnTop(&a1);

  QList<QQuickItem*> l2{&a2, &a1};
  QCOMPARE(l2, axes.canvas()->childItems());
}

QTEST_MAIN(TestQniteAxes)
#include "tst_qniteaxes.moc"
