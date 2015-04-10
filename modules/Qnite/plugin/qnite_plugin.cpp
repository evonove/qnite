#include "qnite_plugin.h"
#include "myitem.h"

#include <qqml.h>

void QnitePlugin::registerTypes(const char *uri)
{
  // @uri qnite
  qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
}


