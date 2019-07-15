#ifndef DYNAMICBACKGROUNDINTERFACE_H
#define DYNAMICBACKGROUNDINTERFACE_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QTimer>
#include <QTime>
#include <QPainter>

#define REFRESH_INTERVAL 30000

class DynamicBackgroundInterface : public QObject
{
    Q_OBJECT
public:
    explicit DynamicBackgroundInterface(QWidget *parent);

    virtual void setInterval(int iv);
    virtual void setColor(QColor color1) {}
    virtual void setColor(QColor color1, QColor color2) {}
    virtual void setColor(QColor color1, QColor color2, QColor color3) {}
    virtual void setColor(QColor color1, QColor color2, QColor color3, QColor color4) {}
    virtual void draw(QPainter& painter) {}

protected:
    virtual void timeout();


    int rand(int min, int max);
    bool randBool();

signals:
    void signalRedraw();

public slots:
    virtual void redraw();

protected:
    QTimer* timer;
    int interval;
    QWidget* widget;
};

#endif // DYNAMICBACKGROUNDINTERFACE_H
