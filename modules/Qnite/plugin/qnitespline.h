#ifndef QNITE_SPLINE_H
#define QNITE_SPLINE_H

#include "qniteline.h"

class QniteSpline : public QniteLine
{
  Q_OBJECT
  Q_ENUMS(Interpolation)
  Q_PROPERTY(Interpolation interpolation READ interpolation WRITE setInterpolation NOTIFY interpolationChanged)

public:
  explicit QniteSpline(QQuickItem *parent = 0);
  virtual ~QniteSpline();

  enum Interpolation {
    Cosine,
    Cubic
  };
  Interpolation interpolation() const { return m_interpolation; }
  void setInterpolation(Interpolation i);

public Q_SLOTS:
  virtual void processData();

Q_SIGNALS:
  void interpolationChanged();

private:
  void cosineInterpolation();
  void cubicInterpolation();

  Interpolation m_interpolation;
};


#endif // QNITE_SPLINE_H

