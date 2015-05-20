#ifndef QNITESELECTIONTOOL_H
#define QNITESELECTIONTOOL_H

#include "qnitetool.h"

class QniteSelectionTool: public QniteTool
{
  Q_OBJECT

public:
  explicit QniteSelectionTool(QQuickItem* parent = 0);
  virtual ~QniteSelectionTool() {}

};


#endif // QNITESELECTIONTOOL_H

