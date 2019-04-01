#include "qnitelinearmapper.h"

/*!
    \qmltype LinearMapper
    \instantiates QniteLinearMapper
    \ingroup transforms
    \inqmlmodule Qnite
    \brief Transform a value from the scale space to the item space

    TODO: add a long description
*/
QniteLinearMapper::QniteLinearMapper(QObject *parent) : QniteMapper(parent) {}

QniteLinearMapper::~QniteLinearMapper() {}

qreal QniteLinearMapper::mapTo(qreal sourceLower, qreal sourceUpper,
                               qreal destLower, qreal destUpper, qreal value,
                               bool flip) {
  qreal sourceSize = qAbs(sourceUpper - sourceLower);
  qreal destSize = qAbs(destLower - destUpper);

  if (sourceSize == 0.0 || destSize == 0.0)
    return 0.0; // TODO: size is invalid. return 0 or raise exception?

  qreal f = destSize / sourceSize;
  qreal v = f * qAbs(sourceLower - value);

  // TODO: maybe raise an exception when the value is out-of-bounds
  if (value < sourceLower)
    v *= -1;

  if (flip) {
    return destUpper - v;
  }

  return destLower + v;
}
