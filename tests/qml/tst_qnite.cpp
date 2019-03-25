#include <QtQml>
#include <QtQuickTest/quicktest.h>

#include "qnite.h"

QT_BEGIN_NAMESPACE
int main(int argc, char **argv) {
  Q_INIT_RESOURCE(qnite);
  QTEST_ADD_GPU_BLACKLIST_SUPPORT
  QTEST_SET_MAIN_SOURCE_PATH
  return quick_test_main(argc, argv, "qnite", QUICK_TEST_SOURCE_DIR);
}
QT_END_NAMESPACE
