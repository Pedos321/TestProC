#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

#define COLUMN1         "Param1"
#define COLUMN2         "Param2"
#define COLUMN3         "Param3"
#define COLUMN4         "Param4"


class dataBase : public QObject
{
    Q_OBJECT
public:
    explicit dataBase(QObject *parent = 0);
    QStringList getNames();
    QStringList Names;
    ~dataBase();

private:
    void initNames();
};


#endif // DATABASE_H
