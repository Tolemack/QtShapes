
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QResizeEvent>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QColorDialog>
#include <QTabWidget>
#include "paintdevicewidget.h"
#include "tab1cube.h"
#include "tab2cylinder.h"
#include "tab3triangularprism.h"

class MainWindow : public QWidget

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    PaintDeviceWidget* paintDeviceWidget;
    void resizeEvent(QResizeEvent *) override;

private:
    Tab1Cube* tab1;
    Tab2Cylinder* tab2;
    Tab3TriangularPrism* tab3;

public slots:
    void tabChanged(int);

};

#endif // MAINWINDOW_H
