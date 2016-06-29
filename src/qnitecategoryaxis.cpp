#include "qnitecategoryaxis.h"
#include "qnitelinearmapper.h"

QniteCategoryAxis::QniteCategoryAxis(QQuickItem* parent):
  QniteAxis{parent}
{
  setMapper(new QniteLinearMapper(this));
}

void QniteCategoryAxis::setValues(const QStringList& v)
{
  if (m_values != v) {
    m_values = v;
    emit valuesChanged();

    processData();
  }
}

void QniteCategoryAxis::processData()
{
  if (mapper() == nullptr) {
    return;
  }

  setLowerBound(0.0);
  setUpperBound(1.0);

  m_majorTicks.clear();

  auto step = 1.0 / (m_values.size() + 1);

  for(auto i = 0; i < m_values.size(); ++i) {
    auto v = mapper()->mapTo(0.0, 1.0, 0.0, size(), step*(i+1), flip());
    m_majorTicks.push_back(v);
  }

  m_labels = m_values;

  emit labelsChanged();
  emit majorTicksChanged();
}
