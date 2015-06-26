#ifndef QNITE_BAR_H
#define QNITE_BAR_H

#include "qnitexyartist.h"
#include <QColor>

class QniteBar : public QniteXYArtist
{
  Q_OBJECT

public:
  explicit QniteBar(QQuickItem *parent = 0);
  virtual ~QniteBar();

protected:
  QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);
  void updateBars(QSGNode* node);

private:
  QSGNode* m_barsNode;
};


#endif // QNITE_BAR_H

