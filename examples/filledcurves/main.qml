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

            axes.xBounds: [-5, 10]
            axes.yBounds: [-2, 10.8]

            Grid {
            }
            Line {
                xValues: [-2, -1, 1, 3, 5, 6, 10]
                yValues: [-2, 1, 3, 6, 3, 4, 10]
                fill: true
                fillColor: "#99e8eaf6"
                color: "#3f51b5"
            }
            Spline {
                xValues: [-5, -1.5, -0.1, .4, 2.3, 3.4, 5, 6, 9, 10]
                yValues: [-3, 0, 2, -1.3, .9, -.2, -.6, 4, 5, 9]
                fill: true
                fillColor: "#99ec407a"
                color: "#3f51b5"
            }
        }
    }
}

