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

            axes.leftBounds: [-0.1, 0.65]
            axes.bottomBounds: [0, 0.125]

            Grid { }
            Line {
                xValues: [0, 0.01, 0.03, 0.05, 0.06, 0.12]
                yValues: [0, 0.3, 0.6, 0.3, 0.4, 0.6]
                color: "#3f51b5"
            }
        }
    }
}

