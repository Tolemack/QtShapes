
#ifndef PA_CUBE_H
#define PA_CUBE_H

#include <QPainter>
#include <QtMath>
#include "paintable.h"


class pa_Cube : public Paintable
{
public:
    pa_Cube(int, int, int);
    void paint(QPainter*);
    void setColor(QColor);
    QColor getColor();

public slots:
    void setWidth(int width);
    void setHeight(int height);
    void setDepth(int depth);

protected:
    int width;
    int height;
    int depth;
    QColor color;
};

#endif // PA_CUBE_H
