#include "qnitecurve.h"
#include "qnitescalemap.h"

#include <QDebug>

#include <QSGGeometry>
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>


QniteCurve::QniteCurve(QQuickItem *parent):
  QQuickItem(parent),
  m_scaleMap(0)
{
  setFlag(ItemHasContents, true);
}

QniteCurve::~QniteCurve()
{
}

QColor QniteCurve::color() const
{
  return m_color;
}

void QniteCurve::setColor(const QColor& color)
{
  if (m_color != color) {
    m_color = color;
    emit colorChanged();
  }
}

QVariantList QniteCurve::xValues()
{
  return m_xValues;
}

void QniteCurve::setXValues(const QVariantList& values)
{
  m_xValues = values;
  emit xValuesChanged();
}

QniteScaleMap* QniteCurve::scaleMap() const
{
  return m_scaleMap;
}

void QniteCurve::setScaleMap(QniteScaleMap* scaleMap)
{
  if (scaleMap != m_scaleMap) {
    m_scaleMap = scaleMap;
    emit scaleMapChanged();
  }
}

QSGNode* QniteCurve::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*)
{
  QSGGeometryNode *node = 0;
  QSGGeometry *geometry = 0;

  if (!oldNode) {
    node = new QSGGeometryNode;
    geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), m_xValues.size());
    geometry->setLineWidth(3);
    geometry->setDrawingMode(GL_LINE_STRIP);
    node->setGeometry(geometry);
    node->setFlag(QSGNode::OwnsGeometry);

    QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
    material->setColor(m_color);
    node->setMaterial(material);
    node->setFlag(QSGNode::OwnsMaterial);
  } else {
    node = static_cast<QSGGeometryNode *>(oldNode);
    geometry = node->geometry();
    geometry->allocate(m_xValues.size());
  }

  QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
  for(int i = 0; i < m_xValues.size(); ++i) {
    const QVariant& v = m_xValues.at(i);

    // TODO: this is bad here! move transformation elsewhere
    qreal value;
    if (m_scaleMap)
      value = m_scaleMap->transform(v.toReal());
    else
      value = v.toReal();

    vertices[i].set(static_cast<float>(value), i*10);
    qDebug() << "point" << value << i*10;
  }

  node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

  return node;
}

