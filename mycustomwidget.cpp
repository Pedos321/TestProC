#include "mycustomwidget.h"

#include <QDebug>
#include <QTableView>
#include <QHeaderView>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QString>


MyCustomWidget::MyCustomWidget(QString name,QWidget* parent ) : QWidget( parent ) {
    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout( mainLayout );

#define LabelName{
    m_label = new QLabel();
    setNameLabel(name);
    //Устанвка названия

    //
    m_label->setStyleSheet("QLabel { background-color : white; color : red; }");
    mainLayout->addWidget(m_label);
#define LabelName}

}
MyCustomWidget::~MyCustomWidget(){}

void MyCustomWidget::setNameLabel(QString name){
    m_label->setText(name);
}
//CustomModel::CustomModel( QObject* parent ) : QAbstractTableModel( parent ) {
//    }
