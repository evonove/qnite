#ifndef QNITEGRID_H
#define QNITEGRID_H


#include "qniteartist.h"


class QniteGrid : public QniteArtist
{
public:
    QniteGrid(QQuickItem* parent = Q_NULLPTR);

    QNanoQuickItemPainter* createItemPainter() const Q_DECL_OVERRIDE;

public Q_SLOTS:
  virtual void processData() Q_DECL_OVERRIDE {}
};

#endif // QNITEGRID_H
