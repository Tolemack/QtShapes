
#include "mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,600);

    QGridLayout *layout = new QGridLayout();

    this->paintDeviceWidget = new PaintDeviceWidget();

    QTabWidget *tabWidget = new QTabWidget(this);
    this->tab1 = new Tab1Cube(this, this->paintDeviceWidget);
    this->tab2 = new Tab2Cylinder(this, this->paintDeviceWidget);
    this->tab3 = new Tab3TriangularPrism(this, this->paintDeviceWidget);
    tabWidget->addTab(tab1,"Cube");
    tabWidget->addTab(tab2,"Cylinder");
    tabWidget->addTab(tab3,"Triangular Prism");
    tabWidget->setTabPosition(QTabWidget::South);

    tabWidget->setFixedHeight(150);

    layout->addWidget(paintDeviceWidget,0,0);
    layout->addWidget(tabWidget,1,0);

    setLayout(layout);

    QObject::connect(tabWidget, &QTabWidget::currentChanged,
                     this, &MainWindow::tabChanged);
}

MainWindow::~MainWindow()
{
}

void MainWindow::resizeEvent(QResizeEvent *event){
    std::cout << "Resize mainWindow :"
              << event->size().width() << "/"
              << event->size().height()
              << std::endl;
}

void MainWindow::tabChanged(int index){
    if(index == 0){
        this->tab1->tabOpened();
    } else if(index == 1){
        this->tab2->tabOpened();
    } else if(index == 2){
        this->tab3->tabOpened();
    }
}
