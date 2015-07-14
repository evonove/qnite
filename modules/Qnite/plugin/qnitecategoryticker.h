#ifndef QNITE_CATEGORY_TICKER_H
#define QNITE_CATEGORY_TICKER_H

#include "qniteticker.h"

class QniteCategoryTicker: public QniteTicker
{
  Q_OBJECT

public:
  explicit QniteCategoryTicker(QObject * parent=0);
  virtual ~QniteCategoryTicker() {}

  void setValues(qreal lower, qreal upper);

protected:
  virtual void buildTicks();

private:
};


#endif  // QNITE_CATEGORY_TICKER_H

