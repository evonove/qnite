#include "qniteartist.h"
#include "qniteaxes.h"

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
  disconnect(m_axes, SIGNAL(widthChanged()), this, 0);
  disconnect(m_axes, SIGNAL(heightChanged()), this, 0);

  if (m_axes != nullptr) {
    setWidth(m_axes->width());
    setHeight(m_axes->height());

    connect(m_axes, &QQuickItem::widthChanged, [=](){ this->setWidth(m_axes->width()); });
    connect(m_axes, &QQuickItem::heightChanged, [=](){ this->setHeight(m_axes->height()); });
  }
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

