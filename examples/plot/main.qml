import QtQuick 2.4
import QtQuick.Controls 1.3

ApplicationWindow {
    width: 640; height: 480
    visible: true

    Plot {
        width: 200; height: 200
        series: [1, 2, 3, 4]

        xAxis: Axis {
        }

        yAxis: Axis {
        }
    }
}

