#ifndef DYNAMICBACKGROUNDINTERFACE_H
#define DYNAMICBACKGROUNDINTERFACE_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QDebug>

#define REFRESH_INTERVAL 30000

class DynamicBackgroundInterface : public QObject
{
    Q_OBJECT
public:
    DynamicBackgroundInterface(QWidget *parent);

    virtual void setInterval(int iv);
    virtual void setColor(QColor) {}
    virtual void setColor(QColor, QColor) {}
    virtual void setColor(QColor, QColor, QColor) {}
    virtual void setColor(QColor, QColor, QColor, QColor) {}
    virtual void draw(QPainter&) { qDebug() << "interface draw"; }

protected:
    virtual QRect getGeometry();

    int rand(int min, int max);
    bool randBool();
    int delta3(int v);

signals:
    void signalRedraw();

public slots:
    virtual void timeout();
    virtual void redraw();

protected:
    QTimer* timer;
    int interval;
    QWidget* widget;
};

#endif // DYNAMICBACKGROUNDINTERFACE_H
