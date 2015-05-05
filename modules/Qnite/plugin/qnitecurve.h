#ifndef QNITE_CURVE_H
#define QNITE_CURVE_H

#include "qnitexyartist.h"

class QniteCurve : public QniteXYArtist
{
    Q_OBJECT
  public:
    explicit QniteCurve(QQuickItem *parent = 0);
    virtual ~QniteCurve();

  protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);
};


#endif // QNITE_CURVE_H

