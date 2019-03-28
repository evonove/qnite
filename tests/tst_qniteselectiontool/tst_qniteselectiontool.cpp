#include <QtTest/QtTest>

#include "qniteartist.h"
#include "qniteaxes.h"
#include "tools/qniteselectiontool.h"

class FooArtist : public QniteArtist {
  Q_OBJECT

public Q_SLOTS:
  void processData() {}

public:
  bool sel;

  FooArtist(QQuickItem *p = 0) : QniteArtist(p), sel(false) {}
  void clearSelection() { sel = false; }
  bool isSelected() const { return sel; }
  bool select(QPoint) {
    sel = true;
    return !propagateSelection();
  }
};

class FooSelector : public QniteSelectionTool {
  Q_OBJECT

public:
  FooSelector(QQuickItem *parent = 0) : QniteSelectionTool(parent) {}
  QList<QniteArtist *> getFooArtists() { return artists(); }
  void fooSelect() { select(); }
  void fooClearSelection() { clearSelection(); }

protected:
  bool doSelect(QniteArtist *a) { return a->select(QPoint()); }
};

class TestQniteSelectionTool : public QObject {
  Q_OBJECT

  FooArtist a1, a2, a3, a4;
  FooSelector sel;
  QniteAxes axes;

private slots:

  void initTestCase() {
    auto p1 = axes.artists();
    p1.append(&p1, &a1);
    p1.append(&p1, &a2);
    p1.append(&p1, &a3);
    p1.append(&p1, &a4);

    auto p2 = axes.tools();
    p2.append(&p2, &sel);
  }

  void init() {
    a1.setSelectable(true);
    a2.setSelectable(true);
    a3.setSelectable(true);
    a4.setSelectable(true);

    a1.setPropagateSelection(true);
    a2.setPropagateSelection(true);
    a3.setPropagateSelection(true);
    a4.setPropagateSelection(true);
  }

  void testSelection() {
    a2.setSelectable(false);
    a3.setPropagateSelection(false);

    sel.fooSelect();

    QCOMPARE(a1.selected(), true);
    QCOMPARE(a2.selected(), false); // not selectable
    QCOMPARE(a3.selected(), true);
    QCOMPARE(a4.selected(), false); // a3 didn't propagate selection
  }

  void testClearSelection() {
    sel.fooSelect();
    QCOMPARE(a1.selected(), true);
    QCOMPARE(a2.selected(), true);
    QCOMPARE(a3.selected(), true);
    QCOMPARE(a4.selected(), true);

    sel.fooClearSelection();
    QCOMPARE(a1.selected(), false);
    QCOMPARE(a2.selected(), false);
    QCOMPARE(a3.selected(), false);
    QCOMPARE(a4.selected(), false);
  }

  void testReset() {
    sel.fooSelect();
    QCOMPARE(a1.selected(), true);
    QCOMPARE(a2.selected(), true);
    QCOMPARE(a3.selected(), true);
    QCOMPARE(a4.selected(), true);

    sel.reset();
    QCOMPARE(a1.selected(), false);
    QCOMPARE(a2.selected(), false);
    QCOMPARE(a3.selected(), false);
    QCOMPARE(a4.selected(), false);
  }
};

QTEST_MAIN(TestQniteSelectionTool)
#include "tst_qniteselectiontool.moc"
