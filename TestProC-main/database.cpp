#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    if(!QFile("C:/QtProjects/QScrollArea-master/TestProC" DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createDeviceTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Failed to restore the database";
        return false;
    }
    return false;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("C:/QtProjects/QScrollArea-master/TestProC" DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}

bool DataBase::createDeviceTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " DEVICE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            DEVICE_HOSTNAME  " VARCHAR(255)    NOT NULL,"
                            DEVICE_IP        " VARCHAR(16)     NOT NULL,"
                            DEVICE_MAC       " VARCHAR(18)     NOT NULL,"
                            DEVICE_NAME      " VARCHAR(18)     NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << DEVICE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::inserIntoDeviceTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " DEVICE " ( " DEVICE_HOSTNAME ", "
                                              DEVICE_IP ", "
                                              DEVICE_MAC " ) "
                  "VALUES (:Hostname, :IP, :MAC )");
    query.bindValue(":Hostname",    data[0].toString());
    query.bindValue(":IP",          data[1].toString());
    query.bindValue(":MAC",         data[2].toString());

    if(!query.exec()){
        qDebug() << "error insert into " << DEVICE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

void DataBase::selectNameFromDB()
{

}
