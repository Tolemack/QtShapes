
#ifndef PA_TRIANGULAR_PRISM_H
#define PA_TRIANGULAR_PRISM_H

#include <QPainter>
#include <QtMath>
#include "paintable.h"


class pa_Triangular_Prism : public Paintable
{
public:
    pa_Triangular_Prism(int, int, int);
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

#endif // PA_TRIANGULAR_PRISM_H
