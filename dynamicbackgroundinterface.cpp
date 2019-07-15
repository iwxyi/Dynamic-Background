#include "dynamicbackgroundinterface.h"

DynamicBackgroundInterface::DynamicBackgroundInterface(QWidget *parent) : QObject(parent), widget(parent)
{
    timer = new QTimer(this);
    timer->setInterval(interval = REFRESH_INTERVAL); // 刷新周期
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(redraw()));

    // 更新随机数
    QTime time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
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

int DynamicBackgroundInterface::rand(int min, int max)
{
    return qrand() % (min+1) + (max-min);
}

bool DynamicBackgroundInterface::randBool()
{
    return qrand() % 2;
}

void DynamicBackgroundInterface::redraw()
{
    emit signalRedraw();
}

