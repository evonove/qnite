#include <QtTest/QtTest>


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

class TestQniteArtist: public QObject
{
  Q_OBJECT

  FooArtist  artist;

private slots:
  void initTestCase()
  {
  }

  void cleanupTestCase()
  {
  }

  void testSelectableFlag()
  {
    QCOMPARE(artist.selectable(), false);

    artist.setSelectable(true);
    QCOMPARE(artist.selectable(), true);

    artist.sel = true;
    artist.setSelectable(false);
    QCOMPARE(artist.selectable(), false);
    QCOMPARE(artist.sel, false);
  }

  void testSelected()
  {
    artist.sel = true;

    artist.setSelectable(true);
    QCOMPARE(artist.selected(), true);

    artist.setSelectable(false);
    QCOMPARE(artist.selected(), false);
  }

  void testPropagateSelection()
  {
    QCOMPARE(artist.propagateSelection(), false);
    QCOMPARE(artist.select(QPoint()), true); // accepted

    artist.setPropagateSelection(true);

    QCOMPARE(artist.propagateSelection(), true);
    QCOMPARE(artist.select(QPoint()), false); // rejected
  }
};

QTEST_MAIN(TestQniteArtist)
#include "tst_qniteartist.moc"
