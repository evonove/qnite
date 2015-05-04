#include "qniteartist.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitemapper.h"
#include "qniteclipper.h"

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

const QList<qreal>& QniteArtist::xMapped() const
{
  return m_xMapped;
}

const QList<qreal>& QniteArtist::yMapped() const
{
  return m_yMapped;
}

void QniteArtist::processData()
{
  if (xValues().size() != yValues().size())
    qWarning() << "xValues and yValues size for the artists are different";

  // get bounds
  qreal xLower = axes()->bottomAxis()->lowerBound();
  qreal xUpper = axes()->bottomAxis()->upperBound();
  qreal yLower = axes()->leftAxis()->lowerBound();
  qreal yUpper = axes()->leftAxis()->upperBound();

  // clip non visible data
  QniteClipper clipper;
  QList<qreal> xClipped;
  QList<qreal> yClipped;
  // TODO: xValues and yValues should return const references
  clipper.clip(xValues(), yValues(), xLower, xUpper, yLower, yUpper, xClipped, yClipped);

  // map to display
  m_xMapped = xMapper()->mapTo(xLower, xUpper, 0, width(), xClipped);
  m_yMapped = yMapper()->mapTo(yLower, yUpper, 0, height(), yClipped, true);
}
