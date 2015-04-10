#ifndef MYITEM_H
#define MYITEM_H

#include <QQuickItem>

class MyItem : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(MyItem)

  public:
    MyItem(QQuickItem *parent = 0);
    ~MyItem();
};

#endif // MYITEM_H

