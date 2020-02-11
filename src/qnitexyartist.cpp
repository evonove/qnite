#include "qnitexyartist.h"
#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qniteclipper.h"
#include "qnitemapper.h"

QniteXYArtist::QniteXYArtist(QQuickItem *parent)
    : QniteArtist(parent), m_clipper{nullptr}, m_xMapper{nullptr},
      m_yMapper{nullptr} {}

QniteXYArtist::~QniteXYArtist() {}

QList<qreal> QniteXYArtist::xValues() { return m_xValues.values(); }

void QniteXYArtist::setXValues(const QList<qreal> &values) {
  if (m_xValues.values() != values) {
    m_xValues.clear();
    for (int i = 0; i < values.size(); i++) {
      m_xValues.insert(i, values.at(i));
    }
    // TODO: transform the values here and cache
    emit xValuesChanged();
    update();

    // clear the current selection after any changes on X values
    clearSelection();
  }
}

QList<qreal> QniteXYArtist::yValues() { return m_yValues.values(); }

void QniteXYArtist::setYValues(const QList<qreal> &values) {
  if (m_yValues.values() != values) {
    m_yValues.clear();
    for (int i = 0; i < values.size(); i++) {
      m_yValues.insert(i, values.at(i));
    }
    // TODO: transform the values here and cache
    emit yValuesChanged();
    update();

    // clear the current selection after any changes on Y values
    clearSelection();
  }
}

QniteMapper *QniteXYArtist::xMapper() const { return m_xMapper; }

void QniteXYArtist::setXMapper(QniteMapper *mapper) {
  // TODO: when the mapper is set we should
  // connect to its factorChanged event and trigger an update
  // and disconnect the previous one
  if (mapper != m_xMapper) {
    m_xMapper = mapper;
    // TODO: emit a signal??
  }
}

QniteMapper *QniteXYArtist::yMapper() const { return m_yMapper; }

void QniteXYArtist::setYMapper(QniteMapper *mapper) {
  // TODO: when the mapper is set we should
  // connect to its factorChanged event and trigger an update
  // and disconnect the previous one
  if (mapper != m_yMapper) {
    m_yMapper = mapper;
    // TODO: emit a signal??
  }
}

QniteClipper *QniteXYArtist::clipper() const { return m_clipper; }

void QniteXYArtist::setClipper(QniteClipper *clipper) {
  if (m_clipper != clipper) {
    m_clipper = clipper;
    // TODO: signal????
  }
}

QMap<int, qreal> QniteXYArtist::xMapped() const { return m_xMapped; }

QMap<int, qreal> QniteXYArtist::yMapped() const { return m_yMapped; }

QList<qreal> QniteXYArtist::xProcessed() const { return m_xProcessed; }

QList<qreal> QniteXYArtist::yProcessed() const { return m_yProcessed; }

void QniteXYArtist::processData() {
  if (qMin(xValues().size(), yValues().size()) < 1) {
    m_xMapped.clear();
    m_yMapped.clear();

    m_xProcessed.clear();
    m_yProcessed.clear();

    return;
  }

  // get bounds
  qreal xLower = axes()->axisX()->lowerBound();
  qreal xUpper = axes()->axisX()->upperBound();
  qreal yLower = axes()->axisY()->lowerBound();
  qreal yUpper = axes()->axisY()->upperBound();

  // TODO: this should be improved. clipping should be done only when bounds
  // changes and tranforsm should always be performed
  QMap<int, qreal> xClipped;
  QMap<int, qreal> yClipped;
  // clip non visible data
  if (clipper() != nullptr) {
    clipper()->clip(m_xValues, m_yValues, xLower, xUpper, yLower, yUpper,
                    xClipped, yClipped);
  } else {
    xClipped = m_xValues;
    yClipped = m_yValues;
  }

  // map to display
  m_xMapped = xMapper()->mapTo(xLower, xUpper, 0, width(), xClipped);
  m_yMapped = yMapper()->mapTo(yLower, yUpper, 0, height(), yClipped, true);

  // TODO: this is ugly and inefficient. move into a pipelino or something
  // similar move to the output area
  m_xProcessed = m_xMapped.values();
  m_yProcessed = m_yMapped.values();
}

void QniteXYArtist::updateAxes() {
  QniteArtist::updateAxes();

  QniteAxes *axes = this->axes();
  if (axes != nullptr) {
    // TODO: find a better way to handle axis bindings
    if (axes->axisX() != nullptr)
      this->setXMapper(axes->axisX()->mapper());

    if (axes->axisY() != nullptr)
      this->setYMapper(axes->axisY()->mapper());

    disconnect(axes, SIGNAL(axisXChanged()), this, nullptr);
    disconnect(axes, SIGNAL(axisYChanged()), this, nullptr);

    connect(axes, &QniteAxes::axisXChanged, this,
            [=]() { this->setXMapper(axes->axisX()->mapper()); });
    connect(axes, &QniteAxes::axisYChanged, this,
            [=]() { this->setYMapper(axes->axisY()->mapper()); });
  }
}
