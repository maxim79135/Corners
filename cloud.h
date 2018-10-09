#ifndef CLOUD_H
#define CLOUD_H

#include <QObject>
#include <QtWidgets>

class Cloud : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Cloud();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setSpeed(qreal speed) { dx = speed; }

private:
    int width;
    int height;
    qreal dx;
    QPixmap PixMap;
    QTimer time;

private slots:
    void move();
};

#endif // CLOUD_H
