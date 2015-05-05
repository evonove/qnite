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
        size: __plotarea.width
        axisType: "bottom"

        tick {
            thick: 1
            majSize: 10
            midSize: 8
            minSize: 5
            color: Qt.rgba(0,0,0,0.2)
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
        size: __plotarea.height
        flip: true

        tick {
            thick: 1
            majSize: 10
            color: Qt.rgba(0,0,0,0.2)
        }
    }
}
