#include "dynamicbackgroundinterface.h"

DynamicBackgroundInterface::DynamicBackgroundInterface(QWidget *parent) : QObject(parent), widget(parent)
{
    timer = new QTimer(this);
    timer->setInterval(interval = REFRESH_INTERVAL); // 刷新周期
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(redraw()));
}


void DynamicBackgroundInterface::setInterval(int iv)
{
    interval = iv;
    timer->setInterval(iv);
}

void DynamicBackgroundInterface::timeout()
{
    redraw();
}

void DynamicBackgroundInterface::redraw()
{
    emit signalRedraw();
}

