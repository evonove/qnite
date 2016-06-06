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

            tools: [
                PointSelectionTool {
                    anchors.fill: parent // TODO: remove boilerplate
                }
            ]

            axes.yBounds: [-2, 10.8]
            axes.xBounds: [-5, 10]

            Spline {
                id: spline
                selectable: true
                xValues: [-4.8, -2, .5, 2, 3, 4,  8, 10]
                yValues: [   3,  1, -2, 6, 3, 4, 10, 4]
                anchors.fill: parent
                pen {
                    stroke: "#345f6b"
                    fill: "#aa345f6b"
                }
                selectedPen {
                    stroke: "#22ff22"
                    fill: "#aa345f6b"
                }
            }
            Circle {
                xValues: [-4.8, -2, .5, 2, 3, 4,  8, 10]
                yValues: [   3,  1, -2, 6, 3, 4, 10, 4]
                pen {
                    stroke: spline.selected ? spline.selectedPen.stroke : spline.pen.stroke
                    fill: spline.selected ? spline.selectedPen.fill : spline.pen.fill
                }
            }

            Spline {
                id: spline2
                selectable: true
                xValues: [-3.8, -1, 1.5, 3, 4, 5,  9, 11]
                yValues: [   4,  2, -1, 7, 4, 5, 11, 5]
                anchors.fill: parent
                pen {
                    stroke: "#b01327"
                    fill: "#aab01327"
                }
                selectedPen {
                    stroke: "#22ff22"
                    fill: "#aab01327"
                }
            }
            Circle {
                xValues: [-3.8, -1, 1.5, 3, 4, 5,  9, 11]
                yValues: [   4,  2, -1, 7, 4, 5, 11, 5]
                pen {
                    stroke: spline2.selected ? spline2.selectedPen.stroke : spline2.pen.stroke
                    fill: "#e75868"
                }
            }
        }
    }
}
