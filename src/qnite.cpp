#include "qniteartist.h"
#include "qnitexyartist.h"
#include "qniteaxis.h"
#include "qnitelinearaxis.h"
#include "qnitecategoryaxis.h"
#include "qniteaxistick.h"
#include "qniteaxes.h"
#include "qnitebar.h"
#include "qnitecircle.h"
#include "qniteline.h"
#include "qnitespline.h"
#include "qnitegrid.h"
#include "qnitemapper.h"
#include "qnitelinearmapper.h"
#include "qniteticker.h"
#include "qnitelinearticker.h"
#include "qnitetool.h"
#include "qnitepointselectiontool.h"
#include "qnitepathselectiontool.h"
#include "qnitepen.h"

#include <QtQml>

class Qnite
{
public:
    Qnite() {
        auto uri = "Qnite";

        // @uri qnite
        qmlRegisterUncreatableType<QniteArtist>(uri, 1, 0, "Artist", "Cannot create objects of basetype Artist");
        qmlRegisterType<QniteXYArtist>(uri, 1, 0, "XYArtist");
        qmlRegisterType<QniteAxes>(uri, 1, 0, "BasicAxes");
        qmlRegisterUncreatableType<QniteAxis>(uri, 1, 0, "Axis", "Cannot create obects of base type Axis");
        qmlRegisterType<QniteLinearAxis>(uri, 1, 0, "LinearAxis");
        qmlRegisterType<QniteCategoryAxis>(uri, 1, 0, "CategoryAxis");
        qmlRegisterType<QniteAxisTick>(uri, 1, 0, "AxisTick");
        qmlRegisterUncreatableType<QnitePen>(uri, 1, 0, "Pen", "Cannot create obects of type Pen");
        qmlRegisterType<QniteBar>(uri, 1, 0, "Bar");
        qmlRegisterType<QniteCircle>(uri, 1, 0, "Circle");
        qmlRegisterType<QniteLine>(uri, 1, 0, "Line");
        qmlRegisterType<QniteSpline>(uri, 1, 0, "Spline");
        qmlRegisterType<QniteGrid>(uri, 1, 0, "Grid");

        qmlRegisterUncreatableType<QniteTool>(uri, 1, 0, "Tool", "Cannot create objects of basetype Tool");
        qmlRegisterType<QnitePointSelectionTool>(uri, 1, 0, "PointSelectionTool");
        qmlRegisterType<QnitePathSelectionTool>(uri, 1, 0, "PathSelectionTool");

        qmlRegisterUncreatableType<QniteMapper>(uri, 1, 0, "Mapper", "Cannot create objects of basetype Mapper");
        qmlRegisterType<QniteLinearMapper>(uri, 1, 0, "LinearMapper");
        qmlRegisterUncreatableType<QniteTicker>(uri, 1, 0, "Ticker", "Cannot create objects of base type Ticker");
        qmlRegisterType<QniteLinearTicker>(uri, 1, 0, "LinearTicker");
    }
};

static Qnite registerTypes;
