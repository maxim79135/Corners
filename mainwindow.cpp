#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(195, 176, 145)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
