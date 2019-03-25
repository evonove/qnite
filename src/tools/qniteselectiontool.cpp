#include "tools/qniteselectiontool.h"
#include "qniteartist.h"
#include "qniteaxes.h"

QniteSelectionTool::QniteSelectionTool(QQuickItem *parent) : QniteTool(parent) {
  setAcceptedMouseButtons(Qt::LeftButton);
}

/*!
  Iterate through artists present in current axes, skip if not selectable,
  perform selection and break iteration if some artist accepts the selection
  event.
 */
void QniteSelectionTool::select() {
  for (auto artist : artists()) {
    if (!artist->selectable()) {
      continue;
    } else if (doSelect(artist)) {
      break;
    }
  }
}

void QniteSelectionTool::clearSelection() {
  for (auto artist : artists()) {
    if (artist->selectable()) {
      artist->clearSelection();
    }
  }
}

void QniteSelectionTool::reset() { clearSelection(); }
