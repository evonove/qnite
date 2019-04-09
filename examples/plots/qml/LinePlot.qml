import QtQuick.Controls 2.0
import Qnite 1.0

Figure {
    axes.yBounds: [-0.2, 0.65]
    axes.xBounds: [0.0001, 0.0006]

    tools: [
        ZoomTool {
            id: zoom
            anchors.fill: parent
        }
    ]

    Grid {
        Button {
            anchors.top: parent.top
            anchors.right: parent.right

            text: "Reset Zoom"

            onClicked: zoom.reset()
        }
    }
    Line {
        xValues: [0.0001, 0.00013, 0.0003, 0.0004, 0.00052]
        yValues: [0, 0.3, 0.6, 0.3, 0.4, 0.6]
        pen.stroke: "#3f51b5"
    }
}
