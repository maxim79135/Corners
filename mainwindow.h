#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <cloud.h>
#include <custombutton.h>
#include <customlabel.h>
#include <customedit.h>
#include <view.h>
#include <game.h>

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
    QGraphicsScene *second_menu;
    QGraphicsScene *register_scene;
    Cloud *cloudA;
    Cloud *cloudB;
    CustomButton *startButton;
    CustomButton *registerButton;
    CustomLabel *login;
    CustomLabel *password;
    CustomLabel *nameGame;
    CustomLabel *playGame;
    CustomLabel *ExitGame;
    CustomEdit *login_edit;
    CustomEdit *password_edit;
    View *view;
    Game *game;

private:
    void init_items();
    void init_view();

private slots:
    void on_startGame();
    void on_main_menu();
    void on_register_menu();
    void on_Show_main_menu();

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
