
#include "tab3triangularprism.h"

Tab3TriangularPrism::Tab3TriangularPrism(QWidget *parent, PaintDeviceWidget* paintDeviceWidget)
    : QWidget(parent), paintDeviceWidget(paintDeviceWidget)
{
    QColor defaultColor = Qt::yellow;
    int defaultSize = 100;

    this->paTriangularPrism = new pa_Triangular_Prism(defaultSize,defaultSize,defaultSize);
    this->paTriangularPrism->setColor(defaultColor);

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
                     this, &Tab3TriangularPrism::updateColor);

    QObject::connect(sliderWidth, &QSlider::valueChanged,
                     this, &Tab3TriangularPrism::updateWidth);

    QObject::connect(sliderHeight, &QSlider::valueChanged,
                     this, &Tab3TriangularPrism::updateHeight);

    QObject::connect(sliderDepth, &QSlider::valueChanged,
                     this, &Tab3TriangularPrism::updateDepth);
}

void Tab3TriangularPrism::updateColor()
{
    const QColor color = QColorDialog::getColor(this->paTriangularPrism->getColor(), this, "Select Color");

    if (color.isValid()) {
        this->colorLabel->setText(color.name());
        this->colorLabel->setPalette(QPalette(color));
        this->paTriangularPrism->setColor(color);
        this->paintDeviceWidget->repaint();
    }
}

void Tab3TriangularPrism::updateWidth(int value){
    this->paTriangularPrism->setWidth(value);
    this->paintDeviceWidget->repaint();
}

void Tab3TriangularPrism::updateHeight(int value){
    this->paTriangularPrism->setHeight(value);
    this->paintDeviceWidget->repaint();
}

void Tab3TriangularPrism::updateDepth(int value){
    this->paTriangularPrism->setDepth(value);
    this->paintDeviceWidget->repaint();
}

void Tab3TriangularPrism::tabOpened(){
    this->paintDeviceWidget->setPaintable(this->paTriangularPrism);
    this->paintDeviceWidget->repaint();
}

