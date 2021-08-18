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
QStringList dataBase::getHeaders(QString type)
{
    QStringList returnHeaders;
    if(type == "OneName")
    {
        returnHeaders<<tr("Параметр1")
                     <<tr("Параметр2")
                     <<tr("Параметр3")
                     <<tr("Параметр4");
    }
    else if(type=="TwoName")
    {
        returnHeaders<<tr("Параметр1")
                     <<tr("Параметр2")
                     <<tr("Параметр3");
    }
    else if(type=="ThirdName")
    {
        returnHeaders<<tr("Параметр1")
                     <<tr("Параметр2");
    }
    qDebug()<<returnHeaders;
    return returnHeaders;
}

