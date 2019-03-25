#include <QLoggingCategory>

#include "qnitegrid.h"
#include "qnitegridpainter.h"

Q_LOGGING_CATEGORY(qnitegrid, "qnite.grid")

QniteGrid::QniteGrid(QQuickItem *parent)
    : QniteArtist{parent}, m_drawXAxes{true}, m_drawYAxes{true} {
  // we set a nicer default for a background grid
  pen()->setWidth(1);
  pen()->setStroke("#bdbdbd");
}

QNanoQuickItemPainter *QniteGrid::createItemPainter() const {
  return new QniteGridPainter;
}

/* When the value variable has a different value the m_drawXAxes variable,
 * signal is emitted  */
void QniteGrid::setDrawXAxes(bool value) {
  if (m_drawXAxes != value) {
    m_drawXAxes = value;
    emit drawXAxesChanged();
  }
}

/* When the value variable has a different value the m_drawYAxes variable,
 * signal is emitted  */
void QniteGrid::setDrawYAxes(bool value) {
  if (m_drawYAxes != value) {
    m_drawYAxes = value;
    emit drawYAxesChanged();
  }
}
