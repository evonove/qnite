#ifndef QNITE_SPLINE_H
#define QNITE_SPLINE_H

#include "qnitexyartist.h"

class QniteSpline : public QniteXYArtist
{
  Q_OBJECT
public:
  explicit QniteSpline(QQuickItem *parent = 0);
  virtual ~QniteSpline();

public Q_SLOTS:
  virtual void processData();

protected:
  QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);
};


#endif // QNITE_SPLINE_H

