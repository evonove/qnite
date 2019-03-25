#include <QtTest/QtTest>

#include "qniteaxes.h"
#include "qniteaxis.h"
#include "tools/qnitetool.h"

#include "qniteartist.h"

class FooArtist : public QniteArtist {
  Q_OBJECT

public Q_SLOTS:
  void processData() {}

public:
  bool sel;

  FooArtist(QQuickItem *p = 0) : QniteArtist(p), sel(false) {}
  void clearSelection() { sel = false; }
  bool isSelected() const { return sel; }
};

class FooAxis : public QniteAxis {
  Q_OBJECT

public Q_SLOTS:
  void processData() {}

public:
  FooAxis(QQuickItem *p = 0) : QniteAxis(p) {}
};

class TestQniteAxes : public QObject {
  Q_OBJECT

private slots:
  void testDefaults();

  void testAppendTool();
  void testSetOnTop();
  void testPadding();
};

void TestQniteAxes::testDefaults() {
  QniteAxes axes;
  QCOMPARE(axes.canvas()->clip(), true);
}

void TestQniteAxes::testAppendTool() {
  QniteAxes axes;
  QniteTool tool;

  auto property = axes.tools();
  property.append(&property, &tool);

  // axes has been set
  QCOMPARE(tool.axes(), &axes);
  // tool has been visually parented to axes canvas
  QCOMPARE(axes.canvas(), tool.parentItem());
}

void TestQniteAxes::testSetOnTop() {
  QniteAxes axes;
  FooArtist a1, a2;

  auto prop = axes.artists();
  prop.append(&prop, &a1);
  prop.append(&prop, &a2);

  QList<QQuickItem *> l{&a1, &a2};
  QCOMPARE(l, axes.canvas()->childItems());

  axes.setOnTop(&a1);

  QList<QQuickItem *> l2{&a2, &a1};
  QCOMPARE(l2, axes.canvas()->childItems());
}

void TestQniteAxes::testPadding() {
  QniteAxes axes;

  // Axes bounds
  QList<qreal> xBounds{-10.0, 100.0};
  QList<qreal> yBounds{-20.0, 200.0};

  // Axes padding
  qreal xPadding{20.0};
  qreal yPadding{10.0};

  // Axis necessary to correctly
  // set bounds and padding
  auto xAxis = new FooAxis();
  auto yAxis = new FooAxis();

  axes.setAxisX(xAxis);
  axes.setAxisY(yAxis);

  axes.setXBounds(xBounds);
  axes.setYBounds(yBounds);

  axes.setXPadding(xPadding);
  axes.setYPadding(yPadding);

  QCOMPARE(axes.xPadding(), 20.0);
  QCOMPARE(axes.yPadding(), 10.0);

  // Check that bounds are correctly calculated
  // depending on the padding set
  auto expectedXLowerBound = xBounds.at(0) - xPadding;
  auto expectedXUpperBound = xBounds.at(1) + xPadding;
  auto expectedYLowerBound = yBounds.at(0) - yPadding;
  auto expectedYUpperBound = yBounds.at(1) + yPadding;

  QCOMPARE(axes.axisX()->lowerBound(), expectedXLowerBound);
  QCOMPARE(axes.axisX()->upperBound(), expectedXUpperBound);
  QCOMPARE(axes.axisY()->lowerBound(), expectedYLowerBound);
  QCOMPARE(axes.axisY()->upperBound(), expectedYUpperBound);
}

QTEST_MAIN(TestQniteAxes)
#include "tst_qniteaxes.moc"
