#ifndef QNITE_AXES_H
#define QNITE_AXES_H

#include <QQuickItem>

class QniteArtist;
class QniteAxis;
class QniteAxes: public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QniteArtist> artists READ artists)
    Q_PROPERTY(QniteAxis* yLeft READ yLeft WRITE setYLeft NOTIFY yLeftChanged)
    Q_PROPERTY(QniteAxis* xBottom READ xBottom WRITE setXBottom NOTIFY xBottomChanged)
  public:
    explicit QniteAxes(QQuickItem* parent = 0);
    virtual ~QniteAxes();

    QQmlListProperty<QniteArtist> artists();

    QniteAxis* yLeft() const;
    void setYLeft(QniteAxis* yLeft);
    QniteAxis* xBottom() const;
    void setXBottom(QniteAxis* xBottom);

  Q_SIGNALS:
    void yLeftChanged();
    void xBottomChanged();

  protected:
    void bindToXBottom();
    void bindToYLeft();

  private:
    static void append_artists(QQmlListProperty<QniteArtist>* property, QniteArtist* value);
    static QniteArtist* at_artists(QQmlListProperty<QniteArtist>* property, int index);
    static void clear_artists(QQmlListProperty<QniteArtist>* property);
    static int count_artists(QQmlListProperty<QniteArtist>* property);

    QList<QniteArtist*> m_artists;
    QniteAxis* m_yLeft;
    QniteAxis* m_xBottom;
};

#endif // QNITE_AXES_H
