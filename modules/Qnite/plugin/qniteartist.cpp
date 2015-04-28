#include "qniteartist.h"

QniteArtist::QniteArtist(QQuickItem* parent):
  QQuickItem(parent),
  m_axes{nullptr},
  m_xMapper{nullptr},
  m_yMapper{nullptr}
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
  }
}

QColor QniteArtist::color() const
{
  return m_color;
}

void QniteArtist::setColor(const QColor& color)
{
  if (color != m_color) {
    m_color = color;
    emit colorChanged();
  }
}

QList<qreal> QniteArtist::xValues()
{
  return m_xValues;
}

void QniteArtist::setXValues(const QList<qreal>& values)
{
  if (m_xValues != values) {
    m_xValues = values;
    // TODO: transform the values here and cache
    emit xValuesChanged();
  }
}
QList<qreal> QniteArtist::yValues()
{
  return m_yValues;
}

void QniteArtist::setYValues(const QList<qreal>& values)
{
  if (m_yValues != values) {
    m_yValues = values;
    // TODO: transform the values here and cache
    emit yValuesChanged();
  }
}

QniteMapper* QniteArtist::xMapper() const
{
  return m_xMapper;
}

void QniteArtist::setXMapper(QniteMapper* mapper)
{
  // TODO: when the mapper is set we should
  // connect to its factorChanged event and trigger an update
  // and disconnect the previous one
  if (mapper != m_xMapper) {
    m_xMapper = mapper;
    // TODO: emit a signal??
  }
}

QniteMapper* QniteArtist::yMapper() const
{
  return m_yMapper;
}

void QniteArtist::setYMapper(QniteMapper* mapper)
{
  // TODO: when the mapper is set we should
  // connect to its factorChanged event and trigger an update
  // and disconnect the previous one
  if (mapper != m_yMapper) {
    m_yMapper = mapper;
    // TODO: emit a signal??
  }
}

