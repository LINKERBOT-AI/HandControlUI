#include "customheaderview.h"

CustomHeaderView::CustomHeaderView(Qt::Orientation orientation, QWidget *parent): QHeaderView(orientation, parent)
{
    painter = new QPainter(this);
    painter->setPen(QColor(255,255,255));
    rect = {222,222,222,222};
    paintSection(painter,rect,4);
}

void CustomHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const {
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, true);

        if(logicalIndex == 0)
        {
            QPainterPath path;
            path.addRoundedRect(rect,radius,radius);

            QRect tempRect;
            tempRect = rect;
            tempRect.setTopLeft(QPoint(rect.width()/2,0));
            QPainterPath path_tempRect;
            path_tempRect.addRect(tempRect);
            path += path_tempRect;

            tempRect = rect;
            tempRect.setTopLeft(QPoint(0,rect.height()/2));
            //path_tempRect;
            path_tempRect.addRect(tempRect);
            path += path_tempRect;

            painter->setClipPath(path);
            painter->fillPath(path,Qt::white);
        }
        else if(logicalIndex == (count() - 1))
        {
            QPainterPath path;
            path.addRoundedRect(rect,radius,radius);

            QRect tempRect;
            tempRect = rect;
            tempRect.setTopRight(QPoint(rect.x() + rect.width()/2,0));
            QPainterPath path_tempRect;
            path_tempRect.addRect(tempRect);
            path += path_tempRect;

            tempRect = rect;
            tempRect.setTopRight(QPoint(rect.x() + rect.width(),rect.height()/2));
            //path_tempRect.clear();
            path_tempRect.addRect(tempRect);
            path += path_tempRect;

            painter->setClipPath(path);
            painter->fillPath(path,Qt::white);
        }
        else
        {
            painter->fillRect(rect,Qt::white);
        }

        painter->setPen(QPen(QColor(192, 192, 192),1));
        if (logicalIndex != 0)
        {
            painter->drawLine(rect.topLeft(),rect.bottomLeft());
        }
        painter->drawLine(rect.bottomLeft(),rect.bottomRight());

        // 绘制文字
        painter->setPen(Qt::black);  // 设置文字颜色
        painter->drawText(rect.adjusted(5, 0, -5, 0), defaultAlignment(), model()->headerData(logicalIndex, orientation()).toString());

        painter->restore();
    }


