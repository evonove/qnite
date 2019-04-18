#include "qniteartist.h"
#include "qniteaxes.h"
#include "qnitepen.h"

QniteArtist::QniteArtist(QQuickItem *parent)
    : QNanoQuickItem(parent), m_axes{nullptr}, m_selectable{false},
      m_propagate_selection{false}, m_pen{new QnitePen},
      m_selectedPen{new QnitePen}, m_highlightedPen{new QnitePen} {
  // we need to trigger a redraw of the artist when
  // the pen or selectedPen's attributes change.
  connect(m_pen, &QnitePen::penChanged, this, &QniteArtist::update);
  connect(m_selectedPen, &QnitePen::penChanged, this, &QniteArtist::update);
  connect(m_highlightedPen, &QnitePen::penChanged, this, &QniteArtist::update);
}

QniteArtist::~QniteArtist() {
  delete m_pen;
  delete m_selectedPen;
  delete m_highlightedPen;
}

QniteAxes *QniteArtist::axes() const { return m_axes; }

void QniteArtist::setAxes(QniteAxes *axes) {
  if (m_axes != axes) {
    m_axes = axes;
    emit axesChanged();

    updateAxes();
  }
}

void QniteArtist::updateAxes() {
  disconnect(m_axes, SIGNAL(widthChanged()), this, 0);
  disconnect(m_axes, SIGNAL(heightChanged()), this, 0);
  disconnect(m_axes, &QniteAxes::xBoundsChanged, this, 0);
  disconnect(m_axes, &QniteAxes::yBoundsChanged, this, 0);

  if (m_axes != nullptr) {
    setWidth(m_axes->width());
    setHeight(m_axes->height());

    connect(m_axes, &QQuickItem::widthChanged, this,
            [=]() { this->setWidth(m_axes->width()); });
    connect(m_axes, &QQuickItem::heightChanged, this,
            [=]() { this->setHeight(m_axes->height()); });

    connect(m_axes, &QniteAxes::xBoundsChanged, this, &QniteArtist::update);
    connect(m_axes, &QniteAxes::yBoundsChanged, this, &QniteArtist::update);
  }
}

void QniteArtist::setSelectable(bool selectable) {
  if (selectable != m_selectable) {
    if (!selectable && selected()) {
      clearSelection();
    }

    m_selectable = selectable;
    emit selectableChanged();
  }
}

/*!
    If the artist is not selectable, completely skip the logic determining
    the selection state.
*/
bool QniteArtist::selected() const { return selectable() && isSelected(); }

/*!
    Perform a selection operation within the path and return whether
    the selection event should be accepted or not. If a selection event
    is accepted, it should not be propagated to other artists.
*/
bool QniteArtist::select(const QList<QPoint> &) {
  return !m_propagate_selection;
}

/*!
    \overload select(const QList<QPointF>&)

    Provided to conveniently select single points
*/
bool QniteArtist::select(QPoint p) { return select(QList<QPoint>{p}); }

void QniteArtist::setPropagateSelection(bool propagate) {
  if (m_propagate_selection != propagate) {
    m_propagate_selection = propagate;

    emit propagateSelectionChanged();
  }
}
