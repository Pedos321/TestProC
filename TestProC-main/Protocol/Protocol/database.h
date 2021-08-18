#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class dataBase : public QObject
{
    Q_OBJECT
public:
    explicit dataBase(QObject *parent = 0);
    QStringList getNames();
    QStringList getHeaders(QString type);

    QStringList Names;
    ~dataBase();

private:
    void initNames();
};


#endif // DATABASE_H
