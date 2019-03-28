#include <QVector>
#include <QtQuickTest/quicktest.h>

#include "qnite.h"

// We need to set the QML import paths before the test file is read and this is
// the only working way
int main(int argc, char **argv) {
  QTEST_ADD_GPU_BLACKLIST_SUPPORT
  QTEST_SET_MAIN_SOURCE_PATH
  QVector<char *> newArgv;
  int i = 0;
  for (; i < argc; i++) {
    newArgv << argv[i];
  }
  newArgv << strdup("-import");
  newArgv << strdup("qrc:/");
  newArgv << strdup("-import");
  newArgv << strdup("qrc:/qml");
  newArgv << strdup("-import");
  newArgv << strdup(INSTALL_ROOT);
  return quick_test_main(newArgv.size(), newArgv.data(), "tst_qnitecircle",
                         QUICK_TEST_SOURCE_DIR);
}
