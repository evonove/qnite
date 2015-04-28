#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qniteartist.h"


QniteAxes::QniteAxes(QQuickItem* parent) :
  QQuickItem(parent),
  m_lowerBottomBound{0},
  m_upperBottomBound{0},
  m_lowerLeftBound{0},
  m_upperLeftBound{0},
  m_leftAxis{nullptr},
  m_bottomAxis{nullptr}
{
}

QniteAxes::~QniteAxes()
{
}

QQmlListProperty<QniteArtist> QniteAxes::artists()
{
  return QQmlListProperty<QniteArtist>(this, nullptr,
                                       &QniteAxes::append_artists,
                                       &QniteAxes::count_artists,
                                       &QniteAxes::at_artists,
                                       &QniteAxes::clear_artists);
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

    // TODO: use signals?
    initLeftAxis();
    this->bindToLeftAxis();
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

    // TODO: use signals?
    initBottomAxis();
    bindToBottomAxis();
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

void QniteAxes::bindToBottomAxis()
{
  if (this->bottomAxis() == nullptr)
    return;

  for(const auto& artist: m_artists) {
    artist->setXMapper(this->bottomAxis()->mapper());
  }
}

void QniteAxes::bindToLeftAxis()
{
  if (this->leftAxis() == nullptr)
    return;

  for(const auto& artist: m_artists) {
    artist->setYMapper(this->leftAxis()->mapper());
  }
}

void QniteAxes::append_artists(QQmlListProperty<QniteArtist>* property, QniteArtist* value)
{
  QniteAxes* axes = qobject_cast<QniteAxes*>(property->object);
  if (axes != nullptr) {
    value->setParentItem(axes);
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

