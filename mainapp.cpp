#include "mainapp.h"
#include "ui_mainapp.h"
#include<QTableView>
#include <QLabel>

MainApp::MainApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainApp)
{
    ui->setupUi(this);

    db = new DataBase();
    db->connectToDataBase();

    for(int i = 0; i < 4; i++){
           QVariantList data;
           int random = 5; // Get random integers to be inserted into the database
           data.append(QDate::currentDate()); // Get the current date to be inserted into the database
           data.append(QTime::currentTime()); // Get the current time to be inserted into the database
           // Prepare the received random number to be inserted into the database
           data.append(random);
           // Prepare message for insertion into the database
           data.append("Получено сообщение от " + QString::number(random));
           // Insert data into the database
           db->inserIntoDeviceTable(data);
    }


}

MainApp::~MainApp()
{
    delete ui;
}

void MainApp::on_btnAddNew_clicked()
{

    createModel(DEVICE,QStringList() << tr("id")
                << tr("Имя хоста")
                << tr("IP адрес")
                << tr("MAC-адрес")
                << tr("Name"));


    qDebug()<<model->columnCount();
    QTableView *view = new QTableView();
    view->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    view->setModel(model);


    QLabel *label = new QLabel(model->index(0,4).data().toString());
    ui->scrollAreaWidgetContents->layout()->addWidget(label);
    ui->scrollAreaWidgetContents->layout()->addWidget(view);
    ui->scrollAreaWidgetContents->layout()->addWidget(view);

}

void MainApp::createModel(const QString &tableName, const QStringList &headers)
{
     model = new QSqlTableModel(this);
     model->setTable(tableName);
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     model->select();


     for(int i = 0, j = 0; i < model->columnCount(); i++, j++)
     {
         model->setHeaderData(i,Qt::Horizontal,headers[j]);
         qDebug()<<headers[j];
     }
     listOfModels[0].append(model);
}



//QTableView *createView(QSqlTableModel &model) Для чего
//{
//   QTableView *view = new QTableView;
//  view->setModel(&model);
//  return view;
//}

