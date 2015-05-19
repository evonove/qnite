#include "qniteartist.h"

QniteArtist::QniteArtist(QQuickItem* parent):
  QQuickItem(parent),
  m_axes{nullptr},
  m_selectable{false},
  m_propagate_selection{false}
{
}

QniteArtist::~QniteArtist()
{
}

QniteAxes* QniteArtist::axes() const
{
  return m_axes;
}

void QniteArtist::setAxes(QniteAxes* axes)
{
  if (m_axes != axes) {
    m_axes = axes;
    emit axesChanged();

    updateAxes();
  }
}

void QniteArtist::updateAxes()
{
}

void QniteArtist::setSelectable(bool selectable)
{
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
bool QniteArtist::selected() const
{
  return selectable() && isSelected();
}

/*!
    Perform a selection operation within the path and return whether
    the selection event should be accepted or not. If a selection event
    is accepted, it should not be propagated to other artists.
*/
bool QniteArtist::select(const QList<QPointF>&)
{
  return !m_propagate_selection;
}

/*!
    \overload select(const QList<QPointF>&)

    Provided to conveniently select single points
*/
bool QniteArtist::select(QPointF p)
{
  return select(QList<QPointF>{p});
}

void QniteArtist::setPropagateSelection(bool propagate)
{
  if (m_propagate_selection != propagate) {
    m_propagate_selection = propagate;

    emit propagateSelectionChanged();
  }
}
