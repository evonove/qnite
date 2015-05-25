#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qniteartist.h"
#include "qnitetool.h"


QniteAxes::QniteAxes(QQuickItem* parent) :
  QQuickItem(parent),
  m_lowerBottomBound{0},
  m_upperBottomBound{0},
  m_lowerLeftBound{0},
  m_upperLeftBound{0},
  m_canvas{new QQuickItem},
  m_leftAxis{nullptr},
  m_bottomAxis{nullptr}
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


QList<qreal> QniteAxes::bottomBounds() const
{
  return {m_lowerBottomBound, m_upperBottomBound};
}

void QniteAxes::setBottomBounds(const QList<qreal>& bounds)
{
  if (bounds.size() != 2) {
    qWarning() << "bottom bounds should only contain two values";
    return;
  }

  auto lowerBound = bounds.at(0);
  auto upperBound = bounds.at(1);

  if (lowerBound != m_lowerBottomBound || upperBound != m_upperBottomBound) {
    m_lowerBottomBound = lowerBound;
    m_upperBottomBound = upperBound;
    emit bottomBoundsChanged();

    initBottomAxis();
  }
}

QList<qreal> QniteAxes::leftBounds() const
{
  return {m_lowerLeftBound, m_upperLeftBound};
}

void QniteAxes::setLeftBounds(const QList<qreal>& bounds)
{
  if (bounds.size() != 2) {
    qWarning() << "left bounds should only contain two values";
    return;
  }

  auto lowerBound = bounds.at(0);
  auto upperBound = bounds.at(1);

  if (lowerBound != m_lowerLeftBound || upperBound != m_upperLeftBound) {
    m_lowerLeftBound = lowerBound;
    m_upperLeftBound = upperBound;
    emit leftBoundsChanged();

    initLeftAxis();
  }
}

QniteAxis* QniteAxes::leftAxis() const
{
  return m_leftAxis;
}

void QniteAxes::setLeftAxis(QniteAxis* leftAxis)
{
  if (m_leftAxis != leftAxis) {
    m_leftAxis = leftAxis;
    m_leftAxis->setParentItem(this);
    emit leftAxisChanged();

    initLeftAxis();
  }
}

QniteAxis* QniteAxes::bottomAxis() const
{
  return m_bottomAxis;
}

void QniteAxes::setBottomAxis(QniteAxis* bottomAxis)
{
  if (m_bottomAxis != bottomAxis) {
    m_bottomAxis = bottomAxis;
    m_bottomAxis->setParentItem(this);
    emit bottomAxisChanged();

    initBottomAxis();
  }
}

void QniteAxes::initLeftAxis()
{
  if (m_leftAxis == nullptr)
    return;

  m_leftAxis->setLowerBound(m_lowerLeftBound);
  m_leftAxis->setUpperBound(m_upperLeftBound);
}

void QniteAxes::initBottomAxis()
{
  if (m_bottomAxis == nullptr)
    return;

  m_bottomAxis->setLowerBound(m_lowerBottomBound);
  m_bottomAxis->setUpperBound(m_upperBottomBound);
}

void QniteAxes::append_artists(QQmlListProperty<QniteArtist>* property, QniteArtist* value)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    value->setAxes(axes);
    value->setParentItem(axes->canvas()); // TODO: move down into artist?
    axes->m_artists.append(value);
  }
}

QniteArtist* QniteAxes::at_artists(QQmlListProperty<QniteArtist>* property, int index)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    return axes->m_artists.at(index);
  }

  return nullptr;
}

void QniteAxes::clear_artists(QQmlListProperty<QniteArtist>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    axes->m_artists.clear();
  }
}

int QniteAxes::count_artists(QQmlListProperty<QniteArtist>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    return axes->m_artists.count();
  }

  return 0;
}

void QniteAxes::append_tools(QQmlListProperty<QniteTool>* property, QniteTool* value)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    value->setAxes(axes);
    value->setParentItem(axes->canvas()); // TODO: move down into artist?
    axes->m_tools.append(value);
  }
}

QniteTool* QniteAxes::at_tools(QQmlListProperty<QniteTool>* property, int index)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    return axes->m_tools.at(index);
  }

  return nullptr;
}

void QniteAxes::clear_tools(QQmlListProperty<QniteTool>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    axes->m_tools.clear();
  }
}

int QniteAxes::count_tools(QQmlListProperty<QniteTool>* property)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    return axes->m_tools.count();
  }

  return 0;
}

void QniteAxes::setOnTop(QniteArtist * artist)
{
  if (m_artists.contains(artist)) {
    // move the artist down the list so that order in m_artists reflects the
    // order in canvas child list
    m_artists.removeAll(artist);
    m_artists.append(artist);
    // handle visual parenting, move the artist down the children list
    // so that it'll be drawn ontop of others
    artist->setParentItem(nullptr);
    artist->setParentItem(canvas());
  }
}
