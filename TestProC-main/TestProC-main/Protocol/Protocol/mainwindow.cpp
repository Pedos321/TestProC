#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "protocolcustomwidget.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new dataBase();

    QStringList *namesFromDB = new QStringList();
    QStringList *headersFromDB = new QStringList();




    *namesFromDB = (db->Names);
    *headersFromDB =(db->getHeaders("OneName"));

    qDebug()<<*namesFromDB;
    qDebug()<<*headersFromDB;

    ProtocolCustomWidget *customWidget = new ProtocolCustomWidget(this);
    customWidget->setName(namesFromDB->at(0));
    customWidget->setModel(headersFromDB);
    qDebug()<<namesFromDB->at(0);
    this->layout()->addWidget(customWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


