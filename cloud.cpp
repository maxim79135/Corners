#include "cloud.h"

Cloud::Cloud() : height(50), width(100) {
    PixMap.load(":/img/img/Cloud.png");
    PixMap = PixMap.scaled(100, 50);

    connect(&time, &QTimer::timeout, this, &Cloud::move);
    time.start(50);
}

QRectF Cloud::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Cloud::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, PixMap, 0, 0, width, height);
}

void Cloud::move() {
    if (dx > 0 && this->pos().x() + dx > 600)
        setPos(-100, this->pos().y());
    if (dx < 0 && this->pos().x() + dx < -100)
        setPos(650, this->pos().y());
    else
        setPos(this->pos().x() + dx, this->pos().y());
}
