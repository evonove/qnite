#include "qniteaxis.h"
#include "qniteclipper.h"
#include "qnitelinearmapper.h"
#include "qnitelinearticker.h"

/*! TODO: add docs
*/
QniteAxisTick::QniteAxisTick(QObject* parent):
  QObject(parent),
  m_thick{0},
  m_majSize{0},
  m_minSize{0}
{
}

QniteAxisTick::~QniteAxisTick()
{
}

qreal QniteAxisTick::thick() const
{
  return m_thick;
}

void QniteAxisTick::setThick(qreal thick)
{
  if (m_thick != thick) {
    m_thick = thick;
    emit thickChanged();
  }
}

qreal QniteAxisTick::majSize() const
{
  return m_majSize;
}

void QniteAxisTick::setMajSize(qreal size)
{
  if (m_majSize != size) {
    m_majSize = size;
    emit majSizeChanged();
  }
}

qreal QniteAxisTick::midSize() const
{
  return m_midSize;
}

void QniteAxisTick::setMidSize(qreal size)
{
  if (m_midSize != size) {
    m_midSize = size;
    emit midSizeChanged();
  }
}

qreal QniteAxisTick::minSize() const
{
  return m_minSize;
}

void QniteAxisTick::setMinSize(qreal size)
{
  if (m_minSize != size) {
    m_minSize = size;
    emit minSizeChanged();
  }
}

QColor QniteAxisTick::color() const
{
  return m_color;
}

void QniteAxisTick::setColor(const QColor& color)
{
  if (m_color != color) {
    m_color = color;
    emit colorChanged();
  }
}

/*! TODO: add docs
*/
QniteAxis::QniteAxis(QQuickItem* parent):
  QniteArtist(parent),
  m_size{0},
  m_lowerBound{0},
  m_upperBound{0},
  m_tick{new QniteAxisTick(this)},
  m_mapper{new QniteLinearMapper(this)},
  m_ticker{new QniteLinearTicker(this)}
{
}

QniteAxis::~QniteAxis()
{
}

qreal QniteAxis::size() const
{
  return m_size;
}

void QniteAxis::setSize(qreal size)
{
  if (m_size != size) {
    m_size = size;
    emit sizeChanged();

    processData();
  }
}

qreal QniteAxis::lowerBound() const
{
  return m_lowerBound;
}

void QniteAxis::setLowerBound(qreal bound)
{
  if (m_lowerBound != bound) {
    qDebug() << "lower changed" << bound;
    m_lowerBound = bound;
    emit lowerBoundChanged();

    processData();
  }
}

qreal QniteAxis::upperBound() const
{
  return m_upperBound;;
}

void QniteAxis::setUpperBound(qreal bound)
{
  if (m_upperBound != bound) {
    qDebug() << "upper changed" << bound;
    m_upperBound = bound;
    emit upperBoundChanged();

    processData();
  }
}

bool QniteAxis::flip() const
{
  return m_flip;
}

void QniteAxis::setFlip(bool flip)
{
  if (m_flip != flip) {
    m_flip = flip;
    emit flipChanged();

    processData();
  }
}

QniteAxisTick* QniteAxis::tick() const
{
  return m_tick;
}

QniteTicker* QniteAxis::ticker() const
{
  return m_ticker;
}

QniteMapper* QniteAxis::mapper() const
{
  return m_mapper;
}

QList<qreal> QniteAxis::majorTicks() const
{
  return m_majorTicks;
}

QList<qreal> QniteAxis::midTicks() const
{
  return m_midTicks;
}

QList<qreal> QniteAxis::minorTicks() const
{
  return m_minorTicks;
}

void QniteAxis::processData()
{
  // avoid ticker initialization when mapper is invalid
  if (m_mapper == nullptr) {
    m_ticker->reset();
  }
  else {
    m_ticker->setBoundaries(m_lowerBound, m_upperBound);

    m_majorTicks.clear();
    m_midTicks.clear();
    m_minorTicks.clear();
    m_ticker->setBoundaries(m_lowerBound, m_upperBound);

    // TODO: encapsulate in transformer pipeline
    // clip ticks
    QList<qreal> t;
    QniteClipper clipper;
    clipper.clip(m_ticker->majorTicks(), m_lowerBound, m_upperBound, t);

    // map to display
    m_majorTicks = m_mapper->mapTo(m_lowerBound, m_upperBound, 0, m_size, t, m_flip);
    m_midTicks = m_mapper->mapTo(m_lowerBound, m_upperBound, 0, m_size,
                                   m_ticker->midTicks(), m_flip);
    m_minorTicks = m_mapper->mapTo(m_lowerBound, m_upperBound, 0, m_size,
                                   m_ticker->minorTicks(), m_flip);
  }

  emit majorTicksChanged();
  emit midTicksChanged();
  emit minorTicksChanged();
}

