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

            axes.yBounds: [-0.2, 0.65]
            axes.xBounds: [0.0001, 0.0006]

            //Grid { }
            Line {
                xValues: [0.0001, 0.00013, 0.0003, 0.0004, 0.00052]
                yValues: [0, 0.3, 0.6, 0.3, 0.4, 0.6]
                pen.stroke: "#3f51b5"
            }
        }
    }
}

