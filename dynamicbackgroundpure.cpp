#include "dynamicbackgroundpure.h"

DynamicBackgroundPure::DynamicBackgroundPure(QWidget* parent, QColor color1, QColor color2)
    : DynamicBackgroundInterface (parent)
{
    setColor(color1, color2);
}

void DynamicBackgroundPure::setColor(QColor color1, QColor color2)
{
    // 阈值
    r1 = color1.red();
    g1 = color1.green();
    b1 = color1.blue();
    r2 = color2.red();
    g2 = color2.green();
    b2 = color2.blue();

    // 随机变化
    add_r = randBool();
    add_g = randBool();
    add_b = randBool();

    // 随机值
    r = rand(r1, r2);
    g = rand(g1, g2);
    b = rand(b1, b2);

    draw_color = QColor(r, g, b);
}

void DynamicBackgroundPure::draw(QPainter &painter)
{
    painter.save();
    {
        // 绘制矩形
        painter.setBrush(draw_color);
        painter.drawRect(getGeometry());
    }
    painter.restore();
}

void DynamicBackgroundPure::timeout()
{
    // 随机变化
    int type = qrand() % 3;
    if (type == 0) // R
    {

    }
    else if (type == 1) // G
    {

    }
    else // B
    {

    }

    DynamicBackgroundInterface::timeout();
}
