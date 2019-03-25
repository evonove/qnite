#ifndef QNITE_CATEGORY_AXIS_H
#define QNITE_CATEGORY_AXIS_H

#include "qniteaxis.h"

class QniteCategoryAxis : public QniteAxis {
  Q_OBJECT
  Q_PROPERTY(
      QStringList values READ values WRITE setValues NOTIFY valuesChanged)

public:
  explicit QniteCategoryAxis(QQuickItem *parent = 0);
  virtual ~QniteCategoryAxis() {}

  QStringList values() const { return m_values; }
  void setValues(const QStringList &v);

Q_SIGNALS:
  void valuesChanged();

public Q_SLOTS:
  virtual void processData();

private:
  QStringList m_values;
};

#endif // QNITE_CATEGORY_AXIS_H
