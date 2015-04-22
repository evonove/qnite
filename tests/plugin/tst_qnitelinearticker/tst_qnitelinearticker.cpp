#include <QtTest/QtTest>
#include <QDebug>

#include "../../../modules/Qnite/plugin/qnitelinearticker.h"

class TestQniteLinearTicker: public QObject
{
    Q_OBJECT

    QniteLinearTicker ticker;

private slots:
    void initTestCase()
    {

    }

};
QTEST_MAIN(TestQniteLinearTicker)
#include "tst_qnitelinearticker.moc"
