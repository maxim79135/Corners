#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::CustomizeWindowHint);
    ui->setupUi(this);

    init_view();
    init_items();
    game = new Game;
    view = new View;

    connect(startButton, SIGNAL(onPressButton()), this, SLOT(on_startGame()));
    connect(registerButton, SIGNAL(onPressButton()), this, SLOT(on_register_menu()));
    connect(view, SIGNAL(on_Exit_Game()), this, SLOT(on_Show_main_menu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_items() {
    QFont font;
    font.setPixelSize(15);
    font.setBold(true);

    nameGame = new CustomLabel(25, 250, 180);
    nameGame->setText("Corners");

    login = new CustomLabel(15, 150, 250);
    login->setText("Login");

    password = new CustomLabel(15, 150, 280);
    password->setText("Password");

    login_edit = new CustomEdit(100, 20, 15, 250, 250);
    password_edit = new CustomEdit(100, 20, 15, 250, 280);

    cloudA = new Cloud(100, 50, 3.0);
    cloudA->setPos(150, 100);

    cloudB = new Cloud(80, 30, -1.0);
    cloudB->setPos(500, 60);

    startButton = new CustomButton(80, 30, 200, 350);
    startButton->setText("Hello");
    registerButton = new CustomButton(80, 30, 300, 350);

    scene->addItem(cloudA);
    scene->addItem(cloudB);
    scene->addItem(startButton);
    scene->addItem(registerButton);
    scene->addWidget(login);
    scene->addWidget(password);
    scene->addWidget(login_edit);
    scene->addWidget(password_edit);
    scene->addWidget(nameGame);
}

void MainWindow::init_view() {
    scene = new QGraphicsScene(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheNone);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFrameStyle(0);
    ui->graphicsView->setSceneRect(0, 0, 600, 600);
    ui->graphicsView->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    setFixedSize(600, 600);
    setWindowTitle("Corners");
    ui->graphicsView->setScene(scene);

    QBrush br;
    QImage pic;
    pic.load(":/img/img/background_1.png");
    br.setTextureImage(pic);
    ui->graphicsView->setBackgroundBrush(br);

    //ui->graphicsView->setBackgroundBrush(QBrush(QColor(195, 176, 145)));
}

void MainWindow::on_startGame() {
    if (login_edit->text() == "admin" && password_edit->text() == "admin") {
        second_menu = new QGraphicsScene(this);
        ui->graphicsView->setScene(second_menu);

        playGame = new CustomLabel(18, 200, 200);
        playGame->setText("Play Game");
        connect(playGame, SIGNAL(on_press_label()), this, SLOT(on_main_menu()));

        second_menu->addWidget(playGame);
    }
}

void MainWindow::on_main_menu() {
    view->setGame(game);
    view->show();
    this->hide();
}

void MainWindow::on_register_menu() {
    register_scene = new QGraphicsScene(this);
}

void MainWindow::on_Show_main_menu() {
    this->show();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        break;
    }
}
