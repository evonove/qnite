#ifndef QNITE_AXIS_TICK_H
#define QNITE_AXIS_TICK_H

#include <QObject>
#include <QColor>

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
  void minSizeChanged();
  void colorChanged();

private:
  qreal m_thick;
  qreal m_majSize;
  qreal m_minSize;
  QColor m_color;
};

#endif  // QNITE_AXIS_TICK_H
