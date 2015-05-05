#include "qniteartist.h"

QniteArtist::QniteArtist(QQuickItem* parent):
  QQuickItem(parent),
  m_axes{nullptr}
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

