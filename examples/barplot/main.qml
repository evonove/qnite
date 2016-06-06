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

            axes.axisX: CategoryAxis {
                values: ["a", "b", "c", "d"]
            }
            axes.yBounds: [-10, 10]

            tools: [
                PointSelectionTool {
                    anchors.fill: parent // TODO: remove boilerplate
                }
            ]

            Grid { }
            Bar {
                categories: ["a", "b", "c", "e"]
                yValues: [-9, 3, 5, -1]

                pen.fill: "red"
                selectionColor: "green"
                selectable: true
            }
        }
    }
}

