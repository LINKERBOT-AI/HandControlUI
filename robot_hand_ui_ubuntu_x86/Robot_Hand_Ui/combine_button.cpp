#include "combine_button.h"

Combine_Button::Combine_Button(QWidget *parent) : QPushButton(parent) {

}

Combine_Button::~Combine_Button() {

}

void Combine_Button::paintEvent(QPaintEvent *event) {
    QPushButton::paintEvent(event);
    QPushButton secondButton(this);
    QLabel label(this);
    label.move(this->width() / 2, 0);
    secondButton.resize(this->width() / 2, this->height());
    label.setText("拇指");
    secondButton.move(this->width() / 3, 0);
    secondButton.resize(this->width() / 3, this->height());
    secondButton.setText("第二个按钮");
    QStyleOptionButton option1;
    QStylePainter painter1(this);
    option1.initFrom(&secondButton);
    painter1.drawControl(QStyle::CE_PushButton, option1);
}

void Combine_Button::mousePressEvent(QMouseEvent *event) {
    if (event->x() < this->width() / 2) {
        QPushButton::mousePressEvent(event);
    } else {
        QPushButton::mousePressEvent(event);
    }
}
