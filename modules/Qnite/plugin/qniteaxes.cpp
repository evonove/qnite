#include "qniteaxes.h"
#include "qniteaxis.h"
#include "qniteartist.h"


QniteAxes::QniteAxes(QQuickItem* parent) :
  QQuickItem(parent),
  m_yLeft{nullptr},
  m_xBottom{nullptr}
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

QniteAxis* QniteAxes::yLeft() const
{
  return m_yLeft;
}
void QniteAxes::setYLeft(QniteAxis* yLeft)
{
  if (m_yLeft != yLeft) {
    m_yLeft = yLeft;
    m_yLeft->setParentItem(this);
    this->bindToYLeft();
    emit yLeftChanged();
  }
}

QniteAxis* QniteAxes::xBottom() const
{
  return m_xBottom;
}
void QniteAxes::setXBottom(QniteAxis* xBottom)
{
  if (m_xBottom != xBottom) {
    m_xBottom = xBottom;
    m_xBottom->setParentItem(this);
    this->bindToXBottom();
    emit xBottomChanged();
  }
}

void QniteAxes::bindToXBottom()
{
  if (this->xBottom() == nullptr)
    return;

  for(const auto& artist: m_artists) {
    artist->setXMapper(this->xBottom()->mapper());
  }
}

void QniteAxes::bindToYLeft()
{
  if (this->yLeft() == nullptr)
    return;

  for(const auto& artist: m_artists) {
    artist->setYMapper(this->yLeft()->mapper());
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
