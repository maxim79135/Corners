#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init_view();
    init_items();

    connect(startButton, SIGNAL(onPressButton()), this, SLOT(startGame()));
    connect(registerButton, SIGNAL(onPressButton()), this, SLOT(testView()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_items() {
    QFont font;
    font.setPixelSize(15);
    font.setBold(true);

    nameGame = new QLabel;
    nameGame->setText("Corners");
    QFont name;
    name.setPixelSize(25);
    name.setBold(true);
    nameGame->setFont(name);
    nameGame->setStyleSheet("QLabel{background-color: rgba(195, 176, 145, 80);}");
    nameGame->move(250, 180);

    login = new QLabel;
    login->setFont(font);
    login->setStyleSheet("QLabel{background-color: rgba(195, 176, 145, 80);}");

    password = new QLabel;
    password->setFont(font);
    password->setStyleSheet("QLabel{background-color: rgba(195, 176, 145, 80);}");

    login->setText("Login");
    password->setText("Password");

    login_edit = new QLineEdit;
    login_edit->setFixedSize(100, 20);
    login_edit->setFont(font);
    login_edit->setStyleSheet("QLineEdit{background-color: rgba(195, 176, 145, 80);}");

    password_edit = new QLineEdit;
    password_edit->setFixedSize(100, 20);
    password_edit->setFont(font);
    password_edit->setStyleSheet("QLineEdit{background-color: rgba(195, 176, 145, 80);}");

    login->move(150, 250);
    password->move(150, 280);
    login_edit->move(250, 250);
    password_edit->move(250, 280);

    cloudA = new Cloud(100, 50, 3.0);
    cloudA->setPos(150, 100);

    cloudB = new Cloud(80, 30, -1.0);
    cloudB->setPos(500, 60);

    startButton = new CustomButton(80, 30);
    startButton->setPos(200, 350);

    registerButton = new CustomButton(80, 30);
    registerButton->setPos(300, 350);

    scene->addItem(cloudA);
    scene->addItem(cloudB);
    scene->addItem(startButton);
    scene->addWidget(login);
    scene->addWidget(password);
    scene->addWidget(login_edit);
    scene->addWidget(password_edit);
    scene->addWidget(nameGame);
    //scene->addItem(registerButton);
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

    /*QBrush br;
    QPixmap pic;
    pic.load(":/img/img/background.jpg");
    pic = pic.scaled(600, 600);
    br.setTexture(pic);
    ui->graphicsView->setBackgroundBrush(br);*/

    ui->graphicsView->setBackgroundBrush(QBrush(QColor(195, 176, 145)));
}

void MainWindow::startGame() {
    //close();
    test = new QGraphicsScene(this);
    ui->graphicsView->setScene(test);



    test->addItem(registerButton);

}

void MainWindow::testView() {
    ui->graphicsView->setScene(scene);
}
