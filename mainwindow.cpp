#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(600, 400);

    dm_bg = new DynamicBackgroundPure(this);
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    dm_bg->draw(painter);
}
