#include "qnitepointselectiontool.h"
#include "qniteartist.h"

QnitePointSelectionTool::QnitePointSelectionTool(QQuickItem *parent)
    : QniteSelectionTool(parent) {
  setFlag(ItemHasContents, false);
}

void QnitePointSelectionTool::select(const QPoint &point) {
  clearSelection();
  m_selection = point;
  select(); // calls doSelect on all artists of the attached axes
}

bool QnitePointSelectionTool::doSelect(QniteArtist *artist) {
  return artist->select(m_selection);
}

void QnitePointSelectionTool::mouseReleaseEvent(QMouseEvent *event) {
  select(event->pos());
}
