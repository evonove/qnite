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

            Component.onCompleted: {
                var n = 100000;
                var xx = [];
                var yy = [];
                for (var i = 0; i < n; ++i) {
                    xx.push(Math.random() * 10);
                    yy.push(Math.random() * 10);
                }
                circle.xValues = xx;
                circle.yValues = yy;
            }
            axes.leftBounds: [0, 10]
            axes.bottomBounds: [0, 10]

            Curve {
                xValues: [0, 1, 3, 5, 6, 10]
                yValues: [0, 3, 6, 3, 4, 10]
                anchors.fill: parent
                color: "#3f51b5"
            }
            Circle {
                id: circle
                //xValues: [0, 1, 3, 5, 6, 10]
                //yValues: [0, 3, 6, 3, 4, 10]
                anchors.fill: parent
                radius: 2
                color: "#3f51b5"
            }
        }
    }
}

