#include "qnitetool.h"
#include "qniteaxes.h"


QniteTool::QniteTool(QQuickItem* parent)
    : QQuickItem(parent)
    , m_axes{nullptr}
{
}

void QniteTool::setAxes(QniteAxes* axes)
{
  if (m_axes != axes) {
    m_axes = axes;
    emit axesChanged();
  }
}

/*!
    A protected proxy method to propagate friendship between
    QniteTool and QniteAxes to the children of QniteTool
*/
QList<QniteArtist*> QniteTool::artists()
{
  if (m_axes != nullptr) {
    return m_axes->m_artists;
  }

  return QList<QniteArtist*>{};
}
