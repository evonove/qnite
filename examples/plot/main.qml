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

            axisBottom.color: "green"
            axisLeft.thickness: 2

            Curve {
              xValues: [1, 3, 5, 6]
              anchors.fill: parent
              color: "blue"

              scaleMap: ScaleMap {
                min: 0
                max: 10

                size: 200
              }
            }
        }
    }
}

