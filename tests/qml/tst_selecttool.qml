import QtQuick 2.4
import QtTest 1.0

Item {
    id: container
    width: 300; height: 300

    TestCase {
        id: testCase
        name: "Test_SelectTool"
        when: windowShown

        function test_selection() {
            var tmp = Qt.createQmlObject(
                'import Qnite 1.0; PathSelectionTool {id: selectTool; width: 300; height: 300}',
                container, '');

            mousePress(tmp);
            mouseMove(tmp, 1, 1);

            compare(tmp.selectionPath.length, 2);
            compare(tmp.selectionPath, [Qt.point(0,0), Qt.point(0,1)]);

            mouseRelease(tmp);
            compare(tmp.selectionPath.length, 0);

            tmp.destroy();
        }
    }
}
