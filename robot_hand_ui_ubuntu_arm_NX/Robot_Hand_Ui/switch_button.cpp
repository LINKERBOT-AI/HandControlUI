#include "switch_button.h"

switch_Button::switch_Button(QString type,QWidget *parent) : QWidget(parent) {
    m_pDataType = type;
    opened = false;
    hover = false;
    atWhere = 0;

}

void switch_Button::setButtonPos(float where) {
    atWhere = where;
    update();
}

bool switch_Button::isOpened() const {
    return opened;
}

void switch_Button::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    qreal rad = height() * 0.5;
    int xleft = rad;
    int xright = width() - rad;
    int xpos = xleft + (xright - xleft) * atWhere;
    painter.setPen(Qt::NoPen);
    painter.setBrush((xpos == xright) ? QColor(0, 170, 255) : QColor(173, 173, 173));
    painter.drawRoundedRect(0, 0, width(), height(), rad, rad);
    if (hover) {
        painter.setBrush(QColor(255, 255, 255, 63));
        painter.drawRoundedRect(0, 0, width(), height(), rad, rad);
    }

    painter.setPen(QColor(213, 213, 213));
    painter.setBrush(QColor(243, 243, 243));
    painter.drawEllipse(QPointF(xpos, rad), rad - 1, rad -1);
}

void switch_Button::mousePressEvent(QMouseEvent *event) {
    pressPt = event->pos();
}

void switch_Button::mouseReleaseEvent(QMouseEvent *event) {
    if (pressPt == event->pos()) {
        opened = !opened;
        emit clicked(opened, m_pDataType);
        QVariantAnimation *ani = new QVariantAnimation(this);
        ani->setStartValue(0.0f);
        ani->setEndValue(1.0f);
        ani->setDuration(200);
        ani->setDirection(opened ? QVariantAnimation::Forward : QVariantAnimation::Backward);
        connect(ani, &QVariantAnimation::valueChanged, this, [this](const QVariant& value) {
            setButtonPos(value.toFloat());
        });
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }

}

void switch_Button::enterEvent(QEvent *event)
{
    hover = true;
    update();
}

void switch_Button::leaveEvent(QEvent *event)
{
    hover = false;
    update();
}

QSize switch_Button::sizeHint() const
{
    return QSize(30, 18);
}












