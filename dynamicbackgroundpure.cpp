#include "dynamicbackgroundpure.h"

DynamicBackgroundPure::DynamicBackgroundPure(QWidget* parent, QColor color1, QColor color2)
    : DynamicBackgroundInterface (parent)
{
    setColor(color1, color2);
}

void DynamicBackgroundPure::setColor(QColor color1, QColor color2)
{
    bg_color1 = color1;
    bg_color2 = color2;


}

void DynamicBackgroundPure::redraw(QPainter &painter)
{

}

void DynamicBackgroundPure::timeout()
{

}

QRect DynamicBackgroundPure::getGeometry()
{
    return QRect(QPoint(0,0), widget->size());
}
