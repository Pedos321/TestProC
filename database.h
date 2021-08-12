#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME   "QDataWidgetMapper"
#define DATABASE_NAME       "QDataWidgetDataBase.db"

#define DEVICE                  "DeviceTable"
#define DEVICE_HOSTNAME         "Hostname"
#define DEVICE_IP               "IP"
#define DEVICE_MAC              "MAC"
#define DEVICE_NAME             "NAME"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    bool inserIntoDeviceTable(const QVariantList &data);

private:
    QSqlDatabase    db;

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createDeviceTable();
    void selectNameFromDB();
};

#endif // DATABASE_H
