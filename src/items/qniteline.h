#ifndef QNITE_LINE_H
#define QNITE_LINE_H

#include "qnitexyartist.h"

#include <QColor>

class QniteLine : public QniteXYArtist {
  Q_OBJECT
  Q_PROPERTY(bool drawSymbols READ drawSymbols WRITE setDrawSymbols NOTIFY
                 drawSymbolsChanged)
  Q_PROPERTY(bool drawStepped READ drawStepped WRITE setDrawStepped NOTIFY
                 drawSteppedChanged)

public:
  explicit QniteLine(QQuickItem *parent = 0);

  bool select(const QList<QPoint> &) Q_DECL_OVERRIDE;
  bool select(const QPoint) Q_DECL_OVERRIDE;
  void clearSelection() Q_DECL_OVERRIDE;

  bool drawSymbols() const { return m_drawSymbols; }
  bool drawStepped() const { return m_drawStepped; }
  void setDrawSymbols(bool drawSymbols);
  void setDrawStepped(bool drawStepped);

  QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE;

signals:
  void drawSymbolsChanged();
  void drawSteppedChanged();

protected:
  virtual bool isSelected() const Q_DECL_OVERRIDE { return m_selected; }

private:
  bool m_selected;
  bool m_drawSymbols;
  bool m_drawStepped;
};

#endif // QNITE_LINE_H
