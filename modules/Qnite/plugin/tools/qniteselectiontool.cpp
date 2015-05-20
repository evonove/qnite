#include "tools/qniteselectiontool.h"
#include "qniteaxes.h"
#include "qniteartist.h"

QniteSelectionTool::QniteSelectionTool(QQuickItem* parent):
  QniteTool(parent)
{
  setAcceptedMouseButtons(Qt::LeftButton);
  setFlag(ItemHasContents, true);
}

void QniteSelectionTool::select()
{
  for (auto artist : artists()) {
    if (artist->selectable()) {
      doSelect(artist);
    }
  }
}
