import QtQuick 2.4
import Qnite 1.0

/*! \qmltype Axes
    \inqmlmodule Qnite 0.1
    \ingroup figure

    \brief The container of all the axes and the ploy area

    TODO: add a long description
*/
BasicAxes {
    id: __plotarea
    anchors.fill: parent
    anchors.margins: 50

    leftAxis: __left
    bottomAxis: __bottom

    // TODO: expose as a property so it is customizable
    Rectangle {
        id: background
        anchors.fill: parent
        color: "#FAFAFA"
        z: -1
    }

    Rectangle {
        id: bottombaseline
        implicitWidth: parent.width
        implicitHeight: __bottom.tick.thick
        anchors.verticalCenter: parent.bottom
        anchors.alignWhenCentered: false
        color: __bottom.tick.color
    }
    Axis {
        id: __bottom
        width: __plotarea.width; height: 30
        anchors.top: __plotarea.bottom
        anchors.left: __plotarea.left

        tick {
            thick: 1
            majSize: 10
            color: Qt.rgba(0,0,0,0.2)
        }
        axisType: "bottom"
        mapper {
            size: __plotarea.width
            // TODO: move this assignement to C++ layer
            min: __bottom.lowerBound; max: __bottom.upperBound
        }
    }

    Rectangle {
        id: leftbaseline
        implicitWidth: __left.tick.thick
        implicitHeight: parent.height
        anchors.horizontalCenter: parent.left
        anchors.alignWhenCentered: false
        color: __left.tick.color
    }
    Axis {
        id: __left
        width: 30; height: __plotarea.height
        anchors.bottom: __plotarea.bottom
        anchors.right: __plotarea.left
        axisType: "left"

        tick {
            thick: 1
            majSize: 10
            color: Qt.rgba(0,0,0,0.2)
        }

        mapper {
            size: __plotarea.height
            // TODO: move this assignement to C++ layer
            min: __left.lowerBound; max: __left.upperBound
            flip: true
        }
    }
}
