#include "imagedelegate.h"
#include "math.h"

#include <QPainter>
#include <QDebug>


Imagedelegate::Imagedelegate()
{

}

QSize Imagedelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QItemDelegate::sizeHint(option, index);
}

void Imagedelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItem myOption = option;

    if (index.column()==4)
    {
        QString data = index.model()->data(index, Qt::DisplayRole).toString();


        myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;


        QString icon = "C:/Users/AlsAr/Desktop/QtProjects/TestProC-main/TestProC-main/ModelViewDemo/Icon" + index.model()->data(index, Qt::DisplayRole).toString();

        qDebug() << icon;

        QPixmap pixmap2(icon);

        painter->drawPixmap(myOption.rect.x()+30,myOption.rect.y(),20,20, pixmap2);
    }
    else
    {
        drawDisplay(painter, option, option.rect, index.model()->data(index, Qt::DisplayRole).toString());

    }
    drawFocus(painter, myOption, myOption.rect);


}
