#ifndef COMBINE_BUTTON_H
#define COMBINE_BUTTON_H

#include <QObject>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QStyleOptionButton>
#include <QStylePainter>
#include <QLabel>

class Combine_Button : public QPushButton
{
    Q_OBJECT
public:
    Combine_Button(QWidget *parent = nullptr);
    ~Combine_Button();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // COMBINE_BUTTON_H
