#ifndef QNITEARTISTPAINTER_H
#define QNITEARTISTPAINTER_H

#include "qnanoquickitempainter.h"

template <typename Artist>
class QniteArtistPainter : public QNanoQuickItemPainter {
public:
  QniteArtistPainter();

protected:
  virtual void synchronize(QNanoQuickItem *item) Q_DECL_OVERRIDE;

private:
};

#endif /* QNITEARTISTPAINTER_H */
