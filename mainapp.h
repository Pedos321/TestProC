#ifndef MAINAPP_H
#define MAINAPP_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSqlTableModel>
#include <QTableView>
#include <QVector>
#include "database.h"
namespace Ui {
class MainApp;
}

class MainApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainApp(QWidget *parent = 0);
    ~MainApp();

private slots:

private:
    Ui::MainApp *ui;
    DataBase                    *db;
    QSqlTableModel             *model;
    QList<QSqlTableModel*>    *listOfModels;

    void createModel(const QString &tableName, const QStringList &headers);
    QTableView createView(QSqlTableModel &model);
};

#endif // MAINAPP_H
