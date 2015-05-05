import QtQuick 2.4
import Qnite 1.0

BasicAxis {
    id: axis

    property string axisType

    Item {
        id: ticksnlabels
        anchors.fill: parent

        Repeater {
            model: axis.majorTicks.length
            Loader {
                property real val: axis.majorTicks[index]
                property string label: axis.ticker.majorTicks[index]

                anchors {
                    right: axis.axisType === "left" ? parent.right : undefined
                    rightMargin: axis.axisType === "left" ? tick.thick / 2 : 0
                }
                sourceComponent: axis.axisType === "left" ? leftTick : bottomTick
            }
        }
    }

    Component {
        id: leftTick
        Row {
            spacing: 5

            Binding on y {
                // align the center of the tick with the data value
                value: val - tick.thick / 2
            }

            Rectangle {
                id: __tick
                implicitWidth: tick.majSize
                implicitHeight: tick.thick

                color: tick.color
            }

            Text {
                id: __text
                anchors.verticalCenter: __tick.verticalCenter
                text: label
            }
        }
    }

    Component {
        id: bottomTick
        Column {
            spacing: 5

            Binding on x {
                // align the center of the tick with the data value
                value: val - tick.thick / 2
            }

            Rectangle {
                id: __tick
                implicitWidth: tick.thick
                implicitHeight: tick.majSize

                color: tick.color
            }

            Text {
                id: __text
                anchors.horizontalCenter: __tick.horizontalCenter
                text: label
            }
        }
    }
}
