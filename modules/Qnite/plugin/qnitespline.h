#ifndef QNITE_SPLINE_H
#define QNITE_SPLINE_H

#include "qniteline.h"

class QniteSpline : public QniteLine
{
  Q_OBJECT
  Q_ENUMS(Interpolation)
  Q_PROPERTY(Interpolation interpolation READ interpolation WRITE setInterpolation NOTIFY interpolationChanged)
  Q_PROPERTY(qreal tension READ tension WRITE setTension NOTIFY tensionChanged)
  Q_PROPERTY(qreal bias READ bias WRITE setBias NOTIFY biasChanged)

public:
  explicit QniteSpline(QQuickItem *parent = 0);
  virtual ~QniteSpline();

  enum Interpolation {
    Cosine,
    Cubic,
    CatmullRom,
    Hermite
  };
  Interpolation interpolation() const { return m_interpolation; }
  void setInterpolation(Interpolation i);

  qreal tension() const { return m_tension; }
  void setTension(qreal t);
  qreal bias() const { return m_bias; }
  void setBias(qreal b);

public Q_SLOTS:
  virtual void processData() Q_DECL_OVERRIDE;

Q_SIGNALS:
  void interpolationChanged();
  void tensionChanged();
  void biasChanged();

private:
  void cosineInterpolation();
  void cubicInterpolation();

  Interpolation m_interpolation;
  qreal m_tension;
  qreal m_bias;
};


#endif // QNITE_SPLINE_H

