#include "protocolcustomwidget.h"

#include <QVBoxLayout>

ProtocolCustomWidget::ProtocolCustomWidget(QWidget *parent)
{

    QHBoxLayout *layout = new QHBoxLayout(this);

    lblProtocolName = new QLabel();

    tblProtocol = new QTableView;



    qDebug() << "ProtocolCustomWidget Constructor";

    layout->addWidget(lblProtocolName);
}

