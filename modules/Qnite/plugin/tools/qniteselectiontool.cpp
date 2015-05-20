#include "tools/qniteselectiontool.h"

QniteSelectionTool::QniteSelectionTool(QQuickItem* parent):
  QniteTool(parent)
{
  setAcceptedMouseButtons(Qt::LeftButton);
  setFlag(ItemHasContents, true);
}
