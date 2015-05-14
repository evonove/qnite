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
                var n = 100;
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

            tools: [
                // TODO: add concrete tools when available
            ]

            Grid {
                anchors.fill: parent
            }
            Circle {
                id: circle
                anchors.fill: parent
                radius: 5
                color: "#aa3f51b5"
            }
        }
    }
}

