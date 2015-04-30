#include <QtTest/QtTest>

#include "../../../modules/Qnite/plugin/qnitemapper.h"


class FooMapper : public QniteMapper
{
  Q_OBJECT

public:
  FooMapper(QObject *parent=0): QniteMapper(parent) {}

  qreal mapTo(qreal, qreal, qreal, qreal, qreal, bool) { return 1; }
};


class TestQniteMapper: public QObject
{
  Q_OBJECT

  QniteMapper* mapper;

private slots:
    void testMapTo();
};


void TestQniteMapper::testMapTo()
{
    mapper = new FooMapper();

    auto result = mapper->mapTo(0, 0, 0, 0, 0);
    QCOMPARE(result, 1.);

    auto results = mapper->mapTo(0, 0, 0, 0, {0, 0});
    for(auto v: results) {
      QCOMPARE(v, 1.);
    }

    delete mapper;
}

QTEST_MAIN(TestQniteMapper)
#include "tst_qnitemapper.moc"
