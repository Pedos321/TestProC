#ifndef PROTOCOLCUSTOMWIDGET_H
#define PROTOCOLCUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QAbstractTableModel>


class UnitsModel;
// ********************************************************************************
class ProtocolCustomWidget : public QWidget
{
    Q_OBJECT
public:
    ProtocolCustomWidget(QWidget *parent = 0);
    ~ProtocolCustomWidget();
    void setName(const QString &name);
    void setModel(QStringList *headers);


private :
    QLabel      *lblProtocolName;
    QTableView  *tblProtocol;
    UnitsModel  *unitModel;
    QString     *widgetName;


};
// ********************************************************************************
class UnitsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    UnitsModel( QObject* parent = 0 );

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

private:
    enum Column {
        UNITONE = 0,
        UNITTWO,
        UNITTHREE,
        SELECTION,
        IMAGE,
        LAST
    };

    typedef QHash< Column, QVariant > UnitData;
    typedef QList< UnitData > Units;
    Units units;

};


#endif // PROTOCOLCUSTOMWIDGET_H
