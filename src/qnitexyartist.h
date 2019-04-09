#ifndef QNITE_XY_ARTIST_H
#define QNITE_XY_ARTIST_H

#include "qniteartist.h"

class QniteClipper;
class QniteMapper;
class QniteXYArtist : public QniteArtist {
  Q_OBJECT
  // clang-format off
  Q_PROPERTY(QList<qreal> xValues READ xValues WRITE setXValues NOTIFY xValuesChanged)
  Q_PROPERTY(QList<qreal> yValues READ yValues WRITE setYValues NOTIFY yValuesChanged)
  // clang-format on

public:
  explicit QniteXYArtist(QQuickItem *parent = nullptr);
  virtual ~QniteXYArtist() Q_DECL_OVERRIDE;

  QList<qreal> xValues();
  void setXValues(const QList<qreal> &values);
  QList<qreal> yValues();
  void setYValues(const QList<qreal> &values);

  QniteMapper *xMapper() const;
  void setXMapper(QniteMapper *mapper);
  QniteMapper *yMapper() const;
  void setYMapper(QniteMapper *mapper);
  QniteClipper *clipper() const;
  void setClipper(QniteClipper *clipper);

  QMap<int, qreal> xMapped() const;
  QMap<int, qreal> yMapped() const;

  QList<qreal> xProcessed() const;
  QList<qreal> yProcessed() const;

public Q_SLOTS:
  virtual void processData() Q_DECL_OVERRIDE;

Q_SIGNALS:
  void xValuesChanged();
  void yValuesChanged();

protected:
  virtual void updateAxes() Q_DECL_OVERRIDE;

  QMap<int, qreal> m_xMapped;
  QMap<int, qreal> m_yMapped;

  QList<qreal> m_xProcessed;
  QList<qreal> m_yProcessed;

  QMap<int, qreal> m_xValues;
  QMap<int, qreal> m_yValues;

private:
  QniteClipper *m_clipper;
  QniteMapper *m_xMapper;
  QniteMapper *m_yMapper;
};

#endif // QNITE_XY_ARTIST_H
