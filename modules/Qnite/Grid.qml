import QtQuick 2.4
import Qnite 1.0

/*! \qmltype Grid
    \inqmlmodule Qnite 0.1
    \ingroup artists

    TODO: add description
*/
XYArtist {
    id: grid

    property real xSize: axes ? axes.axisX.tick.thick : 0
    property real ySize: axes ? axes.axisY.tick.thick : 0

    property color xColor: axes ? axes.axisX.tick.color : "black"
    property color yColor: axes ? axes.axisY.tick.color : "black"

    xValues: axes ? axes.axisX.majorTicks : []
    yValues: axes ? axes.axisY.majorTicks : []

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
