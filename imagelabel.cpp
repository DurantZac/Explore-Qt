#include "imagelabel.h"
ImageLabel::ImageLabel()
{
    images.append("C:/Resources/image1.jpg");
    images.append("C:/Resources/image2.jpg");
    images.append("C:/Resources/image3.jpg");
    canvases.append(new QPixmap(images.at(0)));
    canvases.append(new QPixmap(images.at(1)));
    canvases.append(new QPixmap(images.at(2)));
    this->setBackgroundRole(QPalette::Base);
    this->setScaledContents(false);
    this->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    this->setPixmap(*canvases.at(currentImage));
    linePoint = new QPoint();
}

void ImageLabel::slotOnNext()
{
    currentImage = currentImage < canvases.size()-1 ? currentImage +1 : 0;
    QPixmap *newImage = canvases.at(currentImage);
    this->setPixmap(*newImage);
}

void ImageLabel::slotOnReset()
{
    QPixmap *image = canvases.at(currentImage);
    image->load(images.at(currentImage));
    this->setPixmap(*image);
}

void ImageLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if (linePoint->isNull())
    {
        linePoint->setX(ev->x());
        linePoint->setY(ev->y());
    }
    else {
        QPixmap *current = canvases.at(currentImage);
        QPainter painter(current);
        painter.drawLine(linePoint->x(),linePoint->y(),ev->x(), ev->y());
        this->setPixmap(*current);
        linePoint->setX(0);
        linePoint->setY(0);
    }
}
