#include "qniteaxistick.h"

/*! TODO: add docs
 */
QniteAxisTick::QniteAxisTick(QObject *parent)
    : QObject(parent), m_thick{0}, m_majSize{0}, m_minSize{0} {}

QniteAxisTick::~QniteAxisTick() {}

qreal QniteAxisTick::thick() const { return m_thick; }

void QniteAxisTick::setThick(qreal thick) {
  if (m_thick != thick) {
    m_thick = thick;
    emit thickChanged();
  }
}

qreal QniteAxisTick::majSize() const { return m_majSize; }

void QniteAxisTick::setMajSize(qreal size) {
  if (m_majSize != size) {
    m_majSize = size;
    emit majSizeChanged();
  }
}

qreal QniteAxisTick::minSize() const { return m_minSize; }

void QniteAxisTick::setMinSize(qreal size) {
  if (m_minSize != size) {
    m_minSize = size;
    emit minSizeChanged();
  }
}

QColor QniteAxisTick::color() const { return m_color; }

void QniteAxisTick::setColor(const QColor &color) {
  if (m_color != color) {
    m_color = color;
    emit colorChanged();
  }
}
