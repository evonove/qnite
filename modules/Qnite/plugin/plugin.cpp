#include "plugin.h"

#include "qnitecurve.h"
#include "qnitescalemap.h"
#include "qniteticker.h"
#include "qnitelinearticker.h"

#include <QtQml>

void QnitePlugin::registerTypes(const char *uri)
{
  // @uri qnite
  qmlRegisterType<QniteCurve>(uri, 1, 0, "Curve");
  qmlRegisterType<QniteScaleMap>(uri, 1, 0, "ScaleMap");
  qmlRegisterUncreatableType<QniteTicker>(uri, 1, 0, "Ticker",
    "Cannot create objects of base type Ticker");
  qmlRegisterType<QniteLinearTicker>(uri, 1, 0, "LinearTicker");
}

