#include <QtTest/QtTest>

#include "../../../modules/Qnite/plugin/qniteartist.h"


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
};

QTEST_MAIN(TestQniteArtist)
#include "tst_qniteartist.moc"
