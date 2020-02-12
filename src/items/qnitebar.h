#ifndef QNITE_BAR_H
#define QNITE_BAR_H

#include "qnitexyartist.h"
#include <QColor>

class QniteBar : public QniteXYArtist {
  Q_OBJECT
  Q_PROPERTY(qreal fixedWidth READ fixedWidth WRITE setFixedWidth NOTIFY
                 fixedWidthChanged)
  Q_PROPERTY(int selectedIndex READ selectedIndex)
  Q_PROPERTY(QStringList categories READ categories WRITE setCategories NOTIFY
                 categoriesChanged)
  Q_PROPERTY(LabelAlign labelAlign READ labelAlign WRITE setLabelAlign NOTIFY
                 labelAlignChanged)
  Q_PROPERTY(QStringList labelsText READ labelsText WRITE setLabelsText NOTIFY
                 labelsTextChanged)
  Q_PROPERTY(qreal leftPadding READ leftPadding WRITE setLeftPadding NOTIFY
                 leftPaddingChanged)
  Q_PROPERTY(qreal rightPadding READ rightPadding WRITE setRightPadding NOTIFY
                 rightPaddingChanged)

public:
  explicit QniteBar(QQuickItem *parent = 0);
  virtual ~QniteBar() {}

  qreal fixedWidth() const { return m_fixedWidth; }
  void setFixedWidth(qreal w);

  qreal leftPadding() const { return m_leftPadding; }
  void setLeftPadding(qreal leftPadding);
  qreal rightPadding() const { return m_rightPadding; }
  void setRightPadding(qreal rightPadding);

  const QStringList &categories() const { return m_categories; }
  void setCategories(const QStringList &c);

  enum LabelAlign {
    NONE,
    TOP,
  };
  Q_ENUM(LabelAlign)

  LabelAlign labelAlign() const { return m_labelAlign; };
  void setLabelAlign(const LabelAlign &position);

  const QStringList &labelsText() const { return m_labelsText; };
  void setLabelsText(const QStringList &lables);

  bool select(const QPoint) Q_DECL_OVERRIDE;
  bool select(const QList<QPoint> &) Q_DECL_OVERRIDE;
  void clearSelection() Q_DECL_OVERRIDE;

  int selectedIndex() const { return m_selectedIndex; }
  int selectedId() const { return m_selectedId; }

  QNanoQuickItemPainter *createItemPainter() const Q_DECL_OVERRIDE;

Q_SIGNALS:
  void fixedWidthChanged();
  void categoriesChanged();
  void labelAlignChanged();
  void labelsTextChanged();
  void leftPaddingChanged();
  void rightPaddingChanged();

protected:
  virtual bool isSelected() const Q_DECL_OVERRIDE;

private:
  qreal m_fixedWidth;
  qreal m_leftPadding;
  qreal m_rightPadding;

  int m_selectedId;
  int m_selectedIndex;
  LabelAlign m_labelAlign;

  QStringList m_categories;
  QStringList m_labelsText;
};

#endif // QNITE_BAR_H
