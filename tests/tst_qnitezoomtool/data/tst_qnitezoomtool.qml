import QtQuick 2.4
import QtTest 1.0

import Qnite 1.0

TestCase {
    id: testCase
    width: 300
    height: 200
    when: windowShown
    name: "QniteZoomTool"
    visible: true

    Component {
        id: figure
        Figure {
            anchors.fill: parent
            axes.xBounds: [-0.5, 0.15]
            axes.yBounds: [-10, 0]

            tools: [
                ZoomTool {
                    id: zoomTool
                    objectName: "zoomTool"
                    anchors.fill: parent
                }
            ]
        }
    }

    // Verifies both axis bounds are updated when zooming the plot
    function test_zoom_bounds_update() {
        var fig = figure.createObject(testCase);
        var zoom = findChild(fig, "zoomTool");
        verify(zoom);

        // Verifies defaults
        compare(fig.axes.axisX.lowerBound, -0.5);
        compare(fig.axes.axisX.upperBound, 0.15);
        compare(fig.axes.axisY.lowerBound, -10);
        compare(fig.axes.axisY.upperBound, 0);
        compare(fig.axes.width, 258);
        compare(fig.axes.height, 140);
        compare(fig.width, 300);
        compare(fig.height, 200);

        // Zooms
        mouseDrag(zoom, 100, 50, 20, 10, Qt.RightButton);

        // Verifies bounds are correctly updated
        fuzzyCompare(fig.axes.axisX.lowerBound, -0.24, 0.01);
        fuzzyCompare(fig.axes.axisX.upperBound, -0.19, 0.01);
        fuzzyCompare(fig.axes.axisY.lowerBound, -4.28, 0.01);
        fuzzyCompare(fig.axes.axisY.upperBound, -3.57, 0.01);

        fig.destroy();
    }


    // Verifies reset changes zoom level correctly and reenables it if necessary
    function test_reset_zoom() {
        var fig = figure.createObject(testCase);
        var zoom = findChild(fig, "zoomTool");
        verify(zoom);

        // Verifies defaults
        compare(fig.axes.axisX.lowerBound, -0.5);
        compare(fig.axes.axisX.upperBound, 0.15);
        compare(fig.axes.axisY.lowerBound, -10);
        compare(fig.axes.axisY.upperBound, 0);
        compare(zoom.enabled, true);

        // Zooms
        mouseDrag(zoom, 100, 50, 20, 10, Qt.RightButton);

        // Verifies updated bounds
        fuzzyCompare(fig.axes.axisX.lowerBound, -0.24, 0.01);
        fuzzyCompare(fig.axes.axisX.upperBound, -0.19, 0.01);
        fuzzyCompare(fig.axes.axisY.lowerBound, -4.28, 0.01);
        fuzzyCompare(fig.axes.axisY.upperBound, -3.57, 0.01);
        compare(zoom.enabled, true);

        zoom.reset();

        // Verifies zoom is reset
        compare(fig.axes.axisX.lowerBound, -0.5);
        compare(fig.axes.axisX.upperBound, 0.15);
        compare(fig.axes.axisY.lowerBound, -10);
        compare(fig.axes.axisY.upperBound, 0);
        compare(zoom.enabled, true);

        // Zooms some times
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);

        // Verifies bounds are updated and tool is now disabled
        fuzzyCompare(fig.axes.axisX.lowerBound, -0.242766, 0.000001);
        fuzzyCompare(fig.axes.axisX.upperBound, -0.242761, 0.000001);
        fuzzyCompare(fig.axes.axisY.lowerBound, -7.407525, 0.000001);
        fuzzyCompare(fig.axes.axisY.upperBound, -7.407069, 0.000001);
        compare(zoom.enabled, false);

        zoom.reset();

        // Verifies zoom is reset
        compare(fig.axes.axisX.lowerBound, -0.5);
        compare(fig.axes.axisX.upperBound, 0.15);
        compare(fig.axes.axisY.lowerBound, -10);
        compare(fig.axes.axisY.upperBound, 0);
        compare(zoom.enabled, true);

        fig.destroy();
    }

    // Verifies plot doesn't zoom more than minimum zoom size calculated from
    // the current zoom factor
    function test_default_zoom_factor() {
        var fig = figure.createObject(testCase);
        var zoom = findChild(fig, "zoomTool");
        verify(zoom);

        // Verifies defaults
        compare(fig.axes.axisX.lowerBound, -0.5);
        compare(fig.axes.axisX.upperBound, 0.15);
        compare(fig.axes.axisY.lowerBound, -10);
        compare(fig.axes.axisY.upperBound, 0);
        compare(zoom.minZoomFactor, 4);
        compare(zoom.enabled, true);

        // Zooms some times
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);

        // Verifies bounds are updated and tool is now disabled
        fuzzyCompare(fig.axes.axisX.lowerBound, -0.242766, 0.000001);
        fuzzyCompare(fig.axes.axisX.upperBound, -0.242761, 0.000001);
        fuzzyCompare(fig.axes.axisY.lowerBound, -7.407525, 0.000001);
        fuzzyCompare(fig.axes.axisY.upperBound, -7.407069, 0.000001);
        compare(zoom.enabled, false);

        // Zooms some more
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);

        // Verifies bound are unchanged
        fuzzyCompare(fig.axes.axisX.lowerBound, -0.242766, 0.000001);
        fuzzyCompare(fig.axes.axisX.upperBound, -0.242761, 0.000001);
        fuzzyCompare(fig.axes.axisY.lowerBound, -7.407525, 0.000001);
        fuzzyCompare(fig.axes.axisY.upperBound, -7.407069, 0.000001);
        compare(zoom.enabled, false);

        // Increments default zoom factor
        zoom.minZoomFactor = 5;

        // Verifies zoom is enabled again
        compare(zoom.enabled, true);

        // Zooms again
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);
        mouseDrag(zoom, 100, 100, 5, 5, Qt.RightButton);

        // Verifies bounds are now changed and new minimum zoom is reached
        fuzzyCompare(fig.axes.axisX.lowerBound, -0.242763, 0.000001);
        fuzzyCompare(fig.axes.axisX.upperBound, -0.242763, 0.000001);
        fuzzyCompare(fig.axes.axisY.lowerBound, -7.407411, 0.000001);
        fuzzyCompare(fig.axes.axisY.upperBound, -7.407395, 0.000001);
        compare(zoom.enabled, false);

        fig.destroy();
    }
}
