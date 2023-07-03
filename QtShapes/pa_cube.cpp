
#include "pa_cube.h"

pa_Cube::pa_Cube(int width, int height, int depth)
    : width(width), height(height), depth(depth)
{}

void pa_Cube::paint(QPainter *painter) {

    float cuWidth = qCos(qAtan(0.5))*width;
    float cuHeight = height;
    float cuDepth = qCos(qAtan(0.5))*depth;

    QBrush brush;
    QPen pen;

    pen.setColor(QColor(136,136,255));
    painter->setPen(pen);

    brush.setStyle(Qt::SolidPattern);
    painter->translate(250,250);

    /*QRect background(0,cuWidth/2, cuWidth+cuDepth,-(cuHeight+cuDepth/2+cuWidth/2));
    painter->drawRect(background);*/

    pen.setColor(this->color.lighter(200));
    painter->setPen(pen);

    QPointF polygon1[4] = {
        QPointF(0,0),
        QPointF(0,-cuHeight),
        QPointF(cuWidth,-cuHeight+cuWidth/2),
        QPointF(cuWidth,cuWidth/2)
    };
    brush.setColor(this->color);
    painter->setBrush(brush);
    painter->drawConvexPolygon(polygon1, 4);

    const QPointF polygon2[4] = {
        QPointF(0,-cuHeight),
        QPointF(cuWidth,-cuHeight+cuWidth/2),
        QPointF(cuWidth+cuDepth,-cuHeight+cuWidth/2-cuDepth/2),
        QPointF(cuDepth,-cuHeight-cuDepth/2)
    };
    brush.setColor(this->color.lighter(130));
    painter->setBrush(brush);
    painter->drawConvexPolygon(polygon2, 4);

    const QPointF polygon3[4] = {
        QPointF(cuWidth,-cuHeight+cuWidth/2),
        QPointF(cuWidth+cuDepth,-cuHeight+cuWidth/2-cuDepth/2),
        QPointF(cuWidth+cuDepth,cuWidth/2-cuDepth/2),
        QPointF(cuWidth,cuWidth/2)
    };
    brush.setColor(this->color.darker(120));
    painter->setBrush(brush);
    painter->drawConvexPolygon(polygon3, 4);

    pen.setColor(this->color.darker(150));
    painter->setPen(pen);
    QLine line04(0,0,0,-cuHeight);
    QLine line12(0,-cuHeight,cuWidth,-cuHeight+cuWidth/2);
    QLine line11(cuWidth,-cuHeight+cuWidth/2,cuWidth,cuWidth/2);
    QLine line03(cuWidth,cuWidth/2,0,0);
    QLine line05(0,-cuHeight,cuDepth,-cuHeight-cuDepth/2);
    QLine line10(cuWidth,-cuHeight+cuWidth/2, cuWidth+cuDepth,-cuHeight+cuWidth/2-cuDepth/2);
    QLine line00(cuWidth+cuDepth,-cuHeight+cuWidth/2-cuDepth/2,cuDepth,-cuHeight-cuDepth/2);
    QLine line01(cuWidth+cuDepth,-cuHeight+cuWidth/2-cuDepth/2,cuWidth+cuDepth,cuWidth/2-cuDepth/2);
    QLine line02(cuWidth,cuWidth/2,cuWidth+cuDepth,cuWidth/2-cuDepth/2);
    painter->drawLine(line04);
    //painter->drawLine(line12);
    //painter->drawLine(line11);
    painter->drawLine(line05);
    painter->drawLine(line03);
    //painter->drawLine(line10);
    painter->drawLine(line00);
    painter->drawLine(line01);
    painter->drawLine(line02);

    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawPoint(0,0);
    painter->drawPoint(0,1);
    painter->drawPoint(0,-1);
    painter->drawPoint(1,0);
    painter->drawPoint(-1,0);
}

void pa_Cube::setColor(QColor color){
    this->color = color;
}

void pa_Cube::setWidth(int width){
    this->width = width;
}

void pa_Cube::setHeight(int height){
    this->height = height;
}

void pa_Cube::setDepth(int depth){
    this->depth = depth;
}

QColor pa_Cube::getColor(){
    return this->color;
}

