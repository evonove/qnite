#ifndef QNITE_ARTIST_H
#define QNITE_ARTIST_H

#include <QQuickItem>

class QniteAxes;
class QniteMapper;
class QniteArtist: public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QniteAxes* axes READ axes NOTIFY axesChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QList<qreal> xValues READ xValues WRITE setXValues NOTIFY xValuesChanged)
    Q_PROPERTY(QList<qreal> yValues READ yValues WRITE setYValues NOTIFY yValuesChanged)
  public:
    explicit QniteArtist(QQuickItem* parent = 0);
    virtual ~QniteArtist();

    QniteAxes* axes() const;
    void setAxes(QniteAxes* axes);

    QColor color() const;
    void setColor(const QColor& color);

    QList<qreal> xValues();
    void setXValues(const QList<qreal>& values);
    QList<qreal> yValues();
    void setYValues(const QList<qreal>& values);

    QniteMapper* xMapper() const;
    void setXMapper(QniteMapper* mapper);
    QniteMapper* yMapper() const;
    void setYMapper(QniteMapper* mapper);

    const QList<qreal>& xMapped() const;
    const QList<qreal>& yMapped() const;

  public Q_SLOTS:
    virtual void processData();

  Q_SIGNALS:
    void axesChanged();
    void colorChanged();
    void xValuesChanged();
    void yValuesChanged();

  private:
    QniteAxes* m_axes;
    QColor m_color;
    QList<qreal> m_xValues;
    QList<qreal> m_yValues;
    QniteMapper* m_xMapper;
    QniteMapper* m_yMapper;

    QList<qreal> m_xMapped;
    QList<qreal> m_yMapped;
};

#endif // QNITE_ARTIST_H

