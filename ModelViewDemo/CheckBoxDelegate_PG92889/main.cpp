#include "checkboxdelegate.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QTableView>

#define MODEL_ROWS 4            //Количество строк модели
#define MODEL_COLUMN 2          //Количество столбцов модели
#define DELEGATE_COLUMN 0       //Столбец с делегатом

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Создаем модель и представление
    QStandardItemModel *model = new QStandardItemModel(MODEL_ROWS, MODEL_COLUMN);
    QTableView *tableView = new QTableView();
    CheckBoxDelegate *delegate = new CheckBoxDelegate();

    //Заолняем модель данными
    for (int row =0; row < MODEL_ROWS; ++row) {
        for (int column = 0; column < MODEL_COLUMN; ++column) {
            QModelIndex index = model->index(row, column, QModelIndex());
            if(column == 0)
                model->setData(index, QVariant(0));
            else
                model->setData(index, QVariant((row + 1) * (column + 1)));
        }

    }
    //Устанавливаем модель в представление
    tableView->setModel(model);
    //Устанавливаем делегат в столбец
    tableView->setItemDelegateForColumn(DELEGATE_COLUMN, delegate);
    //Внешний вид предтавления
    tableView->resizeColumnsToContents();
    tableView->verticalHeader()->hide();
    tableView->horizontalHeader()->setStretchLastSection(true);

    tableView->setWindowTitle("Check Box Delegate");
    tableView->show();

    return a.exec();
}
