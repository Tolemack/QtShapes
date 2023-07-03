
#include "pa_triangular_prism.h"
#include <iostream>

pa_Triangular_Prism::pa_Triangular_Prism(int width, int height, int depth)
    : width(width), height(height), depth(depth)
{}

void pa_Triangular_Prism::paint(QPainter *painter) {

    float cuWidth = qCos(qAtan(0.5))*width;
    float cuHeight = height;
    float cuDepth = qCos(qAtan(0.5))*depth;

    QPoint qp0 = QPoint(0,0);
    QPoint qp1 = QPoint(cuWidth/2,-cuHeight+cuWidth/4);
    QPoint qp2 = QPoint(cuWidth,cuWidth/2);
    QPoint qp3 = QPoint(cuWidth/2+cuDepth,-cuHeight-cuDepth/2+cuWidth/4);
    QPoint qp4 = QPoint(cuDepth,-cuDepth/2);
    QPoint qp5 = QPoint(cuWidth+cuDepth,cuWidth/2-cuDepth/2);

    QBrush brush;
    QPen pen;

    pen.setColor(QColor(136,136,255));
    painter->setPen(pen);

    brush.setStyle(Qt::SolidPattern);
    painter->translate(250,250);

    pen.setColor(this->color.lighter(200));
    painter->setPen(pen);

    const QPointF polygon1[4] = {qp0,qp1,qp2};
    brush.setColor(this->color);
    painter->setBrush(brush);
    painter->drawConvexPolygon(polygon1, 4);

    if(cuHeight <= cuWidth/2){
        const QPointF polygon2[4] = {qp0,qp1,qp3,qp4};
        brush.setColor(this->color.lighter(130));
        painter->setBrush(brush);
        painter->drawConvexPolygon(polygon2, 4);
    }

    const QPointF polygon3[4] = {qp1,qp3,qp5,qp2};
    brush.setColor(this->color.darker(120));
    painter->setBrush(brush);
    painter->drawConvexPolygon(polygon3, 4);

    pen.setColor(this->color.darker(150));
    painter->setPen(pen);
    QLine line01(qp0,qp1);
    QLine line02(qp0,qp2);
    QLine line04(qp0,qp4);
    QLine line13(qp1,qp3);
    QLine line25(qp2,qp5);
    QLine line43(qp4,qp3);
    QLine line53(qp5,qp3);
    if(cuHeight <= cuWidth/2){
        painter->drawLine(line04);
        painter->drawLine(line43);
    } else {
        painter->drawLine(line01);
        painter->drawLine(line13);
    }
    painter->drawLine(line02);
    painter->drawLine(line25);
    painter->drawLine(line53);

    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawPoint(0,0);
    painter->drawPoint(0,1);
    painter->drawPoint(0,-1);
    painter->drawPoint(1,0);
    painter->drawPoint(-1,0);
}

void pa_Triangular_Prism::setColor(QColor color){
    this->color = color;
}

void pa_Triangular_Prism::setWidth(int width){
    this->width = width;
}

void pa_Triangular_Prism::setHeight(int height){
    this->height = height;
}

void pa_Triangular_Prism::setDepth(int depth){
    this->depth = depth;
}

QColor pa_Triangular_Prism::getColor(){
    return this->color;
}
