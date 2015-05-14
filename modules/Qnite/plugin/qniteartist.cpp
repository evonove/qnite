#include "qniteartist.h"

QniteArtist::QniteArtist(QQuickItem* parent):
  QQuickItem(parent),
  m_axes{nullptr},
  m_selectable{false}
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
  if (!selectable && selected()) {
    clearSelection();
  }

  m_selectable = selectable;
  emit selectableChanged();
}

/*!
    If the artist is not selectable, completely skip the logic determining
    the selection state.
*/
bool QniteArtist::selected() const
{
  return selectable() && isSelected();
}
