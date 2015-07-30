#ifndef QNITE_AXIS_H
#define QNITE_AXIS_H

#include "qniteartist.h"

class QniteMapper;
class QniteTicker;
class QniteAxis: public QniteArtist
{
  Q_OBJECT
  Q_PROPERTY(qreal size READ size WRITE setSize NOTIFY sizeChanged)
  Q_PROPERTY(qreal lowerBound READ lowerBound WRITE setLowerBound NOTIFY lowerBoundChanged)
  Q_PROPERTY(qreal upperBound READ upperBound WRITE setUpperBound NOTIFY upperBoundChanged)
  Q_PROPERTY(bool flip READ flip WRITE setFlip NOTIFY flipChanged)

  Q_PROPERTY(QniteMapper* mapper READ mapper CONSTANT)
  Q_PROPERTY(QniteTicker* ticker READ ticker CONSTANT)

  Q_PROPERTY(QList<qreal> majorTicks READ majorTicks NOTIFY majorTicksChanged)
  Q_PROPERTY(QList<qreal> minorTicks READ minorTicks NOTIFY minorTicksChanged)
  Q_PROPERTY(QStringList labels READ labels NOTIFY labelsChanged)

public:
  explicit QniteAxis(QQuickItem* parent = 0);
  virtual ~QniteAxis() {}

  qreal size() const { return m_size; }
  void setSize(qreal size);
  qreal lowerBound() const { return m_lowerBound; }
  void setLowerBound(qreal bound);
  qreal upperBound() const { return m_upperBound; }
  void setUpperBound(qreal bound);
  bool flip() const { return m_flip; }
  void setFlip(bool flip);

  QniteTicker* ticker() const { return m_ticker; }
  void setTicker(QniteTicker* ticker);
  QniteMapper* mapper() const { return m_mapper; }
  void setMapper(QniteMapper* mapper);

  QList<qreal> majorTicks() const;
  QList<qreal> minorTicks() const;

  QStringList labels() const { return m_labels; }

  qreal position() const;

Q_SIGNALS:
  void flipChanged();
  void sizeChanged();
  void lowerBoundChanged();
  void upperBoundChanged();

  void majorTicksChanged();
  void minorTicksChanged();

  void tickerChanged();
  void mapperChanged();

  void labelsChanged();

protected:
  qreal m_size;
  qreal m_lowerBound;
  qreal m_upperBound;
  bool m_flip;
  qreal m_position;

  QList<qreal> m_majorTicks;
  QList<qreal> m_minorTicks;

  QniteMapper* m_mapper;
  QniteTicker* m_ticker;

  QStringList m_labels;
};

#endif // QNITE_AXIS_H
