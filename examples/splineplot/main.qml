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

            axes.leftBounds: [-2, 10.8]
            axes.bottomBounds: [-5, 10]

            Grid { }
            Spline {
                xValues: [-4.8, -2, .5, 2, 3, 4,  8, 10]
                yValues: [   3,  1, -2, 6, 3, 4, 10, 4]
                color: "#345f6b"
            }
            Circle {
                xValues: spline.xValues
                yValues: spline.yValues
                color: "#3f51b5"
            }
        }
    }
}

