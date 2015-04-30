#include "qnitecircle.h"
#include "qnitemapper.h"
#include "qnitecirclenode.h"
#include "qniteaxes.h"
#include "qniteaxis.h"

#include <QDebug>


QniteCircle::QniteCircle(QQuickItem *parent):
  QniteArtist(parent),
  m_radius{10}
{
  setFlag(ItemHasContents, true);
}

QniteCircle::~QniteCircle()
{
}

qreal QniteCircle::radius() const
{
  return m_radius;
}

void QniteCircle::setRadius(qreal radius)
{
  if (m_radius != radius) {
    m_radius = radius;
    emit radiusChanged();
  }
}

QSGNode* QniteCircle::updatePaintNode(QSGNode* node, UpdatePaintNodeData*)
{
  if (!node) {
    node = new QSGNode;
  }

  // TODO: move this to qniteartist
  int dataSize = qMin(xValues().size(), yValues().size());
  if (xValues().size() != yValues().size())
    qWarning() << "xValues and yValues size for the artists are different";

  // TODO: move the transform into a pipeline
  qreal xLower = axes()->bottomAxis()->lowerBound();
  qreal xUpper = axes()->bottomAxis()->upperBound();
  qreal yLower = axes()->leftAxis()->lowerBound();
  qreal yUpper = axes()->leftAxis()->upperBound();

  node->removeAllChildNodes();
  for(int i = 0; i < dataSize; ++i) {
    // map the center coordinates
    qreal cx = xMapper()->mapTo(xLower, xUpper, 0, width(), xValues().at(i));
    qreal cy = yMapper()->mapTo(yLower, yUpper, 0, height(), yValues().at(i), true);

    // TODO: optimal number of segments should be  computed runtime
    node->appendChildNode(new QniteCircleNode(cx, cy, m_radius, 32, color()));
  }

  return node;
}

