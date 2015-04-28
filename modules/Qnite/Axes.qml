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

    Rectangle {
        anchors.fill: parent
        color: "#FAFAFA"
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

    // TODO: move this hardcode grid artist to c++
    Item {
        id: grid

        Repeater {
            model: __left.majorTicks.length
            Rectangle {
                Binding on y {
                    // align the center of the tick with the data value
                    value: __left.majorTicks[index] - __left.tick.thick / 2
                }

                implicitWidth: __plotarea.width
                implicitHeight: __left.tick.thick
                color: __left.tick.color
            }
        }

        Repeater {
            model: __bottom.majorTicks.length
            Rectangle {
                Binding on x {
                    // align the center of the tick with the data value
                    value: __bottom.majorTicks[index] - __bottom.tick.thick / 2
                }

                implicitWidth: __bottom.tick.thick
                implicitHeight: __plotarea.height
                color: __bottom.tick.color
            }
        }
    }
}
