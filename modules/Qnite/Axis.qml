import QtQuick 2.4

Item {
    id: axis

    property real thickness: 1

    property real majorTickSize: 10

    property color color

    property var scaleEngine

    property string axisType

    Rectangle {
        id: baseline
        implicitWidth: axis.axisType === "bottom" ? parent.width : axis.thickness
        implicitHeight: axis.axisType === "left" ? parent.height : axis.thickness

        anchors.right: axis.axisType === "left" ? parent.right : undefined
        color: axis.color
    }
    Item {
        id: ticksnlabels
        anchors.fill: parent

        Repeater {
            model: scaleEngine.xSteps
            Rectangle {
                implicitWidth: axis.axisType === "bottom" ? axis.thickness : axis.majorTickSize
                implicitHeight: axis.axisType === "left" ? axis.thickness : axis.majorTickSize
                anchors.right: axis.axisType === "left" ? parent.right : undefined

                // FIXME: subtracting width to align the first tick. find something reliable
                x: axis.axisType === "bottom" ? model.index * scaleEngine.xstep - width : 0
                y: axis.axisType === "left" ? axis.height - model.index * scaleEngine.ystep : 0
                color: axis.color
            }
        }
    }
}
