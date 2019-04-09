import QtQuick.Controls 2.0
import QtQuick 2.6
import Qnite 1.0

Figure {
    axes.yBounds: [2.5, 5.8]
    axes.xBounds: [0, 10]

    tools: [
        PathSelectionTool {
            anchors.fill: parent
        },
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
    Circle {
        id: circle
        selectable: true
        pen {
            fill: "#aa3f51b5"
            radius: 5
        }
        selectedPen {
            fill: "#aab01325"
            radius: 6
        }
    }

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
}
