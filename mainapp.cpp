#include "mainapp.h"
#include "ui_mainapp.h"
#include "mycustomwidget.h"

#include<QTableView>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QString>

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

    //Создаем скролл чтобы в него вписать виджеты с подпунктами протокола
    QScrollArea* scroll = new QScrollArea;
       QVBoxLayout* layout = new QVBoxLayout;
       //for(int i = 0; i < 100; ++i)
       //layout -> addWidget(new QPushButton("text"));

       MyCustomWidget* widgetOne = new MyCustomWidget("widgetOne");
       MyCustomWidget* widgetTwo = new MyCustomWidget("widgetTwo");
       MyCustomWidget* widgetThree = new MyCustomWidget("widgetThree");
       layout->addWidget(widgetOne);
       layout->addWidget(widgetTwo);
       layout->addWidget(widgetThree);

       QWidget* widget = new QWidget;
       widget -> setLayout(layout);
       scroll -> setWidget(widget);
       scroll -> show();





       scroll->resize(500,500);

}

MainApp::~MainApp()
{
    delete ui;
}




