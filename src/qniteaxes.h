#ifndef QNITE_AXES_H
#define QNITE_AXES_H

#include <QQuickItem>

class QniteArtist;
class QniteAxis;
class QniteTool;
class QniteAxes : public QQuickItem {
  friend class QniteTool;

  Q_OBJECT
  Q_PROPERTY(QQuickItem *canvas READ canvas CONSTANT)
  Q_PROPERTY(
      QList<qreal> xBounds READ xBounds WRITE setXBounds NOTIFY xBoundsChanged)
  Q_PROPERTY(
      QList<qreal> yBounds READ yBounds WRITE setYBounds NOTIFY yBoundsChanged)
  Q_PROPERTY(
      qreal xPadding READ xPadding WRITE setXPadding NOTIFY xPaddingChanged)
  Q_PROPERTY(
      qreal yPadding READ yPadding WRITE setYPadding NOTIFY yPaddingChanged)

  Q_PROPERTY(QQmlListProperty<QniteArtist> artists READ artists)
  Q_PROPERTY(QQmlListProperty<QniteTool> tools READ tools)

  Q_PROPERTY(QniteAxis *axisY READ axisY WRITE setAxisY NOTIFY axisYChanged)
  Q_PROPERTY(QniteAxis *axisX READ axisX WRITE setAxisX NOTIFY axisXChanged)

public:
  explicit QniteAxes(QQuickItem *parent = 0);
  virtual ~QniteAxes() {}

  Q_INVOKABLE void appendArtist(QniteArtist *artist);

  QQuickItem *canvas() const;
  QQmlListProperty<QniteArtist> artists();
  QQmlListProperty<QniteTool> tools();

  void setOnTop(QniteArtist *);

  QList<qreal> xBounds() const;
  void setXBounds(const QList<qreal> &bounds);
  qreal xPadding() const { return m_xPadding; }
  void setXPadding(qreal padding);

  QList<qreal> yBounds() const;
  void setYBounds(const QList<qreal> &bounds);
  qreal yPadding() const { return m_yPadding; }
  void setYPadding(qreal padding);

  QniteAxis *axisY() const;
  void setAxisY(QniteAxis *axisY);
  QniteAxis *axisX() const;
  void setAxisX(QniteAxis *axisX);

Q_SIGNALS:
  void xBoundsChanged();
  void yBoundsChanged();
  void xPaddingChanged();
  void yPaddingChanged();
  void axisYChanged();
  void axisXChanged();

protected:
  void initAxisY();
  void initAxisX();

private:
  static void append_artists(QQmlListProperty<QniteArtist> *property,
                             QniteArtist *value);
  static QniteArtist *at_artists(QQmlListProperty<QniteArtist> *property,
                                 int index);
  static void clear_artists(QQmlListProperty<QniteArtist> *property);
  static int count_artists(QQmlListProperty<QniteArtist> *property);

  static void append_tools(QQmlListProperty<QniteTool> *property,
                           QniteTool *value);
  static QniteTool *at_tools(QQmlListProperty<QniteTool> *property, int index);
  static void clear_tools(QQmlListProperty<QniteTool> *property);
  static int count_tools(QQmlListProperty<QniteTool> *property);

  qreal m_lowerXBound;
  qreal m_upperXBound;
  qreal m_xPadding;
  qreal m_lowerYBound;
  qreal m_upperYBound;
  qreal m_yPadding;

  QQuickItem *m_canvas;

  QList<QniteArtist *> m_artists;
  QList<QniteTool *> m_tools;

  QniteAxis *m_axisX;
  QniteAxis *m_axisY;
};

#endif // QNITE_AXES_H
