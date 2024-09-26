#ifndef CUSTOMHEADERVIEW_H
#define CUSTOMHEADERVIEW_H

#include <QObject>
#include <QPainter>
#include <QHeaderView>
#include <QPainterPath>
#include <QRect>
#include <QPoint>
#include <QPainter>
#include <QRect>

class CustomHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    explicit CustomHeaderView(Qt::Orientation orientation,QWidget *parent = nullptr);
private:
    int radius{6};//圆角
    QPainter *painter = nullptr;
    QRect rect;
protected:
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const override;

};

#endif // CUSTOMHEADERVIEW_H
