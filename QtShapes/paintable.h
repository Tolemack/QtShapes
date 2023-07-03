
#ifndef PAINTABLE_H
#define PAINTABLE_H

#include <QPainter>

class Paintable{
public:
    Paintable(){}
    virtual ~Paintable(){}
    virtual void paint(QPainter*) = 0;
};

#endif // PAINTABLE_H
