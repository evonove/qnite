#ifndef QNITE_XY_ARTIST_H
#define QNITE_XY_ARTIST_H

#include "qniteartist.h"

class QniteClipper;
class QniteMapper;
class QniteXYArtist: public QniteArtist
{
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
  Q_PROPERTY(QColor selectionColor READ selectionColor WRITE setSelectionColor NOTIFY selectionColorChanged)
  Q_PROPERTY(QList<qreal> xValues READ xValues WRITE setXValues NOTIFY xValuesChanged)
  Q_PROPERTY(QList<qreal> yValues READ yValues WRITE setYValues NOTIFY yValuesChanged)

public:
  explicit QniteXYArtist(QQuickItem* parent = 0);
  virtual ~QniteXYArtist();

  QColor color() const;
  void setColor(const QColor& color);
  QColor selectionColor() const;
  void setSelectionColor(const QColor&);

  const QList<qreal>& xValues();
  void setXValues(const QList<qreal>& values);
  const QList<qreal>& yValues();
  void setYValues(const QList<qreal>& values);

  QniteMapper* xMapper() const;
  void setXMapper(QniteMapper* mapper);
  QniteMapper* yMapper() const;
  void setYMapper(QniteMapper* mapper);
  QniteClipper* clipper() const;
  void setClipper(QniteClipper* clipper);

  const QList<qreal>& xMapped() const;
  const QList<qreal>& yMapped() const;

  const QList<qreal>& xProcessed() const;
  const QList<qreal>& yProcessed() const;

public Q_SLOTS:
  virtual void processData();

Q_SIGNALS:
  void colorChanged();
  void selectionColorChanged();
  void xValuesChanged();
  void yValuesChanged();

protected:
  virtual void updateAxes();

  QList<qreal> m_xMapped;
  QList<qreal> m_yMapped;

  QList<qreal> m_xProcessed;
  QList<qreal> m_yProcessed;

private:
  QColor m_color;
  QColor m_selectionColor;

  QList<qreal> m_xValues;
  QList<qreal> m_yValues;

  QniteClipper* m_clipper;
  QniteMapper* m_xMapper;
  QniteMapper* m_yMapper;
};

#endif // QNITE_XY_ARTIST_H

