#ifndef QNITE_LINE_H
#define QNITE_LINE_H

#include "qnitexyartist.h"

class QniteLine : public QniteXYArtist
{
    Q_OBJECT
  public:
    explicit QniteLine(QQuickItem *parent = 0);
    virtual ~QniteLine();

  protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);
};


#endif // QNITE_LINE_H

