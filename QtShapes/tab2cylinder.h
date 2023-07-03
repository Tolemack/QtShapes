
#ifndef TAB2CYLINDER_H
#define TAB2CYLINDER_H


#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QColorDialog>

#include "pa_cylinder.h"
#include "paintdevicewidget.h"

class Tab2Cylinder : public QWidget
{
    Q_OBJECT

public:
    Tab2Cylinder(QWidget *parent = nullptr, PaintDeviceWidget* = nullptr);
    void tabOpened();

private:
    PaintDeviceWidget* paintDeviceWidget;
    pa_Cylinder* paCylinder;
    QLabel* colorLabel;
    int displayedWidth();
    QSlider* sliderCubeGradient;


public slots:
    void updateWidth(int);
    void updateHeight(int);
    void updateGradient(int);
    void updateColor();
};

#endif // TAB2CYLINDER_H
