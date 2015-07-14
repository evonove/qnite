#ifndef QNITE_AXIS_H
#define QNITE_AXIS_H

#include "qniteartist.h"

class QniteAxisTick;
class QniteMapper;
class QniteTicker;
class QniteAxis: public QniteArtist
{
  Q_OBJECT

  Q_PROPERTY(qreal size READ size WRITE setSize NOTIFY sizeChanged)
  Q_PROPERTY(qreal lowerBound READ lowerBound WRITE setLowerBound NOTIFY lowerBoundChanged)
  Q_PROPERTY(qreal upperBound READ upperBound WRITE setUpperBound NOTIFY upperBoundChanged)
  Q_PROPERTY(bool flip READ flip WRITE setFlip NOTIFY flipChanged)

  Q_PROPERTY(QniteAxisTick* tick READ tick CONSTANT)
  Q_PROPERTY(QniteMapper* mapper READ mapper CONSTANT)
  Q_PROPERTY(QniteTicker* ticker READ ticker CONSTANT)

  Q_PROPERTY(QList<qreal> majorTicks READ majorTicks NOTIFY majorTicksChanged)
  Q_PROPERTY(QList<qreal> minorTicks READ minorTicks NOTIFY minorTicksChanged)

public:
  explicit QniteAxis(QQuickItem* parent = 0);
  virtual ~QniteAxis();

  qreal size() const;
  void setSize(qreal size);
  qreal lowerBound() const;
  void setLowerBound(qreal bound);
  qreal upperBound() const;
  void setUpperBound(qreal bound);
  bool flip() const;
  void setFlip(bool flip);

  QniteAxisTick* tick() const;
  QniteTicker* ticker() const;
  QniteMapper* mapper() const;

  QList<qreal> majorTicks() const;
  QList<qreal> minorTicks() const;

  qreal position() const;

Q_SIGNALS:
  void flipChanged();
  void sizeChanged();
  void lowerBoundChanged();
  void upperBoundChanged();

  void mapperChanged();
  void majorTicksChanged();
  void minorTicksChanged();

public Q_SLOTS:
  virtual void processData();

private:
  qreal m_size;
  qreal m_lowerBound;
  qreal m_upperBound;
  bool m_flip;
  qreal m_position;

  QniteAxisTick* m_tick;
  QniteMapper* m_mapper;
  QniteTicker* m_ticker;

  QList<qreal> m_majorTicks;
  QList<qreal> m_minorTicks;
};

#endif // QNITE_AXIS_H
