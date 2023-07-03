
#include "pa_cylinder.h"
#include <iostream>

pa_Cylinder::pa_Cylinder(int width, int height, int gradient)
    : width(width), height(height), gradient(gradient)
{}

void pa_Cylinder::paint(QPainter *painter) {

    painter->translate(250,250);

    float cuWidth = qCos(qAtan(0.5))*width;
    float cuHeight = height;

    float cyWidth = this->getDisplayedWidth();
    float cyHeight = cuHeight;
    float cyTopHeight = cuWidth*qSqrt(0.5f);
    float xOffset = (cuWidth*2-cyWidth)/2;

    QBrush topBrush, brush;
    QPen darkPen,lightPen,redPen;

    topBrush.setStyle(Qt::SolidPattern);
    brush = QBrush(this->getCosineGradient(cyWidth, xOffset));

    lightPen.setColor(this->color.lighter(200));
    darkPen.setColor(this->color.darker(150));
    redPen.setColor(Qt::red);
    topBrush.setColor(this->color.lighter(130));
    brush.setColor(this->color);

    QRectF cyTop(xOffset, -cyHeight-(cyTopHeight/2), cyWidth, cyTopHeight);
    QRectF cyCorpse(xOffset, 0, cyWidth, -cyHeight);
    QRectF cyBottom(xOffset, -cyTopHeight/2, cyWidth, cyTopHeight);
    painter->setPen(darkPen);
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    painter->drawRect(cyCorpse);
    painter->drawChord(cyBottom,-16*180,16*180);
    painter->setPen(lightPen);
    painter->setBrush(topBrush);
    painter->drawRoundedRect(cyTop,cyWidth/2,cyTopHeight/2);
    painter->setPen(darkPen);
    painter->drawArc(cyTop,-16*180,-16*180);
    painter->drawArc(cyBottom,-16*180,16*180);
    painter->drawLine(QLineF(xOffset,0,xOffset,-cyHeight));
    painter->drawLine(QLineF(cyWidth+xOffset,0,cyWidth+xOffset,-cyHeight));

    painter->setPen(redPen);
    painter->drawPoint(0,0);
    painter->drawPoint(0,1);
    painter->drawPoint(0,-1);
    painter->drawPoint(1,0);
    painter->drawPoint(-1,0);
}

void pa_Cylinder::setColor(QColor color){
    this->color = color;
}

void pa_Cylinder::setWidth(int width){
    this->width = width;
}

void pa_Cylinder::setHeight(int height){
    this->height = height;
}

void pa_Cylinder::setGradient(int gradient){
    this->gradient = gradient;
}

QColor pa_Cylinder::getColor(){
    return this->color;
}

int pa_Cylinder::getWidth(){
    return this->width;
}

int pa_Cylinder::getDisplayedWidth(){
    return qCos(qAtan(0.5))*this->getWidth()*qSqrt(1.5f);
}

QLinearGradient pa_Cylinder::getCosineGradient(float cyWidth, float xOffset){

    float shadeAmplitude = 125;
    float shadeOffset = 30;

    QLinearGradient linearGrad2(QPointF(xOffset, 0), QPointF(xOffset+cyWidth, 0));
    int startShade = 100 - (shadeAmplitude/2);
    linearGrad2.setColorAt(0.0f,
       this->color.darker(startShade+shadeOffset)
    );
    if(this->gradient > 0){
        float shadeScale = shadeAmplitude/(this->gradient);
        for(int iGrad=1;iGrad<=this->gradient;iGrad++){
            float cosineScale = (qCos(qDegreesToRadians((iGrad/(this->gradient+1.0f)*180.0f)))*-1.0f+1.0f)/2;
            linearGrad2.setColorAt(cosineScale, this->color.darker(
                startShade+((iGrad-1)*shadeScale)+shadeOffset
            ));
            linearGrad2.setColorAt(std::nextafter((cosineScale),1.0f), this->color.darker(
                startShade+(iGrad*shadeScale)+shadeOffset
            ));
        }
    } else {
        linearGrad2.setColorAt(0.5f,
           this->color.darker(startShade+(shadeAmplitude/2)+shadeOffset)
        );
    }
    linearGrad2.setColorAt(1.0f, this->color.darker(
        startShade+(shadeAmplitude)+shadeOffset
    ));

    return linearGrad2;
}
