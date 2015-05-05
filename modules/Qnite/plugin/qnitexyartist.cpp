#include "qnitexyartist.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitemapper.h"
#include "qniteclipper.h"

QniteXYArtist::QniteXYArtist(QQuickItem* parent):
  QniteArtist(parent),
  m_xMapper{nullptr},
  m_yMapper{nullptr}
{
}

QniteXYArtist::~QniteXYArtist()
{
}

QColor QniteXYArtist::color() const
{
  return m_color;
}

void QniteXYArtist::setColor(const QColor& color)
{
  if (color != m_color) {
    m_color = color;
    emit colorChanged();
  }
}

QList<qreal> QniteXYArtist::xValues()
{
  return m_xValues;
}

void QniteXYArtist::setXValues(const QList<qreal>& values)
{
  if (m_xValues != values) {
    m_xValues = values;
    // TODO: transform the values here and cache
    emit xValuesChanged();
  }
}
QList<qreal> QniteXYArtist::yValues()
{
  return m_yValues;
}

void QniteXYArtist::setYValues(const QList<qreal>& values)
{
  if (m_yValues != values) {
    m_yValues = values;
    // TODO: transform the values here and cache
    emit yValuesChanged();
  }
}

QniteMapper* QniteXYArtist::xMapper() const
{
  return m_xMapper;
}

void QniteXYArtist::setXMapper(QniteMapper* mapper)
{
  // TODO: when the mapper is set we should
  // connect to its factorChanged event and trigger an update
  // and disconnect the previous one
  if (mapper != m_xMapper) {
    m_xMapper = mapper;
    // TODO: emit a signal??
  }
}

QniteMapper* QniteXYArtist::yMapper() const
{
  return m_yMapper;
}

void QniteXYArtist::setYMapper(QniteMapper* mapper)
{
  // TODO: when the mapper is set we should
  // connect to its factorChanged event and trigger an update
  // and disconnect the previous one
  if (mapper != m_yMapper) {
    m_yMapper = mapper;
    // TODO: emit a signal??
  }
}

const QList<qreal>& QniteXYArtist::xMapped() const
{
  return m_xMapped;
}

const QList<qreal>& QniteXYArtist::yMapped() const
{
  return m_yMapped;
}

void QniteXYArtist::processData()
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

void QniteXYArtist::updateAxes()
{
  QniteAxes* axes = this->axes();
  if (axes != nullptr) {
    disconnect(axes, SIGNAL(bottomAxisChanged()), this, 0);
    disconnect(axes, SIGNAL(leftAxisChanged()), this, 0);

    connect(axes, &QniteAxes::bottomAxisChanged, this, [=](){ this->setXMapper(axes->bottomAxis()->mapper()); });
    connect(axes, &QniteAxes::leftAxisChanged, this, [=](){ this->setYMapper(axes->leftAxis()->mapper()); });
  }
}
