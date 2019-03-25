#include "qnitepen.h"

QnitePen::PenData::PenData()
    : stroke{"black"}, fill{}, width{2}, join{LineJoin::JOIN_MITER},
      cap{LineCap::CAP_SQUARE}, radius{5} {}

QnitePen::QnitePen(QObject *parent) : QObject{parent} {}

void QnitePen::setStroke(QColor stroke) {
  if (m_data.stroke != stroke) {
    m_data.stroke = stroke;
    emit strokeChanged();
    emit penChanged();
  }
}

void QnitePen::setFill(QColor fill) {
  if (m_data.fill != fill) {
    m_data.fill = fill;
    emit fillChanged();
    emit penChanged();
  }
}

void QnitePen::setWidth(qreal width) {
  if (m_data.width != width) {
    m_data.width = width;
    emit widthChanged();
    emit penChanged();
  }
}

void QnitePen::setJoin(LineJoin join) {
  if (m_data.join != join) {
    m_data.join = join;
    emit joinChanged();
    emit penChanged();
  }
}

void QnitePen::setCap(LineCap cap) {
  if (m_data.cap != cap) {
    m_data.cap = cap;
    emit capChanged();
    emit penChanged();
  }
}

void QnitePen::setRadius(qreal radius) {
  if (m_data.radius != radius) {
    m_data.radius = radius;
    emit radiusChanged();
    emit penChanged();
  }
}
