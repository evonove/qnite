#ifndef QNITELINEARTICKER_H
#define QNITELINEARTICKER_H

#include "qniteticker.h"

class QniteLinearTicker: public QniteTicker
{
  Q_OBJECT

public:
  explicit QniteLinearTicker(QObject * parent=0);
  virtual ~QniteLinearTicker() {}

  virtual void reset();
  void setLooseNiceness(bool);
  bool looseNiceness() const;

protected:
  virtual void buildTicks();

private:


  bool m_loose;
};

#endif // QNITELINEARTICKER_H
