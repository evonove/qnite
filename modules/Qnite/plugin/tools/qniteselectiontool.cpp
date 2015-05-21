#include "tools/qniteselectiontool.h"
#include "qniteaxes.h"
#include "qniteartist.h"

QniteSelectionTool::QniteSelectionTool(QQuickItem* parent):
  QniteTool(parent)
{
  setAcceptedMouseButtons(Qt::LeftButton);
  setFlag(ItemHasContents, true);
}

/*!
  Iterate through artists present in current axes, skip if not selectable,
  perform selection and break iteration if some artist accepts the selection
  event.
 */
void QniteSelectionTool::select()
{
  for (auto artist : artists()) {
    if (!artist->selectable()) {
      continue;
    }
    else if (doSelect(artist)) {
      break;
    }
  }
}
