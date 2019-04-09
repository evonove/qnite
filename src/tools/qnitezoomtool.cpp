#include <cmath>

#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitemapper.h"
#include "qnitezoompainter.h"
#include "qnitezoomtool.h"

QniteZoomTool::QniteZoomTool(QQuickItem *parent)
    : QniteTool{parent}, m_minZoomFactor{4}, m_pen{new QnitePen} {
  setAcceptedMouseButtons(Qt::RightButton);

  // Default pen style
  m_pen->setFill("#6EDCDCDC");
  m_pen->setStroke("#7E7E7E");
  m_pen->setWidth(1.0);

  connect(this, &QniteZoomTool::axesChanged, this,
          &QniteZoomTool::connectAxesBoundsSignals);

  connect(this, &QniteZoomTool::minZoomFactorChanged, this,
          &QniteZoomTool::updateEnabled);
}

QniteZoomTool::~QniteZoomTool() {}

QNanoQuickItemPainter *QniteZoomTool::createItemPainter() const {
  return new QniteZoomPainter;
}

void QniteZoomTool::reset() {
  auto xAxis = axes()->axisX();
  auto yAxis = axes()->axisY();

  xAxis->setLowerBound(m_baseZoomRect.x());
  xAxis->setUpperBound(m_baseZoomRect.width());
  yAxis->setLowerBound(m_baseZoomRect.y());
  yAxis->setUpperBound(m_baseZoomRect.height());
  setEnabled(true);
  update();
  axes()->updateArtists();
}

void QniteZoomTool::setMinZoomFactor(int factor) {
  if (m_minZoomFactor != factor) {
    m_minZoomFactor = factor;
    emit minZoomFactorChanged();
  }
}

void QniteZoomTool::mousePressEvent(QMouseEvent *event) {
  if (!isEnabled()) {
    return;
  }

  m_zoomRect.setTopLeft(event->pos());
}

void QniteZoomTool::mouseMoveEvent(QMouseEvent *event) {
  if (!isEnabled()) {
    return;
  }

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

  auto yAxis = axes()->axisY();
  auto yMappedMin =
      yAxis->mapper()->mapTo(0, axes()->height(), yAxis->lowerBound(),
                             yAxis->upperBound(), yMin, yAxis->flip());
  auto yMappedMax =
      yAxis->mapper()->mapTo(0, axes()->height(), yAxis->lowerBound(),
                             yAxis->upperBound(), yMax, yAxis->flip());

  auto xMin = qMin(m_zoomRect.left(), m_zoomRect.right());
  auto xMax = qMax(m_zoomRect.left(), m_zoomRect.right());

  auto xAxis = axes()->axisX();
  auto xMappedMin =
      xAxis->mapper()->mapTo(0, axes()->width(), xAxis->lowerBound(),
                             xAxis->upperBound(), xMin, xAxis->flip());

  auto xMappedMax =
      xAxis->mapper()->mapTo(0, axes()->width(), xAxis->lowerBound(),
                             xAxis->upperBound(), xMax, xAxis->flip());

  yAxis->setLowerBound(qMin(yMappedMin, yMappedMax));
  yAxis->setUpperBound(qMax(yMappedMin, yMappedMax));
  xAxis->setLowerBound(qMin(xMappedMin, xMappedMax));
  xAxis->setUpperBound(qMax(xMappedMin, xMappedMax));

  m_zoomRect = QRectF{};

  update();
  axes()->updateArtists();

  // Disables tool if calculated bounds are smaller than the minimum zoom size
  auto minSize = minimumZoomSize();
  auto axisYSize = qAbs(yMappedMin - yMappedMax);
  auto axisXSize = qAbs(xMappedMin - xMappedMax);

  if (axisXSize <= minSize.width() || axisYSize <= minSize.height()) {
    setEnabled(false);
  }
}

void QniteZoomTool::connectAxesBoundsSignals() const {
  connect(axes(), &QniteAxes::xBoundsChanged, this,
          &QniteZoomTool::updateBaseZoomRectXBounds);
  connect(axes(), &QniteAxes::yBoundsChanged, this,
          &QniteZoomTool::updateBaseZoomRectYBounds);
  disconnect(this, &QniteZoomTool::axesChanged, this,
             &QniteZoomTool::connectAxesBoundsSignals);
}

void QniteZoomTool::updateBaseZoomRectXBounds() {
  auto xBounds = axes()->xBounds();
  m_baseZoomRect.setX(xBounds.first());
  m_baseZoomRect.setWidth(xBounds.last());
  disconnect(axes(), &QniteAxes::xBoundsChanged, this,
             &QniteZoomTool::updateBaseZoomRectXBounds);
}

void QniteZoomTool::updateBaseZoomRectYBounds() {
  auto yBounds = axes()->yBounds();
  m_baseZoomRect.setY(yBounds.first());
  m_baseZoomRect.setHeight(yBounds.last());
  disconnect(axes(), &QniteAxes::yBoundsChanged, this,
             &QniteZoomTool::updateBaseZoomRectYBounds);
}

QSizeF QniteZoomTool::minimumZoomSize() const {
  qreal factor = std::pow(10, m_minZoomFactor);
  return {qAbs(m_baseZoomRect.width() / factor),
          qAbs(m_baseZoomRect.height() / factor)};
}

void QniteZoomTool::updateEnabled() {
  // Disables tool if current bounds are smaller than the minimum zoom size,
  // enables it otherwise
  auto axisX = axes()->axisX();
  auto axisY = axes()->axisY();

  auto axisXSize = qAbs(axisX->lowerBound() - axisX->upperBound());
  auto axisYSize = qAbs(axisY->lowerBound() - axisY->upperBound());

  auto minSize = minimumZoomSize();
  auto enable = axisXSize > minSize.width() || axisYSize > minSize.height();
  setEnabled(enable);
}
