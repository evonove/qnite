#include "qnitelinearaxis.h"
#include "qniteclipper.h"
#include "qnitelinearmapper.h"
#include "qnitelinearticker.h"

QniteLinearAxis::QniteLinearAxis(QQuickItem *parent) : QniteAxis(parent) {
  setMapper(new QniteLinearMapper(this));
  setTicker(new QniteLinearTicker(this));
}

void QniteLinearAxis::processData() {
  // avoid ticker initialization when mapper is invalid
  if (m_mapper == nullptr) {
    m_ticker->reset();
  } else {
    m_ticker->setBoundaries(m_lowerBound, m_upperBound);

    m_majorTicks.clear();
    m_minorTicks.clear();
    m_labels.clear();

    // TODO: encapsulate in transformer pipeline
    // clip ticks
    QList<qreal> maj, min;
    QniteClipper clipper;
    clipper.clip(m_ticker->majorTicks(), m_lowerBound, m_upperBound, maj);
    clipper.clip(m_ticker->minorTicks(), m_lowerBound, m_upperBound, min);

    // map to display
    m_majorTicks =
        m_mapper->mapTo(m_lowerBound, m_upperBound, 0, m_size, maj, m_flip);
    m_minorTicks =
        m_mapper->mapTo(m_lowerBound, m_upperBound, 0, m_size, min, m_flip);

    for (auto i = 0; i < maj.size(); ++i) {
      m_labels.push_back(QString("%1").arg(maj.at(i)));
    }

    // maps the axis position
    m_position =
        m_mapper->mapTo(m_lowerBound, m_upperBound, 0., m_size, 0., m_flip);
  }

  emit labelsChanged();
  emit majorTicksChanged();
  emit minorTicksChanged();
}
