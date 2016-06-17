import Qnite 1.0

Figure {
    axes.xBounds: [-5, 10]
    axes.yBounds: [-2, 10.8]

    tools: [
        PointSelectionTool {
            anchors.fill: parent // TODO: remove boilerplate
        }
    ]

    Grid { }
    Spline {
        xValues: [-5, -1.5, -0.1, .4, 2.3, 3.4, 5, 6, 9, 10]
        yValues: [-3, 0, 2, -1.3, .9, -.2, -.6, 4, 5, 9]

        pen {
            stroke: "#3f51b5"
            fill: "#99ec407a"
        }
    }

    Spline {
        xValues: [-4.8, -2, .5, 2, 3, 4,  8, 10]
        yValues: [   3,  1, -2, 6, 3, 4, 10, 4]
        pen.stroke: "#345f6b"

        interpolation: Spline.CatmullRom
    }
}
