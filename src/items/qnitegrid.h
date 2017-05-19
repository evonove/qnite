#ifndef QNITEGRID_H
#define QNITEGRID_H


#include "qniteartist.h"


class QniteGrid : public QniteArtist
{
    Q_OBJECT
    Q_PROPERTY(bool drawXAxes READ drawXAxes WRITE setDrawXAxes NOTIFY drawXAxesChanged)
    Q_PROPERTY(bool drawYAxes READ drawYAxes WRITE setDrawYAxes NOTIFY drawYAxesChanged)

public:
    bool drawXAxes() const { return m_drawXAxes; }
    bool drawYAxes() const { return m_drawYAxes; }

    void setDrawXAxes(bool value);
    void setDrawYAxes(bool value);

    QniteGrid(QQuickItem* parent = Q_NULLPTR);

    QNanoQuickItemPainter* createItemPainter() const Q_DECL_OVERRIDE;

public Q_SLOTS:
  virtual void processData() Q_DECL_OVERRIDE {}

Q_SIGNALS:
    void drawXAxesChanged();
    void drawYAxesChanged();

private:
    bool m_drawXAxes;
    bool m_drawYAxes;
};


#endif // QNITEGRID_H
