#ifndef QNITE_LINE_H
#define QNITE_LINE_H

#include "qnitexyartist.h"

#include <QColor>

class QniteFillNode;
class QniteLine : public QniteXYArtist
{
  Q_OBJECT
  Q_PROPERTY(bool fill READ fill WRITE setFill NOTIFY fillChanged)
  Q_PROPERTY(QColor fillColor READ fillColor WRITE setFillColor NOTIFY fillColorChanged)
public:
  explicit QniteLine(QQuickItem *parent = 0);
  virtual ~QniteLine();

  bool fill() const { return m_fill; }
  void setFill(bool fill);
  QColor fillColor() const { return m_fillColor; }
  void setFillColor(QColor fillColor);

Q_SIGNALS:
  void fillChanged();
  void fillColorChanged();

protected:
  QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData*);

private:
  QniteFillNode* m_fillNode;
  QColor m_fillColor;
  bool m_fill;
};


#endif // QNITE_LINE_H

