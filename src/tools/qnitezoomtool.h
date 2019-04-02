#pragma once

#include "qnitepen.h"
#include "qnitetool.h"

class QniteZoomTool : public QniteTool {
  Q_OBJECT
  Q_PROPERTY(QnitePen *pen READ pen CONSTANT)
  Q_PROPERTY(qreal minZoomFactor READ minZoomFactor WRITE setMinZoomFactor
                 NOTIFY minZoomFactorChanged)
  Q_PROPERTY(
      bool limitZoom READ limitZoom WRITE setLimitZoom NOTIFY limitZoomChanged)

public:
  explicit QniteZoomTool(QQuickItem *parent = nullptr);
  virtual ~QniteZoomTool() Q_DECL_OVERRIDE;

  QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE;

  QRectF rect() const { return m_zoomRect; }
  QnitePen *pen() const { return m_pen.data(); }

  qreal minZoomFactor() const { return m_minZoomFactor; }
  void setMinZoomFactor(qreal factor);

  bool limitZoom() const { return m_limitZoom; }
  void setLimitZoom(bool limit);

  Q_INVOKABLE void resetZoom();

signals:
  void minZoomFactorChanged() const;
  void limitZoomChanged() const;

protected:
  virtual void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  virtual void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  virtual void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private slots:
  void connectAxesBoundsSignals() const;
  void updateBaseZoomRectXBounds();
  void updateBaseZoomRectYBounds();

private:
  QRectF m_zoomRect;
  QRectF m_baseZoomRect;
  qreal m_minZoomFactor;
  bool m_limitZoom;
  QScopedPointer<QnitePen> m_pen;

  QSizeF minimumZoomSize() const;
};
