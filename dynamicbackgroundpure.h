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
    int dr, dg, db;
    bool ar, ag, ab; // 从1变到2的方向

    QColor draw_color;
};

#endif // DYNAMICBACKGROUNDPURE_H
