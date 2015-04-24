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

            axes.leftBounds: [0, 10]
            axes.bottomBounds: [0, 10]

            Curve {
              xValues: [0, 1, 3, 5, 6, 10]
              yValues: [0, 2, 6, 3, 4, 10]
              anchors.fill: parent
              color: "blue"
            }
        }
    }
}

