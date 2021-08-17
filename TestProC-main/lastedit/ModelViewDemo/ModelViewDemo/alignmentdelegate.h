#ifndef ALIGNMENTDELEGATE_H
#define ALIGNMENTDELEGATE_H

#include <QStyledItemDelegate>

class AlignmentDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
        AlignmentDelegate(Qt::Alignment alignment,QWidget* parent = 0);
        virtual void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index)const;

private:
        Qt::Alignment m_alignment;
};

#endif // ALIGNMENTDELEGATE_H
