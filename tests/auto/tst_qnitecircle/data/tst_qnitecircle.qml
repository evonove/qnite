import QtQuick 2.6
import QtTest 1.1

import Qnite 1.0

TestCase {
    id: testCase
    width: 300; height: 300
    visible: true
    when: windowShown
    name: "QniteCircle"

    Component {
        id: figure

        // Plot
        Figure {
            axes.yBounds: [0, 10]
            axes.xBounds: [0, 10]

            tools: [
                PointSelectionTool {
                    anchors.fill: parent
                }
            ]

            Circle {
                id: __circle
                objectName: "__circle"

                radius: 6
                selectable: true
                pen.fill: "#aa90caf9"
                selectedPen.fill: "#ef5350"
                highlightedPen.fill: "#53ef50"

                // Displayed values
                xValues: [1, 2, 3, 4, 5, 6, 7, 8]
                yValues: [1, 2, 3, 4, 5, 6, 7, 8]
            }
        }
    }

    // Tests selection of multiple plotted points
    function test_select_circle() {
        var fig = figure.createObject(testCase);
        var circle = findChild(fig, '__circle');

        // Does some operations on the circle dataset
        circle.processData();

        // Check that nothing is selected
        compare(circle.selectedIndexes, []);

        // Selects points at indexes 1, 2 and 3
        circle.select([1, 2, 3]);

        // Check selectedIndexes length and if it contains
        // the right indexes
        compare(circle.selectedIndexes.length, 3);
        verify(circle.selectedIndexes.indexOf(1) !== -1);
        verify(circle.selectedIndexes.indexOf(2) !== -1);
        verify(circle.selectedIndexes.indexOf(3) !== -1);
    }

    // Tests highlighting of a single plotted point
    function test_highlight_circle() {
        var fig = figure.createObject(testCase);
        var circle = findChild(fig, '__circle');

        // Does some operations on the circle dataset
        circle.processData();

        // Check that nothing is highlighted
        compare(circle.highlightedIndex, -1);

        // Highlights point at index 5
        circle.highlight(5);

        // Check if points has been highlighted
        compare(circle.highlightedIndex, 5);
    }

    // Test the deselection of selected and highlighted points
    function test_clear_selection() {
        var fig = figure.createObject(testCase);
        var circle = findChild(fig, '__circle');

        // Does some operations on the circle dataset
        circle.processData();

        // Check that no point is selected or highlighted
        compare(circle.selectedIndexes, []);
        compare(circle.highlightedIndex, -1);

        // Selects points at indexes 1, 2 and 3
        // and highlights point at index 5
        circle.select([1, 2, 3]);
        circle.highlight(5);

        // Check if points have been selected and highlighted
        compare(circle.selectedIndexes.length, 3);
        verify(circle.selectedIndexes.indexOf(1) !== -1);
        verify(circle.selectedIndexes.indexOf(2) !== -1);
        verify(circle.selectedIndexes.indexOf(3) !== -1);
        compare(circle.highlightedIndex, 5);

        // Clears selection and highlighting
        circle.clearSelection();

        // Check that no point is selected or highlighted
        compare(circle.selectedIndexes, []);
        compare(circle.highlightedIndex, -1);
    }
}
