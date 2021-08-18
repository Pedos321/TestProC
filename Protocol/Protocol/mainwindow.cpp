#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "protocolcustomwidget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new dataBase();

    QStringList *namesFromDB = new QStringList();

    *namesFromDB = (db->Names);

    qDebug()<<*namesFromDB;




}

MainWindow::~MainWindow()
{
    delete ui;
}


