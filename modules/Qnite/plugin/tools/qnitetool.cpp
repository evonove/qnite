#include "qnitetool.h"

QniteTool::QniteTool(QQuickItem* parent):
  QQuickItem(parent)
{
}

void QniteTool::setAxes(QniteAxes* axes)
{
  if (m_axes != axes) {
    m_axes = axes;
    emit axesChanged();
  }
}
