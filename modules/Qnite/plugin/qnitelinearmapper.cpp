#include "qnitelinearmapper.h"


/*!
    \qmltype LinearMapper
    \instantiates QniteLinearMapper
    \ingroup transforms
    \inqmlmodule Qnite
    \brief Transform a value from the scale space to the item space

    TODO: add a long description
*/
QniteLinearMapper::QniteLinearMapper(QObject *parent):
  QniteMapper(parent)
{
}

QniteLinearMapper::~QniteLinearMapper()
{
}

qreal QniteLinearMapper::factor() const
{
  // TODO: maybe we should cache this value instead
  // of computing it every time
  qreal dataSize = qAbs(m_max - m_min);
  if (dataSize == 0.0 || m_size == 0.0)
    return 0.0;

  return m_size / dataSize;
}

qreal QniteLinearMapper::transform(qreal value)
{
  qreal v = factor() * qAbs(m_min - value);

  // TODO: maybe raise an exception when the value is out-of-bounds
  if (value < m_min)
    v *= -1;

  if (m_flip)
    return m_size - v;

  return v;
}

