#include "plugin.h"

#include "qnitecurve.h"
#include "qnitescalemap.h"

#include <QtQml>

void QnitePlugin::registerTypes(const char *uri)
{
  // @uri qnite
  qmlRegisterType<QniteCurve>(uri, 1, 0, "Curve");
  qmlRegisterType<QniteScaleMap>(uri, 1, 0, "ScaleMap");
}

