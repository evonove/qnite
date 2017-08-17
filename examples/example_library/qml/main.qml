import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

import Qnite 1.0


Window {
    width: 1600; height: 900
    visible: true

    GridLayout {
        columns: 2
        columnSpacing: 10
        rowSpacing: 10

        anchors{
            fill: parent
            margins: 10
        }

        // bar plot
        BarPlot {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        // filled curves
        LinePlot {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        SplinePlot {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        ScatterPlot {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}

