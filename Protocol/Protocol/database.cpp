#include "database.h"
#include <QDebug>

dataBase::dataBase(QObject *parent) : QObject(parent)
{
     Names = getNames();
     qDebug()<<Names;

}
dataBase::~dataBase()
{

}

void dataBase::initNames()
{

}

QStringList dataBase::getNames()
{
    QStringList returnNames;

    returnNames.append("OneName");
    returnNames.append("TwoName");
    returnNames.append("ThirdName");

    qDebug() << returnNames;


    return returnNames;

}
