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

            axes.bottomBounds: [0, 10]
            axes.leftBounds: [-10, 10]

            Grid {
            }
            Bar {
                xValues: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
                yValues: [-9, -6, -5, -1, 2, 5, 4, 3, 7, 8.4]

                color: "red"
            }
        }
    }
}

