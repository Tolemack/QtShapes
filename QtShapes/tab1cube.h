
#ifndef TAB1CUBE_H
#define TAB1CUBE_H


#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QColorDialog>

#include "pa_cube.h"
#include "paintdevicewidget.h"

class Tab1Cube : public QWidget
{
    Q_OBJECT

public:
    Tab1Cube(QWidget *parent = nullptr, PaintDeviceWidget* = nullptr);
    void tabOpened();

private:
    PaintDeviceWidget* paintDeviceWidget;
    pa_Cube* paCube;
    QLabel* colorLabel;

public slots:
    void updateWidth(int);
    void updateHeight(int);
    void updateDepth(int);
    void updateColor();
};

#endif // TAB1CUBE_H
