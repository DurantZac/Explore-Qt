#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>


class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    ImageLabel();
public slots:
    void slotOnNext();
    void slotOnReset();
private:
    void mouseReleaseEvent(QMouseEvent *ev) override;
    QVector<QString> images;
    QVector<QPixmap*> canvases;
    int currentImage = 0;
    QPoint *linePoint;
};

#endif // IMAGELABEL_H
