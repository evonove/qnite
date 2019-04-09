#ifndef QNITE_MAPPER_H
#define QNITE_MAPPER_H

#include <QMap>
#include <QObject>

class QniteMapper : public QObject {
  Q_OBJECT
public:
  explicit QniteMapper(QObject *parent = 0);
  virtual ~QniteMapper();

  virtual QMap<int, qreal> mapTo(qreal sourceLower, qreal sourceUpper,
                                 qreal destLower, qreal destUpper,
                                 const QMap<int, qreal> &values,
                                 bool flip = false);

  virtual qreal mapTo(qreal sourceLower, qreal sourceUpper, qreal destLower,
                      qreal destUpper, qreal values, bool flip = false) = 0;
};
#endif // QNITE_MAPPER_H
