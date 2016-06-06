#ifndef QNITE_PEN_H
#define QNITE_PEN_H


#include <QObject>
#include "qnanopainter.h"


class QnitePen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor stroke READ stroke WRITE setStroke NOTIFY strokeChanged)
    Q_PROPERTY(QColor fill READ fill WRITE setFill NOTIFY fillChanged)
    Q_PROPERTY(qreal width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(LineJoin join READ join WRITE setJoin NOTIFY joinChanged)
    Q_PROPERTY(LineCap cap READ cap WRITE setCap NOTIFY capChanged)

public:

    using LineJoin = QNanoPainter::LineJoin;
    Q_ENUM(LineJoin)

    using LineCap = QNanoPainter::LineCap;
    Q_ENUM(LineCap)

    QnitePen(QObject* parent = Q_NULLPTR);

    QColor stroke() const { return m_data.stroke; }
    void setStroke(QColor stroke);

    QColor fill() const { return m_data.fill; }
    void setFill(QColor fill);

    qreal width() const { return m_data.width; }
    void setWidth(qreal width);

    LineJoin join() const { return m_data.join; }
    void setJoin(LineJoin join);

    LineCap cap() const { return m_data.cap; }
    void setCap(LineCap cap);

    // An instance of PenData is shared with the painter
    // class associated with each artist.
    // this has been moved to a separate inner class to allow
    // an easy copying between the artist and the painter since
    // QObjects cannot be copied (see http://doc.qt.io/qt-5/object.html#qt-objects-identity-vs-value)
    struct PenData
    {
        PenData();

        QColor stroke;
        QColor fill;
        qreal width;
        LineJoin join;
        LineCap cap;
    };

    const PenData& data() const { return m_data; }

Q_SIGNALS:
    void strokeChanged();
    void fillChanged();
    void widthChanged();
    void joinChanged();
    void capChanged();
    void penChanged();

private:
    PenData m_data;
};

#endif // QNITE_PEN_H
