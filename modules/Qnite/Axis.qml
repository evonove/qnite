import QtQuick 2.4
import Qnite 1.0

BasicAxis {
    id: axis

    property string axisType

    property var major;
    property var minor;

    onMajorTicksChanged: {
        var values = [];
        for(var i = 0; i < majorTicks.length; ++i) {
            values.push({
                "value": majorTicks[i],
                "label": ticker.majorTicks[i]
            });
        }

        major = values;
    }

    onMinorTicksChanged: {
        var values = [];
        for(var i = 0; i < minorTicks.length; ++i) {
            values.push({
                "value": minorTicks[i],
            });
        }

        minor = values;
    }

    Item {
        id: ticksnlabels
        anchors.fill: parent

        Repeater {
            model: axis.major
            Loader {
                property real val: modelData.value
                property string label: modelData.label
                property real size: tick.majSize

                anchors {
                    right: axis.axisType === "left" ? ticksnlabels.right : undefined
                    rightMargin: axis.axisType === "left" ? tick.thick / 2 : 0
                }
                sourceComponent: axis.axisType === "left" ? leftTick : bottomTick
            }
        }

        Repeater {
            model: axis.minor
            Loader {
                property real val: modelData.value
                property string label: ""
                property real size: tick.minSize

                anchors {
                    right: axis.axisType === "left" ? ticksnlabels.right : undefined
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

            Text {
                id: __text
                anchors.verticalCenter: __tick.verticalCenter
                text: label
            }

            Rectangle {
                id: __tick
                implicitWidth: size
                implicitHeight: tick.thick

                color: tick.color
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
                implicitHeight: size

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
