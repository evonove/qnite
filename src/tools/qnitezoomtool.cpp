#include "qnitezoomtool.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitemapper.h"
#include "qnitezoompainter.h"

QniteZoomTool::QniteZoomTool(QQuickItem *parent)
    : QniteTool{parent}, m_zoomLevel{0}, m_pen{new QnitePen} {
  setAcceptedMouseButtons(Qt::RightButton);
  m_pen->setFill("#6EDCDCDC");
  m_pen->setStroke("#7E7E7E");
  m_pen->setWidth(1.0);
}

QniteZoomTool::~QniteZoomTool() {}

QNanoQuickItemPainter *QniteZoomTool::createItemPainter() const {
  return new QniteZoomPainter;
}

void QniteZoomTool::mousePressEvent(QMouseEvent *event) {
  m_zoomRect.setTopLeft(event->pos());
}

void QniteZoomTool::mouseMoveEvent(QMouseEvent *event) {
  m_zoomRect.setBottomRight(event->pos());
  update();
}

void QniteZoomTool::mouseReleaseEvent(QMouseEvent *event) {
  if (m_zoomRect.isNull() || event->pos() == m_zoomRect.topLeft()) {
    return;
  }

  // Calculates new axes bounds and updates them
  auto yMin = qMin(m_zoomRect.top(), m_zoomRect.bottom());
  auto yMax = qMax(m_zoomRect.top(), m_zoomRect.bottom());

  QList<qreal> yValues{{yMin, yMax}};

  auto yAxis = axes()->axisY();
  auto yMapped =
      yAxis->mapper()->mapTo(0, axes()->height(), yAxis->lowerBound(),
                             yAxis->upperBound(), yValues, yAxis->flip());

  auto xMin = qMin(m_zoomRect.left(), m_zoomRect.right());
  auto xMax = qMax(m_zoomRect.left(), m_zoomRect.right());

  QList<qreal> xValues{{xMin, xMax}};

  auto xAxis = axes()->axisX();
  auto xMapped =
      xAxis->mapper()->mapTo(0, axes()->width(), xAxis->lowerBound(),
                             xAxis->upperBound(), xValues, xAxis->flip());

  yAxis->setLowerBound(qMin(yMapped.first(), yMapped.last()));
  yAxis->setUpperBound(qMax(yMapped.first(), yMapped.last()));
  xAxis->setLowerBound(qMin(xMapped.first(), xMapped.last()));
  xAxis->setUpperBound(qMax(xMapped.first(), xMapped.last()));

  m_zoomRect = QRectF{};

  update();
}
