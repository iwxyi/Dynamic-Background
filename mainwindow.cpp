#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(600, 400);

    dm_bg = new DynamicBackgroundPure(this);
    dm_bg->setColor(QColor(255, 0, 0), QColor(0, 255, 0));
    dm_bg->setInterval(2000);
    connect(dm_bg, SIGNAL(signalRedraw()), this, SLOT(update()));
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    dm_bg->draw(painter);
}
