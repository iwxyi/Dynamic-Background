#include "dynamicbackgroundgradient.h"

DynamicBackgroundGradient::DynamicBackgroundGradient(QWidget* parent,
        QColor color1, QColor color2, QColor color3,  QColor color4)
    : DynamicBackgroundInterface (parent)
{
	setColor(color1, color2, color3, color4);
}

void DynamicBackgroundGradient::setColor(QColor color1, QColor color2, QColor color3, QColor color4)
{
	// 阈值
    colorToArray(c1, color1);
    colorToArray(c2, color2);
    colorToArray(c3, color3);
    colorToArray(c4, color4);

    // 设置各种属性
    for (int i = 1; i <= 4; i++)
    {
        au[i] = randBool(); // 随机变化方向
        cu[i] = randRange(c1[i], c2[i]); // 初始随机颜色
        du[i] = intToUnity(c2[i]-c1[i]); // 每次变化的方向,false向1变化，true向2变化
        if (cu[i] == c1[i]) au[i] = true;
        if (cu[i] == c2[i]) au[i] = false;
    }
    for (int i = 1; i <= 4; i++)
    {
        ad[i] = randBool(); // 随机变化方向
        cd[i] = randRange(c3[i], c4[i]); // 初始随机颜色
        dd[i] = intToUnity(c4[i]-c3[i]); // 每次变化的方向,false向1变化，true向2变化
        if (cd[i] == c1[i]) ad[i] = true;
        if (cd[i] == c2[i]) ad[i] = false;
    }

    draw_coloru = QColor(cu[R], cu[G], cu[B], cu[A]);
    draw_colord = QColor(cd[R], cd[G], cd[B], cd[A]);
}
void DynamicBackgroundGradient::draw(QPainter &painter)
{
    painter.save();
    {
        painter.setRenderHint(QPainter::Antialiasing, true);

        // 绘制矩形
        QRect rect = getGeometry();
        QLinearGradient linear(QPoint(rect.top(), rect.width()/2), QPoint(QPoint(rect.bottom(), rect.width()/2)));
        linear.setColorAt(0, draw_coloru);
        linear.setColorAt(1, draw_colord);
        linear.setSpread(QGradient::PadSpread);

        painter.setBrush(linear);
        painter.drawRect(rect);
    }
    painter.restore();
}

void DynamicBackgroundGradient::timeout()
{
    // 随机变化
	int t = randRange(1, 4);
    if (qrand() % 2)
    {
    	cu[t] += au[t] ? du[t] : -du[t];
    	if (cu[t] == c1[t]) au[t] = true;
    	if (cu[t] == c2[t]) au[t] = false;

    	draw_coloru = QColor(cu[R], cu[G], cu[B], cu[A]);
    }
    else
    {
    	cd[t] += ad[t] ? dd[t] : -dd[t];
    	if (cd[t] == c3[t]) ad[t] = true;
    	if (cd[t] == c4[t]) ad[t] = false;

    	draw_colord = QColor(cd[R], cd[G], cd[B], cd[A]);
    }

    DynamicBackgroundInterface::timeout();
}
