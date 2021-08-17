#ifndef CHECKBOXHEADER_H
#define CHECKBOXHEADER_H

#include <QHeaderView>

class CheckBoxHeader : public QHeaderView
{
    Q_OBJECT

public:
    CheckBoxHeader(Qt::Orientation orientation, QWidget* parent = 0);

    QRect visualRectOfColumn(int column)const;
    bool all_first_columns_checked(int logicalIIndex=0);
    bool all_first_cilumns_unchecded(int logicalIndex=0);
    bool isChecked() const { return isChecked_; }

    void setIsChecked(bool value);
    void setAllRowHaveDifValues(bool value);

signals:
    void checkBoxClicked();

protected:
    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const;

    void mousePressEvent(QMouseEvent* event);



private:
    bool isChecked_ = false, AllRowHaveDifValues = false;
    int pressColum_{-1};

    void redrawCheckBox();
};

#endif // CHECKBOXHEADER_H
