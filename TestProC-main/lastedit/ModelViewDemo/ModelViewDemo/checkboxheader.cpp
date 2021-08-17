#include "checkboxheader.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>


CheckBoxHeader::CheckBoxHeader(Qt::Orientation orientation, QWidget* parent /*= 0*/)
    : QHeaderView(orientation, parent)
{
    //isChecked_ = true;
    this->setMouseTracking(true);
}

void CheckBoxHeader::paintSection(QPainter  *painter, const QRect& rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();

    if (logicalIndex == 0)
    {
        QStyleOptionButton option;
        QRect checkbox_rect = style()->subElementRect(QStyle::SE_CheckBoxIndicator,&option);
        checkbox_rect.moveCenter(rect.center());


        option.state = QStyle::State_Enabled | QStyle::State_Active;
        option.rect = checkbox_rect;

        if (isChecked_)
            option.state |= QStyle::State_On;
        else
            option.state |= QStyle::State_Off;
        option.state |= QStyle::State_Off;
        QHeaderView::paintSection(painter,checkbox_rect,logicalIndex);
        style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);

    }
}

void CheckBoxHeader::mousePressEvent(QMouseEvent *event)
{
    pressColum_ = this->visualIndexAt(event->pos().x());
    qDebug()<<pressColum_;
    if(pressColum_ ==-1){
        isChecked_ = false;
        return QHeaderView::mousePressEvent(event);
    }
    QStyleOptionButton option;
    QRect checkbox_rect = style()->subElementRect(QStyle::SE_CheckBoxIndicator,&option);
    checkbox_rect.moveCenter(this->visualRectOfColumn(pressColum_).center());
    isChecked_ = checkbox_rect.contains(event->pos());
    QHeaderView::mousePressEvent(event);

    emit checkBoxClicked();
}

void CheckBoxHeader::redrawCheckBox()
{
    viewport()->update();
}

void CheckBoxHeader::setIsChecked(bool val)
{
    if (isChecked_ != val)
    {
        isChecked_ = val;

        redrawCheckBox();
    }
}

void CheckBoxHeader::setAllRowHaveDifValues(bool value)
{
    //true если все столбцы имеют одинаковые значения alltrue/allfalse
    AllRowHaveDifValues = value;
}

QRect CheckBoxHeader::visualRectOfColumn(int column) const
{
    int x = sectionViewportPosition(column);
    int y=0;
    int h= this->height();
    int w= this->sectionSize(column);
    return QRect(x,y,w,h);
}
