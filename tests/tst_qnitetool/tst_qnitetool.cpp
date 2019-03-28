#include <QtTest/QtTest>

#include "qniteartist.h"
#include "qniteaxes.h"
#include "tools/qnitetool.h"

class FooArtist : public QniteArtist {
  Q_OBJECT

public Q_SLOTS:
  void processData() {}

public:
  FooArtist(QQuickItem *p = 0) : QniteArtist(p) {}
};

class FooTool : public QniteTool {
  Q_OBJECT

public:
  FooTool(QQuickItem *parent = 0) : QniteTool(parent) {}
  QList<QniteArtist *> getFooArtists() { return artists(); }
};

class TestQniteTool : public QObject {
  Q_OBJECT

private slots:

  void testInstance() {
    FooTool f;
    QniteAxes axes;
    FooArtist a1, a2;

    auto p1 = axes.artists();
    p1.append(&p1, &a1);
    p1.append(&p1, &a2);

    auto p2 = axes.tools();
    p2.append(&p2, &f);

    QList<QniteArtist *> l{&a1, &a2};
    QCOMPARE(f.getFooArtists(), l);
  }
};

QTEST_MAIN(TestQniteTool)
#include "tst_qnitetool.moc"
