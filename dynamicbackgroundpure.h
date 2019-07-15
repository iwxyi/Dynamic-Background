#ifndef DYNAMICBACKGROUNDPURE_H
#define DYNAMICBACKGROUNDPURE_H

#include "dynamicbackgroundinterface.h"

class DynamicBackgroundPure : public DynamicBackgroundInterface
{
public:
    DynamicBackgroundPure(QWidget *parent, QColor color1=QColor(253, 245, 230), QColor color2=QColor(255, 250, 240));

    void setColor(QColor color1, QColor color2);
    void draw(QPainter& painter);

protected:
    void timeout();

private:
    int r1, g1, b1;
    int r2, g2, b2;
    int r, g, b;
    bool add_r, add_g, add_b;

    QColor draw_color;
};

#endif // DYNAMICBACKGROUNDPURE_H
