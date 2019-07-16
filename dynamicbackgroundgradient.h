#ifndef DYNAMICBACKGROUNDGRADIENT_H
#define DYNAMICBACKGROUNDGRADIENT_H

#include <QLinearGradient>
#include "dynamicbackgroundinterface.h"

class DynamicBackgroundGradient : public DynamicBackgroundInterface
{
public:
    DynamicBackgroundGradient(QWidget* parent,
    	QColor color1 = QColor(240, 248, 255)/*爱丽丝蓝*/,
        QColor color2 = QColor(248, 248, 253)/*幽灵白*/,
    	QColor color3 = QColor(230, 230, 250)/*薰衣草紫*/,
    	QColor color4 = QColor(204, 204, 255)/*长春花色*/
        );

    void setColor(QColor color1, QColor color2, QColor color3, QColor color4);
    void draw(QPainter& painter);

protected:
	void timeout();

private:
	ColorArray c1, c2, c3, c4, cu, cd;
	ColorArray du, dd;
	ColorDirects au, ad;
	
	QColor draw_coloru, draw_colord;
};

#endif // DYNAMICBACKGROUNDGRADIENT_H
