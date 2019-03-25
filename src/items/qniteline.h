#ifndef QNITE_LINE_H
#define QNITE_LINE_H

#include "qnitexyartist.h"

#include <QColor>

class QniteLine : public QniteXYArtist {
  Q_OBJECT
  Q_PROPERTY(bool drawSymbols READ drawSymbols WRITE setDrawSymbols NOTIFY
                 drawSymbolsChanged)

public:
  explicit QniteLine(QQuickItem *parent = 0);

  bool select(const QList<QPoint> &) Q_DECL_OVERRIDE;
  bool select(const QPoint) Q_DECL_OVERRIDE;
  void clearSelection() Q_DECL_OVERRIDE;

  bool drawSymbols() const { return m_drawSymbols; }
  void setDrawSymbols(bool drawSymbols);

  QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE;

signals:
  void drawSymbolsChanged();

protected:
  virtual bool isSelected() const Q_DECL_OVERRIDE { return m_selected; }

private:
  bool m_selected;
  bool m_drawSymbols;
};

#endif // QNITE_LINE_H
