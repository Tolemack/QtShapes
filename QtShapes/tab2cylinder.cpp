
#include "tab2cylinder.h"

Tab2Cylinder::Tab2Cylinder(QWidget *parent, PaintDeviceWidget* paintDeviceWidget)
    : QWidget(parent), paintDeviceWidget(paintDeviceWidget)
{
    QColor defaultColor = Qt::red;
    int defaultSize = 100;

    this->paCylinder = new pa_Cylinder(defaultSize,defaultSize,defaultSize);
    this->paCylinder->setColor(defaultColor);

    QGridLayout* layout = new QGridLayout(this);

    QLabel* labelWidth = new QLabel("Width", this);
    QLabel* labelHeight = new QLabel("Height", this);
    QLabel* labelGradient = new QLabel("Gradient", this);

    QSlider* sliderCubeWidth = new QSlider(Qt::Horizontal,this);
    sliderCubeWidth->setSliderPosition(defaultSize);
    QSlider* sliderCubeHeight = new QSlider(Qt::Horizontal,this);
    sliderCubeHeight->setSliderPosition(defaultSize);
    this->sliderCubeGradient = new QSlider(Qt::Horizontal,this);
    sliderCubeGradient->setSliderPosition(defaultSize);
    sliderCubeGradient->setTickInterval(1);

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
    layout->addWidget(sliderCubeWidth,0,1);
    layout->addWidget(labelHeight,1,0);
    layout->addWidget(sliderCubeHeight,1,1);
    layout->addWidget(labelGradient,2,0);
    layout->addWidget(sliderCubeGradient,2,1);
    layout->addWidget(colorPickerWidget,0,2,3,1);
    layout->setColumnStretch(0,0);
    layout->setColumnStretch(1,1);
    layout->setColumnStretch(2,0);
    setLayout(layout);

    QObject::connect(colorButton, &QAbstractButton::clicked,
                     this, &Tab2Cylinder::updateColor);

    QObject::connect(sliderCubeWidth, &QSlider::valueChanged,
                     this, &Tab2Cylinder::updateWidth);

    QObject::connect(sliderCubeHeight, &QSlider::valueChanged,
                     this, &Tab2Cylinder::updateHeight);

    QObject::connect(sliderCubeGradient, &QSlider::valueChanged,
                     this, &Tab2Cylinder::updateGradient);
}

void Tab2Cylinder::updateColor()
{
    const QColor color = QColorDialog::getColor(this->paCylinder->getColor(), this, "Select Color");

    if (color.isValid()) {
        this->colorLabel->setText(color.name());
        this->colorLabel->setPalette(QPalette(color));
        this->paCylinder->setColor(color);
        this->paintDeviceWidget->repaint();
    }
}

void Tab2Cylinder::updateWidth(int value){
    this->paCylinder->setWidth(value);
    this->paintDeviceWidget->repaint();
    this->sliderCubeGradient->setMinimum(0);
    this->sliderCubeGradient->setMaximum((this->paCylinder->getDisplayedWidth()-2)/2);
}

void Tab2Cylinder::updateHeight(int value){
    this->paCylinder->setHeight(value);
    this->paintDeviceWidget->repaint();
}

void Tab2Cylinder::updateGradient(int value){
    this->paCylinder->setGradient(value);
    this->paintDeviceWidget->repaint();
}

void Tab2Cylinder::tabOpened(){
    this->paintDeviceWidget->setPaintable(this->paCylinder);
    this->paintDeviceWidget->repaint();
}
