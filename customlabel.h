#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>
#include <QtWidgets>

class CustomLabel : public QLabel
{
    Q_OBJECT
public:
    CustomLabel();
    CustomLabel(int f, int wx, int wh);

signals:
    void on_press_label();

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // CUSTOMLABEL_H
