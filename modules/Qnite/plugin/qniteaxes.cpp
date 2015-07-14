#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qniteartist.h"
#include "qnitetool.h"


QniteAxes::QniteAxes(QQuickItem* parent) :
  QQuickItem(parent),
  m_lowerXBound{0},
  m_upperXBound{0},
  m_lowerYBound{0},
  m_upperYBound{0},
  m_canvas{new QQuickItem},
  m_axisX{nullptr},
  m_axisY{nullptr}
{
  m_canvas->setParentItem(this);
  m_canvas->setClip(true);

  connect(this, &QQuickItem::widthChanged, [=](){ this->m_canvas->setWidth(width()); });
  connect(this, &QQuickItem::heightChanged, [=](){ this->m_canvas->setHeight(height()); });
}

void QniteAxes::appendArtist(QniteArtist* artist)
{
  if (artist != nullptr) {
    auto a = this->artists();
    a.append(&a, artist);
  }
}

QQuickItem* QniteAxes::canvas() const
{
  return m_canvas;
}

QQmlListProperty<QniteArtist> QniteAxes::artists()
{
  return QQmlListProperty<QniteArtist>(this, nullptr,
                                       &QniteAxes::append_artists,
                                       &QniteAxes::count_artists,
                                       &QniteAxes::at_artists,
                                       &QniteAxes::clear_artists);
}

QQmlListProperty<QniteTool> QniteAxes::tools()
{
  return QQmlListProperty<QniteTool>(this, nullptr,
                                     &QniteAxes::append_tools,
                                     &QniteAxes::count_tools,
                                     &QniteAxes::at_tools,
                                     &QniteAxes::clear_tools);
}


QList<qreal> QniteAxes::xBounds() const
{
  return {m_lowerXBound, m_upperXBound};
}

void QniteAxes::setXBounds(const QList<qreal>& bounds)
{
  if (bounds.size() != 2) {
    qWarning() << "bottom bounds should only contain two values";
    return;
  }

  auto lowerBound = bounds.at(0);
  auto upperBound = bounds.at(1);

  if (lowerBound != m_lowerXBound || upperBound != m_upperXBound) {
    m_lowerXBound = lowerBound;
    m_upperXBound = upperBound;
    emit xBoundsChanged();

    initAxisX();
  }
}

QList<qreal> QniteAxes::yBounds() const
{
  return {m_lowerYBound, m_upperYBound};
}

void QniteAxes::setYBounds(const QList<qreal>& bounds)
{
  if (bounds.size() != 2) {
    qWarning() << "left bounds should only contain two values";
    return;
  }

  auto lowerBound = bounds.at(0);
  auto upperBound = bounds.at(1);

  if (lowerBound != m_lowerYBound || upperBound != m_upperYBound) {
    m_lowerYBound = lowerBound;
    m_upperYBound = upperBound;
    emit yBoundsChanged();

    initAxisY();
  }
}

QniteAxis* QniteAxes::axisY() const
{
  return m_axisY;
}

void QniteAxes::setAxisY(QniteAxis* axisY)
{
  if (m_axisY != axisY) {
    m_axisY = axisY;
    m_axisY->setParentItem(this);
    emit axisYChanged();

    initAxisY();
  }
}

QniteAxis* QniteAxes::axisX() const
{
  return m_axisX;
}

void QniteAxes::setAxisX(QniteAxis* axisX)
{
  if (m_axisX != axisX) {
    m_axisX = axisX;
    m_axisX->setParentItem(this);
    emit axisXChanged();

    initAxisX();
  }
}

void QniteAxes::initAxisY()
{
  if (m_axisY == nullptr)
    return;

  m_axisY->setLowerBound(m_lowerYBound);
  m_axisY->setUpperBound(m_upperYBound);
}

void QniteAxes::initAxisX()
{
  if (m_axisX == nullptr)
    return;

  m_axisX->setLowerBound(m_lowerXBound);
  m_axisX->setUpperBound(m_upperXBound);
}

void QniteAxes::append_artists(QQmlListProperty<QniteArtist>* property, QniteArtist* value)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  value->setAxes(axes);
  value->setParentItem(axes->canvas()); // TODO: move down into artist?
  axes->m_artists.append(value);
}

QniteArtist* QniteAxes::at_artists(QQmlListProperty<QniteArtist>* property, int index)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  return axes->m_artists.at(index);
}

void QniteAxes::clear_artists(QQmlListProperty<QniteArtist>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  while (!axes->m_artists.isEmpty())
    delete axes->m_artists.takeFirst();
}

int QniteAxes::count_artists(QQmlListProperty<QniteArtist>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  return axes->m_artists.count();
}

void QniteAxes::append_tools(QQmlListProperty<QniteTool>* property, QniteTool* value)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  value->setAxes(axes);
  value->setParentItem(axes->canvas()); // TODO: move down into artist?
  axes->m_tools.append(value);
}

QniteTool* QniteAxes::at_tools(QQmlListProperty<QniteTool>* property, int index)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  return axes->m_tools.at(index);
}

void QniteAxes::clear_tools(QQmlListProperty<QniteTool>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  while (!axes->m_tools.isEmpty())
    delete axes->m_tools.takeFirst();
}

int QniteAxes::count_tools(QQmlListProperty<QniteTool>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  return axes->m_tools.count();
}

void QniteAxes::setOnTop(QniteArtist * artist)
{
  if (canvas()->childItems().isEmpty())
    return;

  if (m_artists.contains(artist)) {
    // the item is moved at the end of the list. This is NEEDED so that
    // items in the back that may be hidden are processed before the items
    // in foreground, allowing their selection.
    m_artists.removeAll(artist);
    m_artists.append(artist);

    // handle visual parenting, move the artist down the children list
    // so that it'll be drawn ontop of others
    auto lastItem = canvas()->childItems().last();
    if (artist != lastItem)
      artist->stackAfter(lastItem);
  }
}
