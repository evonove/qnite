#include "qnitemapper.h"

/*!
    \qmltype Mapper
    \instantiates QniteMapper
    \ingroup transforms
    \inqmlmodule Qnite
    \brief Transform a value from the scale space to the item space

    TODO: add a long description
*/
QniteMapper::QniteMapper(QObject *parent) : QObject(parent) {}

QniteMapper::~QniteMapper() {}

QMap<int, qreal> QniteMapper::mapTo(qreal sourceLower, qreal sourceUpper,
                                    qreal destLower, qreal destUpper,
                                    const QMap<int, qreal> &values, bool flip) {
  QMap<int, qreal> out;

  auto it = values.constBegin();
  while (it != values.constEnd()) {
    auto v =
        mapTo(sourceLower, sourceUpper, destLower, destUpper, it.value(), flip);
    out.insert(it.key(), v);
    it++;
  }
  return out;
}
