
#ifndef PA_CYLINDER_H
#define PA_CYLINDER_H

#include <QPainter>
#include <QtMath>
#include "paintable.h"


class pa_Cylinder : public Paintable
{
public:
    pa_Cylinder(int, int, int);
    void paint(QPainter*);
    void setColor(QColor);
    QColor getColor();

public slots:
    void setWidth(int width);
    void setHeight(int height);
    void setGradient(int depth);
    int getWidth();
    int getDisplayedWidth();

private:
    QLinearGradient getCosineGradient(float, float);

protected:
    int width;
    int height;
    int gradient;
    QColor color;
};

#endif // PA_CYLINDER_H
