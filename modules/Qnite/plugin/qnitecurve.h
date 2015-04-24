#ifndef QNITE_CURVE_H
#define QNITE_CURVE_H

#include "qniteartist.h"

class QniteCurve : public QniteArtist
{
    Q_OBJECT
  public:
    explicit QniteCurve(QQuickItem *parent = 0);
    virtual ~QniteCurve();

  protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);
};


#endif // QNITE_CURVE_H

