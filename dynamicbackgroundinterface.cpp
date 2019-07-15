#include "dynamicbackgroundinterface.h"

DynamicBackgroundInterface::DynamicBackgroundInterface(QWidget *parent) : QObject(parent), widget(parent)
{
    timer = new QTimer(this);
    timer->setInterval(interval = REFRESH_INTERVAL); // 刷新周期
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));

    // 更新随机数
    QTime time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
}


void DynamicBackgroundInterface::setInterval(int iv)
{
    timer->setInterval(interval = iv);
}

void DynamicBackgroundInterface::timeout()
{
    redraw();
}

QRect DynamicBackgroundInterface::getGeometry()
{
    return QRect(-1, -1, widget->size().width()+1, widget->size().height()+1);
}

int DynamicBackgroundInterface::rand(int min, int max)
{
    if (min > max)
    {
        min = min ^ max;
        max = min ^ max;
        min = min ^ max;
    }
    int res = qrand() % (max-min+1) + min;

    return res;
}

bool DynamicBackgroundInterface::randBool()
{
    return qrand() % 2;
}

int DynamicBackgroundInterface::delta3(int v)
{
    if (v == 0)
        return 0;
    if (v > 0)
        return 1;
    return -1;
}

void DynamicBackgroundInterface::redraw()
{
    emit signalRedraw();
}

