#include "qniteaxis.h"
#include "qnitemapper.h"
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
  QQuickItem(parent),
  m_tick{new QniteAxisTick(this)},
  m_mapper{nullptr},
  m_ticker{new QniteLinearTicker(this)}
{
}

QniteAxis::~QniteAxis()
{
}

QniteAxisTick* QniteAxis::tick() const
{
  return m_tick;
}

QniteTicker* QniteAxis::ticker() const
{
  return m_ticker;
}

QList<qreal> QniteAxis::majorTicks() const
{
  return m_majorTicks;
}

QniteMapper* QniteAxis::mapper() const
{
  return m_mapper;
}

void QniteAxis::setMapper(QniteMapper* mapper)
{
  if (m_mapper != mapper) {
    m_mapper = mapper;
    initTicker();
    connect(m_mapper, SIGNAL(factorChanged()),
            this, SLOT(initTicker()));
    emit mapperChanged();
  }
}

void QniteAxis::initTicker()
{
  if (m_mapper == nullptr && m_mapper->factor() == 0)
    m_ticker->reset();
  else {
    // TODO: change when setBoundaries works
    m_ticker->setValues({m_mapper->min(), m_mapper->max()});

    m_majorTicks.clear(); // TODO: avoid computation when mapper is invalid
    for(const auto& tick: m_ticker->majorTicks()) {
      m_majorTicks.append(m_mapper->transform(tick));
    }
    qDebug() << "ticker major ticks" << m_ticker->majorTicks();
    qDebug() << "mapper major ticks" << m_majorTicks;
    emit majorTicksChanged();
  }
}

