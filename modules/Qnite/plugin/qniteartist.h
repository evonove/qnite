#ifndef QNITE_ARTIST_H
#define QNITE_ARTIST_H

#include <QQuickItem>

class QniteAxes;
class QniteArtist: public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QniteAxes* axes READ axes NOTIFY axesChanged)
  public:
    explicit QniteArtist(QQuickItem* parent = 0);
    virtual ~QniteArtist();

    QniteAxes* axes() const;
    void setAxes(QniteAxes* axes);

  public Q_SLOTS:
    virtual void processData() = 0;

  Q_SIGNALS:
    void axesChanged();

  protected:
    virtual void updateAxes();

  private:
    QniteAxes* m_axes;
};

#endif // QNITE_ARTIST_H

