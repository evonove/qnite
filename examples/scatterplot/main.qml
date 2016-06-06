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
                    xx.push(Math.random() * 40);
                    yy.push(Math.random() * 40);
                }
                circle.xValues = xx;
                circle.yValues = yy;
            }

            axes.yBounds: [2.5, 5.8]
            axes.xBounds: [0, 10]

            //Grid { }
            Circle {
                id: circle
                radius: 5
                pen.fill: "#aa3f51b5"
            }
        }
    }
}

