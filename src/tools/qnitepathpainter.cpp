#include <QLoggingCategory>

#include "qnitepathpainter.h"
#include "qnitepathselectiontool.h"

Q_LOGGING_CATEGORY(qnitepathpainter, "qnite.path.painter")

QnitePathPainter::QnitePathPainter() : QNanoQuickItemPainter{} {}

void QnitePathPainter::synchronize(QNanoQuickItem *item) {
  qCDebug(qnitepathpainter) << "synchronizing qnitepath";

  auto path = static_cast<QnitePathSelectionTool *>(item);
  if (path != Q_NULLPTR) {

    m_points = path->m_selection;

    m_pen = path->pen()->data();
  }
}

void QnitePathPainter::paint(QNanoPainter *painter) {
  qCDebug(qnitepathpainter) << "painting qnitepath";

  // avoid drawing when there are less than 2 points
  if (m_points.size() < 2) {
    return;
  }

  painter->setStrokeStyle(QNanoColor::fromQColor(m_pen.stroke));
  if (m_pen.fill.isValid()) {
    painter->setFillStyle(QNanoColor::fromQColor(m_pen.fill));
  }
  painter->setLineWidth(m_pen.width);
  painter->setLineJoin(m_pen.join);
  painter->setLineCap(m_pen.cap);

  painter->beginPath();
  painter->moveTo(m_points.at(0).x(), m_points.at(0).y());
  for (const auto &p : m_points) {
    painter->lineTo(p.x(), p.y());
  }
  painter->fill();
  painter->stroke();
  painter->closePath();
}
