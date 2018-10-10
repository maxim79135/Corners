#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <cloud.h>
#include <custombutton.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *test;
    Cloud *cloudA;
    Cloud *cloudB;
    CustomButton *startButton;
    CustomButton *registerButton;

private:
    void init_items();
    void init_view();

private slots:
    void startGame();
    void testView();
};

#endif // MAINWINDOW_H
