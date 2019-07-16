#ifndef DYNAMICBACKGROUNDINTERFACE_H
#define DYNAMICBACKGROUNDINTERFACE_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QDebug>

#define REFRESH_INTERVAL 2000
#define R 1
#define G 2
#define B 3
#define A 4

typedef int ColorArray[5];
typedef bool ColorDirects[5];

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

    int randRange(int min, int max);
    bool randBool();
    int intToUnity(int v);
    void colorToArray(int* arr, QColor c);

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
