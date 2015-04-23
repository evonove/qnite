#ifndef QNITE_LINEAR_MAPPER_H
#define QNITE_LINEAR_MAPPER_H

#include "qnitemapper.h"

class QniteLinearMapper: public QniteMapper
{
    Q_OBJECT

  public:
    explicit QniteLinearMapper(QObject *parent = 0);
    virtual ~QniteLinearMapper();

    virtual qreal factor() const;
    virtual qreal transform(qreal value);
};

#endif // QNITE_LINEAR_MAPPER_H

