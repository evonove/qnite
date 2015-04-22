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

    /*! \qmlproperty Axes Figure::axes

     This object is responsible for the placement of
     the axes and the alignment with the plot area.
    */
    property alias axes: __axes

    default property alias artists: __axes.artists

    Axes {
      id: __axes
      anchors.fill: parent
    }
}
