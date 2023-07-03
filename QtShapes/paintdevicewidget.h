
#ifndef PAINTDEVICEWIDGET_H
#define PAINTDEVICEWIDGET_H


#include <QWidget>
#include <QPainter>
#include <QResizeEvent>
#include "paintable.h"


class PaintDeviceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintDeviceWidget(QWidget *parent = nullptr);
    void setPaintable(Paintable* paintable);
    Paintable* getPaintable();

protected:
    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent *) override;

private:
    Paintable* paintable = nullptr;

};

#endif // PAINTDEVICEWIDGET_H
