import QtQuick 2.4
import QtTest 1.0

import Qnite 1.0

TestCase {
    id: testCase
    width: 300; height: 300
    visible: true
    when: windowShown
    name: "QnitePathSelectionTool"

    Component {
        id: pathSelectionTool
        PathSelectionTool {
            anchors.fill: parent
        }
    }

    function test_selection() {
        var selectionTool = pathSelectionTool.createObject(testCase);

        mousePress(selectionTool, 0, 0);
        mouseMove(selectionTool, 0, 1);

        compare(selectionTool.selectionPath.length, 2);
        compare(selectionTool.selectionPath, [Qt.point(0,0), Qt.point(0,1)]);

        mouseRelease(selectionTool);
        compare(selectionTool.selectionPath.length, 0);

        selectionTool.destroy();
    }
}
