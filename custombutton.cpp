#include "custombutton.h"

CustomButton::CustomButton() {
}

CustomButton::CustomButton(int w, int h, int wx, int wh) : width(w), height(h) {
    window_x = wx;
    window_height = wh;
    PixmMap.load(":/img/img/button.png");
    PixmMap = PixmMap.scaled(width, height);
    setPos(wx, wh);
}

void CustomButton::setImage(QString s) {
    PixmMap.load(s);
    PixmMap = PixmMap.scaled(width, height);
}

void CustomButton::setText(QString s) {
    QPainter *p = new QPainter();
    p->drawText(window_x, window_height, s);
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
