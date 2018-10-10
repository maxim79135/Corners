#include "custombutton.h"

CustomButton::CustomButton() {
    PixmMap.load(":/img/img/button.png");
    PixmMap = PixmMap.scaled(width, height);
}

CustomButton::CustomButton(int w, int h) : width(w), height(h) {
    PixmMap.load(":/img/img/button.png");
    PixmMap = PixmMap.scaled(width, height);
}

void CustomButton::setImage(QString) {
    PixmMap.load(":/img/img/button.png");
    PixmMap = PixmMap.scaled(width, height);
}

QRectF CustomButton::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void CustomButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, PixmMap, 0, 0, width, height);
}

void CustomButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit onPressButton();
}
