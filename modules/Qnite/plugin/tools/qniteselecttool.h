#ifndef QNITE_SELECT_TOOL_H
#define QNITE_SELECT_TOOL_H

#include "qnitetool.h"

class QniteSelectTool: public QniteTool
{
  Q_OBJECT
public:
  explicit QniteSelectTool(QQuickItem* parent = 0);
  virtual ~QniteSelectTool() {}

};

#endif // QNITE_SELECT_TOOL_H
