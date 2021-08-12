#include "mainapp.h"
#include "ui_mainapp.h"
#include<QTableView>
#include <QLabel>

MainApp::MainApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainApp)
{
    ui->setupUi(this);
}

MainApp::~MainApp()
{
    delete ui;
}

void MainApp::on_btnAddNew_clicked()
{
    QLabel *label = new QLabel("Text");
    ui->scrollAreaWidgetContents->layout()->addWidget(label);


    createModel(DEVICE,QStringList() << tr("id")
                << tr("Имя хоста")
                << tr("IP адрес")
                << tr("MAC-адрес")
                << tr("Name"));

    QTableView *view = new QTableView();
    view->setModel(model);

    ui->scrollAreaWidgetContents->layout()->addWidget(view);


}

void MainApp::createModel(const QString &tableName, const QStringList &headers)
{
     model = new QSqlTableModel(this);
     model->setTable(tableName);
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     model->select();

     for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
         model->setHeaderData(i,Qt::Horizontal,headers[j]);
     }
}



//QTableView *createView(QSqlTableModel &model) Для чего
//{
//   QTableView *view = new QTableView;
//  view->setModel(&model);
//  return view;
//}

