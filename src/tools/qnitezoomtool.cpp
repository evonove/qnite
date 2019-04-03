#include "qnitezoomtool.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qnitemapper.h"
#include "qnitezoompainter.h"

QniteZoomTool::QniteZoomTool(QQuickItem *parent)
    : QniteTool{parent}, m_minZoomFactor{10e4},
      m_limitZoom{true}, m_pen{new QnitePen} {
  setAcceptedMouseButtons(Qt::RightButton);

  // Default pen style
  m_pen->setFill("#6EDCDCDC");
  m_pen->setStroke("#7E7E7E");
  m_pen->setWidth(1.0);

  connect(this, &QniteZoomTool::axesChanged, this,
          &QniteZoomTool::connectAxesBoundsSignals);
}

QniteZoomTool::~QniteZoomTool() {}

QNanoQuickItemPainter *QniteZoomTool::createItemPainter() const {
  return new QniteZoomPainter;
}

void QniteZoomTool::resetZoom() {
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

void QniteZoomTool::setMinZoomFactor(qreal factor) {
  if (qFuzzyCompare(1 + m_minZoomFactor, 1 + factor)) {
    m_minZoomFactor = factor;
    emit minZoomFactorChanged();
  }
}

void QniteZoomTool::setLimitZoom(bool limit) {
  if (m_limitZoom != limit) {
    m_limitZoom = limit;
    emit limitZoomChanged();
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
  axes()->updateArtists();

  if (!m_limitZoom) {
    return;
  }

  // Disables zoom if a certain amount of zoom is reached
  auto minSize = minimumZoomSize();
  auto axisYSize = qAbs(yMapped.first() - yMapped.last());
  auto axisXSize = qAbs(xMapped.first() - xMapped.last());

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
  return {qAbs(m_baseZoomRect.width() / m_minZoomFactor),
          qAbs(m_baseZoomRect.height() / m_minZoomFactor)};
}
