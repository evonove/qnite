#ifndef QNITE_ARTIST_H
#define QNITE_ARTIST_H

#include <QQuickItem>

class QniteMapper;
class QniteArtist: public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QList<qreal> xValues READ xValues WRITE setXValues NOTIFY xValuesChanged)
    Q_PROPERTY(QList<qreal> yValues READ yValues WRITE setYValues NOTIFY yValuesChanged)
  public:
    explicit QniteArtist(QQuickItem* parent = 0);
    virtual ~QniteArtist();

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

  Q_SIGNALS:
    void colorChanged();
    void xValuesChanged();
    void yValuesChanged();

  private:
    QColor m_color;
    QList<qreal> m_xValues;
    QList<qreal> m_yValues;
    QniteMapper* m_xMapper;
    QniteMapper* m_yMapper;
};

#endif // QNITE_ARTIST_H

