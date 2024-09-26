#ifndef SWITCH_BUTTON_H
#define SWITCH_BUTTON_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QVariantAnimation>
#include <QMap>
#include <QGuiApplication>
#include <string.h>
#include <QDebug>
class switch_Button : public QWidget
{
    Q_OBJECT
public:
    explicit switch_Button(QString,QWidget *parent = nullptr);
    QSize sizeHint() const override;//当一个函数后面加上"const"时，这意味着这个函数不能修改传递给它的任何参数的值
    bool isOpened() const;

signals:
    void clicked(bool, QString);


private:
    void setButtonPos(float where);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);



private:
    bool opened;
    bool hover;
    float atWhere;
    QPoint pressPt;

    QString m_pDataType;

};

#endif // SWITCH_BUTTON_H
