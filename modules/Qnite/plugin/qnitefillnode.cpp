#include "qnitefillnode.h"

#include <QDebug>
#include <QSGFlatColorMaterial>

QniteFillNode::QniteFillNode(QColor color):
  m_geometry(QSGGeometry::defaultAttributes_Point2D(), 0)
{
  setGeometry(&m_geometry);
  m_geometry.setDrawingMode(GL_TRIANGLE_STRIP);

  auto material = new QSGFlatColorMaterial;
  material->setColor(color);
  setMaterial(material);
  setFlag(QSGNode::OwnsMaterial);
}

void QniteFillNode::updateGeometry(const QList<qreal>& xs, const QList<qreal>& ys, qreal yBaseline)
{
  qDebug() << "updating fill node geometry";

  QList<qreal> xv;
  QList<qreal> yv;

  for(int i = 0; i < xs.size() - 1; ++i) {
    qreal y1 = ys.at(i);
    qreal y2 = ys.at(i+1);
    qreal x1 = xs.at(i);
    qreal x2 = xs.at(i+1);

    xv.push_back(x1);
    yv.push_back(y1);

    // checks if segment intersect y axis line
    if ((y1 < yBaseline && y2 > yBaseline) ||
        (y1 > yBaseline && y2 < yBaseline)) {

      // find the x of the intersection point
      qreal x = (x2 - x1)*(yBaseline - y1) / (y2 - y1) + x1;

      xv.push_back(x);
      yv.push_back(yBaseline);
    }
  }
  xv.push_back(xs.back());
  yv.push_back(ys.back());

  int dataSize = xv.size();
  m_geometry.allocate(dataSize * 2);
  QSGGeometry::Point2D *vertices = m_geometry.vertexDataAsPoint2D();
  for(int i = 0; i < dataSize; ++i) {
    vertices[i*2+0].set(xv.at(i), yBaseline);
    vertices[i*2+1].set(xv.at(i), yv.at(i));
  }

  markDirty(QSGNode::DirtyGeometry);
}

