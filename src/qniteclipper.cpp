#include "qniteclipper.h"

QniteClipper::QniteClipper(QObject *parent) : QObject(parent) {}

QniteClipper::~QniteClipper() {}

void QniteClipper::clip(const QList<qreal> &xValues,
                        const QList<qreal> &yValues, qreal xLower, qreal xUpper,
                        qreal yLower, qreal yUpper, QList<qreal> &outX,
                        QList<qreal> &outY) {
  int size = qMin(xValues.size(), yValues.size());

  for (int i = 0; i < size; ++i) {
    auto x = xValues.at(i);
    auto y = yValues.at(i);
    if (x >= xLower && x <= xUpper)
      if (y >= yLower && y <= yUpper) {
        outX.append(x);
        outY.append(y);
      }
  }
}

void QniteClipper::clip(const QList<qreal> &values, qreal lower, qreal upper,
                        QList<qreal> &out) {
  for (const auto &v : values) {
    if (v >= lower && v <= upper)
      out.append(v);
  }
}
