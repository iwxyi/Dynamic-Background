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
    ar = randBool();
    ag = randBool();
    ab = randBool();

    // 随机值
    r = rand(r1, r2);
    g = rand(g1, g2);
    b = rand(b1, b2);

    // 每次变化的值
    dr = delta3(r2-r1);
    dg = delta3(g2-g1);
    db = delta3(b2-b1);

    // 边界处理
    if (r == r1) ar = true;
    if (r == r2) ar = false;
    if (g == g1) ag = true;
    if (g == g2) ag = false;
    if (b == b1) ab = true;
    if (b == b2) ab = false;

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
        r += ar ? dr : -dr;
        if (r == r1) ar = true;
        if (r == r2) ar = false;
    }
    else if (type == 1) // G
    {
        g += ag ? dg : -dg;
        if (g == g1) ag = true;
        if (g == g2) ag = false;
    }
    else // B
    {
        b += ab ? db : -db;
        if (b == b1) ab = true;
        if (b == b2) ab = false;
    }

    draw_color = QColor(r, g, b);

    DynamicBackgroundInterface::timeout();
}
