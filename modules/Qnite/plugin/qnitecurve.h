#ifndef QNITE_CURVE_H
#define QNITE_CURVE_H


#include <QQuickItem>


class QniteScaleMap;
class QniteCurve : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(QniteCurve)

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QVariantList xValues READ xValues WRITE setXValues NOTIFY xValuesChanged)
    Q_PROPERTY(QniteScaleMap* scaleMap READ scaleMap WRITE setScaleMap NOTIFY scaleMapChanged)

  public:
    explicit QniteCurve(QQuickItem *parent = 0);
    virtual ~QniteCurve();

    QColor color() const;
    void setColor(const QColor& color);

    QVariantList xValues();
    void setXValues(const QVariantList& values);

    QniteScaleMap* scaleMap() const;
    void setScaleMap(QniteScaleMap* scaleMap);

  signals:
    void colorChanged();
    void xValuesChanged();
    void scaleMapChanged();

  protected:
    QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);

  private:
    QColor m_color;
    QVariantList m_xValues;
    QniteScaleMap* m_scaleMap;
};


#endif // QNITE_CURVE_H

