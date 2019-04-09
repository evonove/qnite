#include "qniteclipper.h"

QniteClipper::QniteClipper(QObject *parent) : QObject(parent) {}

QniteClipper::~QniteClipper() {}

void QniteClipper::clip(const QMap<int, qreal> &xValues,
                        const QMap<int, qreal> &yValues, qreal xLower,
                        qreal xUpper, qreal yLower, qreal yUpper,
                        QMap<int, qreal> &outX, QMap<int, qreal> &outY) {
  // Assume x and y values have same ids
  auto ids = xValues.keys();

  for (auto id : ids) {
    auto x = xValues.value(id);
    auto y = yValues.value(id);
    if (x >= xLower && x <= xUpper) {
      if (y >= yLower && y <= yUpper) {
        outX.insert(id, x);
        outY.insert(id, y);
      }
    }
  }
}

void QniteClipper::clip(const QList<qreal> &xValues,
                        const QList<qreal> &yValues, qreal xLower, qreal xUpper,
                        qreal yLower, qreal yUpper, QList<qreal> &outX,
                        QList<qreal> &outY) {

  int size = qMin(xValues.size(), yValues.size());

  for (int i = 0; i < size; i++) {
    auto x = xValues.at(i);
    auto y = yValues.at(i);
    if (x >= xLower && x <= xUpper) {
      if (y >= yLower && y <= yUpper) {
        outX << x;
        outY << y;
      }
    }
  }
}

void QniteClipper::clip(const QMap<int, qreal> &values, qreal lower,
                        qreal upper, QMap<int, qreal> &out) {

  auto it = values.constBegin();
  while (it != values.constEnd()) {
    auto v = it.value();
    if (v >= lower && v <= upper) {
      out.insert(it.key(), v);
    }
    it++;
  }
}

void QniteClipper::clip(const QList<qreal> &values, qreal lower, qreal upper,
                        QList<qreal> &out) {
  for (auto v : values) {
    if (v >= lower && v <= upper) {
      out << v;
    }
  }
}
