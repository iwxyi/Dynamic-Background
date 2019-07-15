#ifndef DYNAMICBACKGROUNDPURE_H
#define DYNAMICBACKGROUNDPURE_H

#include "dynamicbackgroundinterface.h"

class DynamicBackgroundPure : public DynamicBackgroundInterface
{
public:
    DynamicBackgroundPure(QWidget *parent, QColor color1=QColor(), QColor color2=QColor());

    void setColor(QColor color1, QColor color2);
    void redraw(QPainter& painter);

protected:
    void timeout();
    virtual QRect getGeometry();

private:
    QColor bg_color1, bg_color2;
};

#endif // DYNAMICBACKGROUNDPURE_H
