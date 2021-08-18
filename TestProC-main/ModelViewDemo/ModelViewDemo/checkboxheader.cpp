#include "checkboxheader.h"
#include <QCheckBox>
#include <QApplication>
#include <QDebug>


CheckBoxHeader::CheckBoxHeader(Qt::Orientation orientation, QWidget* parent) :QHeaderView(orientation,parent)
{
    isChecked_=false;
}


void CheckBoxHeader::paintSection(QPainter* painter, const QRect &rect, int logicalIndex) const
{

    painter->save();

    QHeaderView::paintSection(painter,rect,logicalIndex);

    painter->restore();

    QStyleOptionButton option;

    QRect checkbox_rect = style()->subElementRect(QStyle::SE_CheckBoxIndicator,&option);
    checkbox_rect.moveCenter(rect.center());

    if(logicalIndex==0)
    {
        qDebug()<<checkbox_rect<<" --"<<rect;
        //position
        option.state = QStyle::State_Enabled|QStyle::State_Active;
        option.rect = checkbox_rect;
        QHeaderView::paintSection(painter,checkbox_rect,logicalIndex);

        if(isChecked_)
            option.state|=QStyle::State_On;
        else
            option.state|=QStyle::State_Off;
        option.state |=QStyle::State_Off;

        style()->drawPrimitive(QStyle::PE_IndicatorCheckBox,&option, painter);
    }
}

void CheckBoxHeader::mousePressEvent(QMouseEvent *event)
{
    setIsChecked(!isChecked());
    emit checkBoxClicked(isChecked());
}

void CheckBoxHeader::redrawCheckBox()
{
    viewport()->update();
}

void CheckBoxHeader::setIsChecked(bool value)
{
    if(isChecked_ !=value)
    {
        isChecked_ = value;
        redrawCheckBox();
    }
}
