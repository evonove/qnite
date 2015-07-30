import QtQuick 2.4
import QtQuick.Controls 1.3
import Qnite 1.0

ApplicationWindow {
    width: 640; height: 480
    visible: true

    Rectangle {
        anchors.fill: parent
        color: "white"

        Figure {
            id: figure
            anchors.fill: parent

            tools: [
                PointSelectionTool {
                    anchors.fill: parent // TODO: remove boilerplate
                }
            ]

            Grid { }

            axes.yBounds: [-2, 10.8]
            axes.xBounds: [-5, 10]

            Spline {
                id: spline
                selectable: true
                xValues: [-4.8, -2, .5, 2, 3, 4,  8, 10]
                yValues: [   3,  1, -2, 6, 3, 4, 10, 4]
                anchors.fill: parent
                color: "#345f6b"
                selectionColor: "#22ff22"
                fill: true
                fillColor: "#aa345f6b"
                lineWidth: 5
            }

            Spline {
                id: spline2
                selectable: true
                xValues: [-3.8, -1, 1.5, 3, 4, 5,  9, 11]
                yValues: [   4,  2, -1, 7, 4, 5, 11, 5]
                anchors.fill: parent
                color: "#b01327"
                selectionColor: "#22ff22"
                fill: true
                fillColor: "#aab01327"
            }
        }
    }
}
