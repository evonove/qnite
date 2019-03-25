#ifndef QNITE_LINEAR_MAPPER_H
#define QNITE_LINEAR_MAPPER_H

#include "qnitemapper.h"

class QniteLinearMapper : public QniteMapper {
  Q_OBJECT

public:
  explicit QniteLinearMapper(QObject *parent = 0);
  virtual ~QniteLinearMapper();

  using QniteMapper::mapTo;

  virtual qreal mapTo(qreal sourceLower, qreal sourceUpper, qreal destLower,
                      qreal destUpper, qreal value, bool flip = false);
};

#endif // QNITE_LINEAR_MAPPER_H
