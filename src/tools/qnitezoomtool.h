#pragma once

#include "qnitepen.h"
#include "qnitetool.h"

class QniteZoomTool : public QniteTool {
  Q_OBJECT
  Q_PROPERTY(QnitePen *pen READ pen CONSTANT)

public:
  explicit QniteZoomTool(QQuickItem *parent = nullptr);
  virtual ~QniteZoomTool() Q_DECL_OVERRIDE;

  QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE;

  QRectF rect() const { return m_zoomRect; }
  QnitePen *pen() const { return m_pen.data(); }

protected:
  virtual void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  virtual void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  virtual void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
  int m_zoomLevel;

  QRectF m_zoomRect;
  QScopedPointer<QnitePen> m_pen;
};
