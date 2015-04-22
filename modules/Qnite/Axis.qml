import QtQuick 2.4
import Qnite 1.0

BasicAxis {
    id: axis

    property string axisType

    QtObject {
      id: ticker
      property int numMajTicks: 11

      property var values: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    }

    Item {
        id: ticksnlabels
        anchors.fill: parent

        Repeater {
            model: ticker.numMajTicks
            Rectangle {
                implicitWidth: axis.axisType === "bottom" ? tick.thick : tick.majSize
                implicitHeight: axis.axisType === "left" ? tick.thick : tick.majSize
                anchors.right: axis.axisType === "left" ? parent.right : undefined

                Binding on x {
                  when: axis.axisType === "bottom"
                  value: mapper.factor * ticker.values[index] - tick.thick / 2
                }

                Binding on y {
                  when: axis.axisType === "left"
                  value: axis.height - (mapper.factor * ticker.values[index] + tick.thick / 2)
                }

                color: tick.color
            }
        }
    }
}
