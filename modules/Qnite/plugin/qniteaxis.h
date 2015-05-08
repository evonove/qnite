#ifndef QNITE_AXIS_H
#define QNITE_AXIS_H

#include "qniteartist.h"

class QniteAxisTick: public QObject
{
  Q_OBJECT

  Q_PROPERTY(qreal thick READ thick WRITE setThick NOTIFY thickChanged)
  Q_PROPERTY(qreal majSize READ majSize WRITE setMajSize NOTIFY majSizeChanged)
  Q_PROPERTY(qreal minSize READ minSize WRITE setMinSize NOTIFY minSizeChanged)
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
  explicit QniteAxisTick(QObject* parent = 0);
  virtual ~QniteAxisTick();

  qreal thick() const;
  void setThick(qreal thick);
  qreal majSize() const;
  void setMajSize(qreal size);
  qreal minSize() const;
  void setMinSize(qreal size);

  QColor color() const;
  void setColor(const QColor& color);

Q_SIGNALS:
  void thickChanged();
  void majSizeChanged();
  void midSizeChanged();
  void minSizeChanged();
  void colorChanged();

private:
  qreal m_thick;
  qreal m_majSize;
  qreal m_midSize;
  qreal m_minSize;
  QColor m_color;
};

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
  qreal m_flip;

  QniteAxisTick* m_tick;
  QniteMapper* m_mapper;
  QniteTicker* m_ticker;

  QList<qreal> m_majorTicks;
  QList<qreal> m_minorTicks;
};

#endif // QNITE_AXIS_H
