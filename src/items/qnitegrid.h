#ifndef QNITEGRID_H
#define QNITEGRID_H


#include "qniteartist.h"


class QniteGrid : public QniteArtist
{
    Q_OBJECT
    Q_PROPERTY(bool drawXAxes READ drawXAxes WRITE setDrawXAxes NOTIFY drawXAxesChanged)
    Q_PROPERTY(bool drawYAxes READ drawYAxes WRITE setDrawYAxes NOTIFY drawYAxesChanged)

public:
    bool drawXAxes() const { return m_drawXAxes; } // get the m_drawXAxes value
    bool drawYAxes() const { return m_drawYAxes; } // get the m_drawYAxes value

    void setDrawXAxes(bool value); // set the drawXAxes value
    void setDrawYAxes(bool value); // set the drawYAxes value

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
