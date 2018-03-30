import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

import Qnite 1.0


ApplicationWindow {
    width: 1600; height: 900
    visible: true

    ColumnLayout {
        anchors.fill: parent

        CheckBox {
            id: _drawSymbols
            text: "Draw Symbols"
        }

        Figure {
            axes.yBounds: [-0.2, 0.65]
            axes.xBounds: [0.0001, 0.0006]

            Grid { }
            Line {
                xValues: [0.0001, 0.00013, 0.0003, 0.0004, 0.00052]
                yValues: [0, 0.3, 0.6, 0.3, 0.4, 0.6]

                drawSymbols: _drawSymbols.checked
            }

            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}

