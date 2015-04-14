import QtQuick 2.4
import Qnite 1.0


FocusScope {
    id: plot
    property string title

    property real xMin: 0
    property real xMax: 10

    property real yMin: 0
    property real yMax: 10

    property real step: 1.0

    QtObject {
        id: scaleEngine

        // data space dimension
        property real __dimX: plot.xMax - plot.xMin
        property real __dimY: plot.yMax - plot.yMin

        property real xSteps: __dimX / plot.step
        property real ySteps: __dimY / plot.step

        // following values are the factors needed to transfor a point
        // from data space to coordinates space
        property real __xFactor: plotArea.width / __dimX
        property real __yFactor: plotArea.height / __dimY

        property real xstep: plot.step * __xFactor
        property real ystep: plot.step * __yFactor

        Component.onCompleted: {
            console.debug(__dimX, __dimY, xSteps, ySteps,
                          __xFactor, __yFactor, xstep, ystep);
        }
    }

    Item {
        id: plotArea
        anchors.fill: parent
        anchors.margins: 50

        Rectangle {
            anchors.fill: parent
            color: "#FAFAFA"
        }
    }

    Axis {
        id: yLeft

        width: 30; height: plotArea.height
        anchors.top: plotArea.top
        anchors.right: plotArea.left

        axisType: "left"
        scaleEngine: scaleEngine
    }

    Axis {
        id: xBottom
        width: plotArea.width; height: 30
        anchors.top: plotArea.bottom
        anchors.left: plotArea.left

        axisType: "bottom"
        scaleEngine: scaleEngine
    }
}
