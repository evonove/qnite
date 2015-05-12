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

            axes.leftBounds: [0.5, 1.8]
            axes.bottomBounds: [0, 2.0]


            Line {
                xValues: [0, 0.1, 0.3, 0.5, 0.6, 1.0]
                yValues: [0, 0.3, 0.6, 0.3, 0.4, 1.0]
                anchors.fill: parent
                color: "#3f51b5"
            }
        }
    }
}

