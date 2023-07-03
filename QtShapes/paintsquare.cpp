
#include <iostream>
#include <QWidget>
#include <QPainter>


class PaintSquare : public QWidget {
public :
    explicit PaintSquare(QWidget *parent = nullptr)
        : QWidget{parent}
    {}

protected:
    void paintEvent(QPaintEvent* event) override {

        QPainter painter;
        painter.begin(this);
        //painter.setRenderHint(QPainter::Antialiasing);

        QBrush brush(QColor(128, 128, 255));
        QRect rectangle(0,0,1000,1000);
        painter.fillRect(rectangle, brush);

        painter.end();
    }
};
