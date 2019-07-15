#include "dynamicbackgroundpure.h"

DynamicBackgroundPure::DynamicBackgroundPure(QWidget* parent, QColor color1, QColor color2)
    : DynamicBackgroundInterface (parent)
{
    setColor(color1, color2);
}

void DynamicBackgroundPure::setColor(QColor color1, QColor color2)
{
    r1 = color1.red();
    g1 = color1.green();
    b1 = color1.blue();
    r2 = color2.red();
    g2 = color2.green();
    b2 = color2.blue();

    add_r = randBool();
    add_g = randBool();
    add_b = randBool();

    r = rand(r1, r2);
    g = rand(g1, g2);
    b = rand(b1, b2);

    draw_color = QColor(r, g, b);
}

void DynamicBackgroundPure::redraw(QPainter &painter)
{
    painter.save();
    {
        painter.setBrush(draw_color);
        painter.drawRect(getGeometry());
    }
    painter.restore();
}

void DynamicBackgroundPure::timeout()
{

}

QRect DynamicBackgroundPure::getGeometry()
{
    return QRect(QPoint(0,0), widget->size());
}
