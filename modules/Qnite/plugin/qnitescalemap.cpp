#include "qnitescalemap.h"


/*!
    \qmltype ScaleEngine
    \instantiates QniteScaleEngine
    \ingroup scaling
    \inqmlmodule Qnite
    \brief Transform a value from the scale space to the item space

    TODO: add a long description
*/

QniteScaleMap::QniteScaleMap(QObject *parent):
  QObject(parent)
{
}

QniteScaleMap::~QniteScaleMap()
{
}

qreal QniteScaleMap::min() const
{
  return m_min;
}

void QniteScaleMap::setMin(qreal min)
{
  if (min != m_min) {
    m_min = min;
    emit minChanged();
  }
}

qreal QniteScaleMap::max() const
{
  return m_max;
}

void QniteScaleMap::setMax(qreal max)
{
  if (max != m_max) {
    m_max = max;
    emit maxChanged();
  }
}

qreal QniteScaleMap::size() const
{
  return m_size;
}

void QniteScaleMap::setSize(qreal size)
{
  if (size != m_size) {
    m_size = size;
    emit sizeChanged();
  }
}

qreal QniteScaleMap::transform(qreal value)
{
  qreal sSize = qAbs(m_max - m_min);
  return m_size / sSize * value;
}

