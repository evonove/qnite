#ifndef QNITE_SPLINE_H
#define QNITE_SPLINE_H

#include "qniteline.h"

class QniteSpline : public QniteLine
{
  Q_OBJECT
public:
  explicit QniteSpline(QQuickItem *parent = 0);
  virtual ~QniteSpline();

public Q_SLOTS:
  virtual void processData();

};


#endif // QNITE_SPLINE_H

