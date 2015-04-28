import QtQuick 2.4
import Qnite 1.0

/*! \qmltype Grid
    \inqmlmodule Qnite 0.1
    \ingroup artists

    TODO: add description
*/
Artist {
    id: grid

    property real xSize: axes.bottomAxis.tick.thick
    property real ySize: axes.leftAxis.tick.thick

    property color xColor: axes.bottomAxis.tick.color
    property color yColor: axes.leftAxis.tick.color

    xValues: axes.bottomAxis.majorTicks
    yValues: axes.leftAxis.majorTicks

    Repeater {
        model: grid.yValues.length
        Rectangle {
            Binding on y {
                // align the center of the tick with the data value
                value: grid.yValues[index] - grid.ySize / 2
            }

            implicitWidth: grid.width
            implicitHeight: grid.ySize
            color: grid.yColor
        }
    }

    Repeater {
        model: grid.xValues.length
        Rectangle {
            Binding on x {
                // align the center of the tick with the data value
                value: grid.xValues[index] - grid.xSize / 2
            }

            implicitWidth: grid.xSize
            implicitHeight: grid.height
            color: grid.xColor
        }
    }
}
