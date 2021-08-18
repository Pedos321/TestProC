#include "alignmentdelegate.h"

AlignmentDelegate::AlignmentDelegate(Qt::Alignment alignment,QWidget* parent /*= 0*/)
{
    m_alignment = alignment;
}

void AlignmentDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem alignmentOption(option);
    alignmentOption.displayAlignment = m_alignment;
    QStyledItemDelegate::paint(painter,alignmentOption,index);
}
