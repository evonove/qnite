import QtQuick 2.4
import Qnite 1.0

/*! \qmltype Figure
    \inqmlmodule Qnite 0.1
    \ingroup figure

    \brief The container of all the plot items.

    TODO: add a long description

    \qml

    // TODO: add a code example

    \endqml
*/
FocusScope {
    id: plot

    /*! \qmlproperty string Figure::title

        The title of the plot.
    */
    property string title

    /*! \qmlproperty Axis Figure::axisLeft

        The y-axis placed on the left of the plot.
    */
    property alias axisLeft: yLeft

    /*! \qmlproperty Axis Figure::axisBottom

        The x-axis placed at the bottom of the plot.
    */
    property alias axisBottom: xBottom


    default property alias data: plotArea.data

    property real xMin: 0
    property real xMax: 10

    property real yMin: 0
    property real yMax: 10

    property real step: 1.0

    QtObject {
        id: scaleEngine

        // data space dimension
        property real __dimX: plot.xMax - plot.xMin
        property real __dimY: plot.yMax - plot.yMin

        property real xSteps: __dimX / plot.step
        property real ySteps: __dimY / plot.step

        // following values are the factors needed to transfor a point
        // from data space to coordinates space
        property real __xFactor: plotArea.width / __dimX
        property real __yFactor: plotArea.height / __dimY

        property real xstep: plot.step * __xFactor
        property real ystep: plot.step * __yFactor

    }

    Item {
        id: plotArea
        anchors.fill: parent
        anchors.margins: 50

        Rectangle {
            anchors.fill: parent
            color: "#FAFAFA"
        }

        //Rectangle {
            //width: parent.width; height: 20
            //color: "#11000000"
            //anchors.verticalCenter: parent.bottom
        //}
    }

    Axis {
        id: yLeft
        width: 30; height: plotArea.height
        anchors.top: plotArea.top
        anchors.right: plotArea.left

        axisType: "left"
        scaleEngine: scaleEngine
        //visible: false
    }

    Axis {
        id: xBottom
        width: plotArea.width; height: 30
        anchors.top: plotArea.bottom
        anchors.left: plotArea.left

        axisType: "bottom"
        scaleEngine: scaleEngine
        //visible: false
    }
}
