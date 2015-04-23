#include "qnitemapper.h"


/*!
    \qmltype Mapper
    \instantiates QniteMapper
    \ingroup transforms
    \inqmlmodule Qnite
    \brief Transform a value from the scale space to the item space

    TODO: add a long description
*/
QniteMapper::QniteMapper(QObject *parent):
  QObject(parent),
  m_min{0},
  m_max{0},
  m_size{0},
  m_flip{false}
{
  connect(this, SIGNAL(minChanged()), this, SIGNAL(factorChanged()));
  connect(this, SIGNAL(maxChanged()), this, SIGNAL(factorChanged()));
  connect(this, SIGNAL(sizeChanged()), this, SIGNAL(factorChanged()));
}

QniteMapper::~QniteMapper()
{
}

qreal QniteMapper::min() const
{
  return m_min;
}

void QniteMapper::setMin(qreal min)
{
  if (min != m_min) {
    m_min = min;
    emit minChanged();
  }
}

qreal QniteMapper::max() const
{
  return m_max;
}

void QniteMapper::setMax(qreal max)
{
  if (max != m_max) {
    m_max = max;
    emit maxChanged();
  }
}

qreal QniteMapper::size() const
{
  return m_size;
}

void QniteMapper::setSize(qreal size)
{
  if (size != m_size) {
    m_size = size;
    emit sizeChanged();
  }
}

bool QniteMapper::flip() const
{
  return m_flip;
}

void QniteMapper::setFlip(bool flip)
{
  if (flip != m_flip) {
    m_flip = flip;
    emit flipChanged();
  }
}

