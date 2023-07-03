
#include "tab1cube.h"

Tab1Cube::Tab1Cube(QWidget *parent, PaintDeviceWidget* paintDeviceWidget)
    : QWidget(parent), paintDeviceWidget(paintDeviceWidget)
{
    QColor defaultColor = Qt::blue;
    int defaultSize = 100;

    this->paCube = new pa_Cube(defaultSize,defaultSize,defaultSize);
    this->paCube->setColor(defaultColor);

    QGridLayout* layout = new QGridLayout(this);

    QLabel* labelWidth = new QLabel("Width", this);
    QLabel* labelHeight = new QLabel("Height", this);
    QLabel* labelDepth = new QLabel("Depth", this);

    QSlider* sliderWidth = new QSlider(Qt::Horizontal,this);
    sliderWidth->setSliderPosition(defaultSize);
    QSlider* sliderHeight = new QSlider(Qt::Horizontal,this);
    sliderHeight->setSliderPosition(defaultSize);
    QSlider* sliderDepth = new QSlider(Qt::Horizontal,this);
    sliderDepth->setSliderPosition(defaultSize);

    QWidget* colorPickerWidget = new QWidget(this);
    colorPickerWidget->setFixedWidth(100);
    QVBoxLayout* colorPickerLayout = new QVBoxLayout(colorPickerWidget);
    QPushButton* colorButton = new QPushButton("&Color", colorPickerWidget);
    this->colorLabel = new QLabel(defaultColor.name(), colorPickerWidget);
    this->colorLabel->setPalette(QPalette(defaultColor));
    this->colorLabel->setAutoFillBackground(true);
    colorLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    colorLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    colorPickerLayout->addWidget(colorButton);
    colorPickerLayout->addWidget(colorLabel);
    colorPickerWidget->setLayout(colorPickerLayout);

    layout->addWidget(labelWidth,0,0);
    layout->addWidget(sliderWidth,0,1);
    layout->addWidget(labelHeight,1,0);
    layout->addWidget(sliderHeight,1,1);
    layout->addWidget(labelDepth,2,0);
    layout->addWidget(sliderDepth,2,1);
    layout->addWidget(colorPickerWidget,0,2,3,1);
    layout->setColumnStretch(0,0);
    layout->setColumnStretch(1,1);
    layout->setColumnStretch(2,0);
    setLayout(layout);

    QObject::connect(colorButton, &QAbstractButton::clicked,
                     this, &Tab1Cube::updateColor);

    QObject::connect(sliderWidth, &QSlider::valueChanged,
                     this, &Tab1Cube::updateWidth);

    QObject::connect(sliderHeight, &QSlider::valueChanged,
                     this, &Tab1Cube::updateHeight);

    QObject::connect(sliderDepth, &QSlider::valueChanged,
                     this, &Tab1Cube::updateDepth);
}

void Tab1Cube::updateColor()
{
    const QColor color = QColorDialog::getColor(this->paCube->getColor(), this, "Select Color");

    if (color.isValid()) {
        this->colorLabel->setText(color.name());
        this->colorLabel->setPalette(QPalette(color));
        this->paCube->setColor(color);
        this->paintDeviceWidget->repaint();
    }
}

void Tab1Cube::updateWidth(int value){
    this->paCube->setWidth(value);
    this->paintDeviceWidget->repaint();
}

void Tab1Cube::updateHeight(int value){
    this->paCube->setHeight(value);
    this->paintDeviceWidget->repaint();
}

void Tab1Cube::updateDepth(int value){
    this->paCube->setDepth(value);
    this->paintDeviceWidget->repaint();
}

void Tab1Cube::tabOpened(){
    this->paintDeviceWidget->setPaintable(this->paCube);
    this->paintDeviceWidget->repaint();
}

