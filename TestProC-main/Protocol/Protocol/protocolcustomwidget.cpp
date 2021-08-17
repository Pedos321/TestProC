#include "protocolcustomwidget.h"

#include <QVBoxLayout>

ProtocolCustomWidget::ProtocolCustomWidget(QString *name, QWidget *parent)
{

    QHBoxLayout *layout = new QHBoxLayout(this);

    lblProtocolName = new QLabel();

    tblProtocol = new QTableView;



    qDebug() << "ProtocolCustomWidget Constructor";

    layout->addWidget(lblProtocolName);
}

void ProtocolCustomWidget::setName(QString *name)
{

}

void ProtocolCustomWidget::createModel(const QString &tableName, const QStringList &headers)
{
     //model = new QSqlTableModel(this);
     //model->setTable(tableName);
     //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     //model->select();


     //for(int i = 0, j = 0; i < model->columnCount(); i++, j++)
     //{
         //model->setHeaderData(i,Qt::Horizontal,headers[j]);
         //qDebug()<<headers[j];
     //}
}
