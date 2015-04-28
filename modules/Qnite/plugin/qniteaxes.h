#ifndef QNITE_AXES_H
#define QNITE_AXES_H

#include <QQuickItem>

class QniteArtist;
class QniteAxis;
class QniteAxes: public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QList<qreal> bottomBounds READ bottomBounds WRITE setBottomBounds NOTIFY bottomBoundsChanged)
    Q_PROPERTY(QList<qreal> leftBounds READ leftBounds WRITE setLeftBounds NOTIFY leftBoundsChanged)

    Q_PROPERTY(QQmlListProperty<QniteArtist> artists READ artists)
    Q_PROPERTY(QniteAxis* leftAxis READ leftAxis WRITE setLeftAxis NOTIFY leftAxisChanged)
    Q_PROPERTY(QniteAxis* bottomAxis READ bottomAxis WRITE setBottomAxis NOTIFY bottomAxisChanged)
  public:
    explicit QniteAxes(QQuickItem* parent = 0);
    virtual ~QniteAxes();

    QQmlListProperty<QniteArtist> artists();

    QList<qreal> bottomBounds() const;
    void setBottomBounds(const QList<qreal>& bounds);
    QList<qreal> leftBounds() const;
    void setLeftBounds(const QList<qreal>& bounds);

    QniteAxis* leftAxis() const;
    void setLeftAxis(QniteAxis* leftAxis);
    QniteAxis* bottomAxis() const;
    void setBottomAxis(QniteAxis* bottomAxis);

  Q_SIGNALS:
    void bottomBoundsChanged();
    void leftBoundsChanged();
    void leftAxisChanged();
    void bottomAxisChanged();

  protected:
    void initLeftAxis();
    void initBottomAxis();
    void bindToBottomAxis();
    void bindToLeftAxis();

  private:
    static void append_artists(QQmlListProperty<QniteArtist>* property, QniteArtist* value);
    static QniteArtist* at_artists(QQmlListProperty<QniteArtist>* property, int index);
    static void clear_artists(QQmlListProperty<QniteArtist>* property);
    static int count_artists(QQmlListProperty<QniteArtist>* property);

    qreal m_lowerBottomBound;
    qreal m_upperBottomBound;
    qreal m_lowerLeftBound;
    qreal m_upperLeftBound;

    QList<QniteArtist*> m_artists;
    QniteAxis* m_leftAxis;
    QniteAxis* m_bottomAxis;
};

#endif // QNITE_AXES_H
