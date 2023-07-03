
#include "paintdevicewidget.h"
#include <iostream>

PaintDeviceWidget::PaintDeviceWidget(QWidget *parent)
    : QWidget{parent}
{}

void PaintDeviceWidget::paintEvent(QPaintEvent* event){
    QPainter painter;
    painter.begin(this);
    if(this->paintable){
        this->paintable->paint(&painter);
    }
    painter.end();
}

void PaintDeviceWidget::resizeEvent(QResizeEvent* event){
    std::cout << "Resize paintDevice :"
              << event->size().width() << "/"
              << event->size().height()
              << std::endl;
}

void PaintDeviceWidget::setPaintable(Paintable* paintable){
    this->paintable = paintable;
}

Paintable* PaintDeviceWidget::getPaintable(){
    return this->paintable;
}
