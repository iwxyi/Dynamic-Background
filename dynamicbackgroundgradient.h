#ifndef DYNAMICBACKGROUNDGRADIENT_H
#define DYNAMICBACKGROUNDGRADIENT_H

#include "dynamicbackgroundinterface.h"

class DynamicBackgroundGradient : public QObject
{
public:
    DynamicBackgroundGradient();

    void setColor(QColor color1, QColor color2, QColor color3, QColor color4);
    void draw();

protected:
	void timeout();

private:
	int c1[5], c2[5], c3[5], c4[5], c[5];
	
};

#endif // DYNAMICBACKGROUNDGRADIENT_H
