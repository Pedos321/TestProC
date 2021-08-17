#ifndef IMAGEDELEGATE_H
#define IMAGEDELEGATE_H

#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>


class Imagedelegate : public QItemDelegate
{
    Q_OBJECT
public:
    Imagedelegate();

    QSize sizeHint(const QStyleOptionViewItem &option,
                           const QModelIndex &index) const override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const override;
};

#endif // IMAGEDELEGATE_H
