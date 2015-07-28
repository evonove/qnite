import QtQuick 2.4
import Qnite 1.0

/*! \qmltype Axes
    \inqmlmodule Qnite 0.1
    \ingroup figure

    \brief The container of all the axes and the ploy area

    TODO: add a long description
*/
BasicAxes {
    id: __plotarea

    /*! tick properties */
    AxisTick {
        id: __axistick
        thick: 1
        majSize: 10
        minSize: 3
        color: Qt.rgba(0,0,0,0.2)
    }
    property alias tick: __axistick

    TextMetrics {
        id: __metrics
        text: "99999"
    }
    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
        right: parent.right

        topMargin: __metrics.height / 2
        bottomMargin: __metrics.height + tick.majSize + 5
        leftMargin: __metrics.width + tick.majSize + 5
        rightMargin: __metrics.width / 2
    }

    function majorTicksChanged(axis, labelsitem) {
        var values = [];
        for(var i = 0, item; (item = axis.majorTicks[i]) !== undefined; i++) {
            values.push({
                "value": item,
                "label": (axis.ticker.majorTicks[i]).toString()
            });
        }

        labelsitem.major = values;
    }

    function minorTicksChanged(axis, labelsitem) {
        var values = [];
        for(var i = 0, item; (item = axis.minorTicks[i]) !== undefined; i++) {
            values.push({ "value": item });
        }

        labelsitem.minor = values;
    }

    axisY: LinearAxis {
        id: __left
        size: __plotarea.height
        flip: true

        onMajorTicksChanged: __plotarea.majorTicksChanged(__left, __leftlabels)
        onMinorTicksChanged: __plotarea.minorTicksChanged(__left, __leftlabels)
    }
    axisX: LinearAxis {
        id: __bottom
        size: __plotarea.width

        onMajorTicksChanged: __plotarea.majorTicksChanged(__bottom, __bottomlabels)
        onMinorTicksChanged: __plotarea.minorTicksChanged(__bottom, __bottomlabels)
    }


    // TODO: expose as a property so it is customizable
    Rectangle {
        id: background
        anchors.fill: parent
        color: "#FAFAFA"
        z: -1
    }

    Rectangle {
        id: bottombaseline
        implicitWidth: parent.width
        implicitHeight: tick.thick
        anchors.verticalCenter: parent.bottom
        anchors.alignWhenCentered: false
        color: tick.color
    }
    AxisLabel {
        id: __bottomlabels
        axisType: "bottom"
        width: __plotarea.width
        anchors.top: __plotarea.bottom
        anchors.left: __plotarea.left

        tick: __plotarea.tick
    }

    Rectangle {
        id: leftbaseline
        implicitWidth: tick.thick
        implicitHeight: parent.height
        anchors.horizontalCenter: parent.left
        anchors.alignWhenCentered: false
        color: tick.color
    }
    AxisLabel {
        id: __leftlabels
        axisType: "left"
        height: __plotarea.height
        anchors.bottom: __plotarea.bottom
        anchors.right: __plotarea.left

        tick: __plotarea.tick
    }
}
