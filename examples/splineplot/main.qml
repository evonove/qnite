import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
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

            axes.leftBounds: [-2, 10.8]
            axes.bottomBounds: [-5, 10]

            Grid { }
            Spline {
                id: spline
                xValues: [-4.8, -2, .5, 2, 3, 4,  8, 10]
                yValues: [   3,  1, -2, 6, 3, 4, 10, 4]
                color: "#345f6b"
            }
        }

        Item {
            anchors {
                left: parent.left
                top: parent.top
                margins: 20
            }
            width: __layout.implicitWidth + 20
            height: __layout.implicitHeight + 20

            Rectangle {
                anchors.fill: parent
                radius: height / 4
                color: "white"
                opacity: 0.8
            }

            RowLayout {
                id: __layout
                anchors {
                    centerIn: parent
                }

                ExclusiveGroup { id: tabPositionGroup }
                RadioButton {
                    text: "Cubic"
                    checked: true
                    exclusiveGroup: tabPositionGroup
                    onClicked: spline.interpolation = Spline.Cubic
                }
                RadioButton {
                    text: "CatmullRom"
                    exclusiveGroup: tabPositionGroup
                    onClicked: spline.interpolation = Spline.CatmullRom
                }
                RadioButton {
                    text: "Cosine"
                    exclusiveGroup: tabPositionGroup
                    onClicked: spline.interpolation = Spline.Cosine
                }
            }
        }
    }
}

