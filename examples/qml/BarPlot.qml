import Qnite 1.0

Figure {
    axes.axisX: CategoryAxis {
        values: ["a", "b", "c", "d"]
    }
    axes.yBounds: [-10, 10]

    axes.yAxisName: "Y"
    axes.xAxisName: "X"

    tools: [
        PointSelectionTool {
            anchors.fill: parent // TODO: remove boilerplate
        }
    ]

    Grid { }
    Bar {
        categories: ["a", "b", "c", "e"]
        yValues: [-9, 3, 5, -1]

        pen.fill: "red"
        selectedPen.fill: "green"
        selectable: true
    }
}
