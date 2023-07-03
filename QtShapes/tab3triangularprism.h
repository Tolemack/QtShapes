
#ifndef TAB3TRIANGULARPRISM_H
#define TAB3TRIANGULARPRISM_H


#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QColorDialog>

#include "pa_triangular_prism.h"
#include "paintdevicewidget.h"

class Tab3TriangularPrism : public QWidget
{
    Q_OBJECT

public:
    Tab3TriangularPrism(QWidget *parent = nullptr, PaintDeviceWidget* = nullptr);
    void tabOpened();

private:
    PaintDeviceWidget* paintDeviceWidget;
    pa_Triangular_Prism* paTriangularPrism;
    QLabel* colorLabel;

public slots:
    void updateWidth(int);
    void updateHeight(int);
    void updateDepth(int);
    void updateColor();
};

#endif // TAB3TRIANGULARPRISM_H
