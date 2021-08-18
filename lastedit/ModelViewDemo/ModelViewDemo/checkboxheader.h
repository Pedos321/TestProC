#ifndef CHECKBOXHEADER_H
#define CHECKBOXHEADER_H

#include <QHeaderView>

class CheckBoxHeader : public QHeaderView
{
    Q_OBJECT

public:
    CheckBoxHeader(Qt::Orientation orientation, QWidget* parent = 0);

    QRect visualRectOfColumn(int column)const;
    bool isChecked() const { return isChecked_; }
    void setIsChecked(bool value);

signals:
    void checkBoxClicked(bool);

protected:
    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const;

    void mousePressEvent(QMouseEvent* event);



private:
    bool isChecked_ = false;
    int pressColum_{-1};
};

#endif // CHECKBOXHEADER_H
