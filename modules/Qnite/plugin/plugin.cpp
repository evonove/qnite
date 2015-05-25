#include "plugin.h"

#include "qniteartist.h"
#include "qnitexyartist.h"
#include "qniteaxis.h"
#include "qniteaxes.h"
#include "qnitecircle.h"
#include "qniteline.h"
#include "qnitespline.h"
#include "qnitemapper.h"
#include "qnitelinearmapper.h"
#include "qniteticker.h"
#include "qnitelinearticker.h"
#include "qnitetool.h"
#include "qnitepathselectiontool.h"

#include <QtQml>

void QnitePlugin::registerTypes(const char *uri)
{
  // @uri qnite
  qmlRegisterUncreatableType<QniteArtist>(uri, 1, 0, "Artist", "Cannot create objects of basetype Artist");
  qmlRegisterType<QniteXYArtist>(uri, 1, 0, "XYArtist");
  qmlRegisterType<QniteAxes>(uri, 1, 0, "BasicAxes");
  qmlRegisterType<QniteAxis>(uri, 1, 0, "BasicAxis");
  qmlRegisterType<QniteAxisTick>(uri, 1, 0, "AxisTick");
  qmlRegisterType<QniteCircle>(uri, 1, 0, "Circle");
  qmlRegisterType<QniteLine>(uri, 1, 0, "Line");
  qmlRegisterType<QniteSpline>(uri, 1, 0, "Spline");

  qmlRegisterUncreatableType<QniteTool>(uri, 1, 0, "Tool", "Cannot create objects of basetype Tool");
  qmlRegisterType<QnitePathSelectionTool>(uri, 1, 0, "PathSelectionTool");

  qmlRegisterUncreatableType<QniteMapper>(uri, 1, 0, "Mapper", "Cannot create objects of basetype Mapper");
  qmlRegisterType<QniteLinearMapper>(uri, 1, 0, "LinearMapper");
  qmlRegisterUncreatableType<QniteTicker>(uri, 1, 0, "Ticker", "Cannot create objects of base type Ticker");
  qmlRegisterType<QniteLinearTicker>(uri, 1, 0, "LinearTicker");
}

