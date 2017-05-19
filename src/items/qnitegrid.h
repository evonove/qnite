#ifndef QNITEGRID_H
#define QNITEGRID_H


#include "qniteartist.h"


class QniteGrid : public QniteArtist
{
    Q_OBJECT
    Q_PROPERTY(bool drawXAxes READ drawXAxes WRITE setDrawXAxes NOTIFY drawXAxesChanged)
    Q_PROPERTY(bool drawYAxes READ drawYAxes WRITE setDrawYAxes NOTIFY drawYAxesChanged)

public:
    bool drawXAxes() const { return m_drawXAxes; } // dafault value is false and allows you to draw axes x if the value changes to true
    bool drawYAxes() const { return m_drawYAxes; } // dafault value is false and allows you to draw axes y if the value changes to true

    void setDrawXAxes(bool value);
    void setDrawYAxes(bool value);

    QniteGrid(QQuickItem* parent = Q_NULLPTR);

    QNanoQuickItemPainter* createItemPainter() const Q_DECL_OVERRIDE;

public Q_SLOTS:
  virtual void processData() Q_DECL_OVERRIDE {}

Q_SIGNALS:
    void drawXAxesChanged(); // this signal is emitted when the m_drawXaxes value changes
    void drawYAxesChanged(); // this signal is emitted when the m_drawYaxes value changes

private:
    bool m_drawXAxes;
    bool m_drawYAxes;
};


#endif // QNITEGRID_H
