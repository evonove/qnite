#ifndef QNITE_TOOL_H
#define QNITE_TOOL_H

#include <QQuickItem>

class QniteAxes;
class QniteArtist;
class QniteTool: public QQuickItem
{
  Q_OBJECT
  Q_PROPERTY(QniteAxes* axes READ axes NOTIFY axesChanged) // TODO: axes needs to be a property?

public:
  explicit QniteTool(QQuickItem* parent = 0);
  virtual ~QniteTool() {}

  QniteAxes* axes() const { return m_axes; }
  void setAxes(QniteAxes* axes);

Q_SIGNALS:
  void axesChanged();

protected:
  QList<QniteArtist*> artists();

private:
  QniteAxes* m_axes;

};

#endif // QNITE_TOOL_H
