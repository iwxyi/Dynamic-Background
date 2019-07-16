#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(600, 400);

    dm_bg = new DynamicBackgroundGradient(this);

//    dm_bg->setColor(QColor(255, 0, 0), QColor(0, 255, 0));
//    dm_bg->setColor(QColor(255, 0, 0), QColor(128, 0, 0), QColor(0, 255, 0), QColor(0, 128, 0));

    dm_bg->setInterval(20);
//    dm_bg->setHorizone(true);
    connect(dm_bg, SIGNAL(signalRedraw()), this, SLOT(update()));
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    dm_bg->draw(painter);
}
