#ifndef QNITE_CLIPPER_H
#define QNITE_CLIPPER_H

#include <QObject>

class QniteClipper : public QObject {
  Q_OBJECT
public:
  explicit QniteClipper(QObject *parent = 0);
  virtual ~QniteClipper();

  virtual void clip(const QList<qreal> &xValues, const QList<qreal> &yValues,
                    qreal xLower, qreal xUpper, qreal yLower, qreal yUpper,
                    QList<qreal> &outX, QList<qreal> &outY);
  virtual void clip(const QList<qreal> &values, qreal lower, qreal upper,
                    QList<qreal> &out);
};
#endif // QNITE_CLIPPER_H
