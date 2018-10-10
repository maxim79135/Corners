#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QtWidgets>

class CustomButton : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    CustomButton();
    CustomButton(int w, int h);
    void setImage(QString);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int width;
    int height;
    QPixmap PixmMap;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void onPressButton();

};

#endif // CUSTOMBUTTON_H
