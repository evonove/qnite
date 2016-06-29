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
  QObject(parent)
{
}

QniteMapper::~QniteMapper()
{
}

QList<qreal> QniteMapper::mapTo(qreal sourceLower, qreal sourceUpper,
                                qreal destLower, qreal destUpper,
                                const QList<qreal>& values, bool flip)
{
  QList<qreal> out;
  for(const auto& value: values) {
    auto v = mapTo(sourceLower, sourceUpper, destLower, destUpper, value, flip);
    out.append(v);
  }

  return out;
}
