#ifndef MYCUSTOMWIDGET_H
#define MYCUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QAbstractTableModel>

class CustomModel;

// ********************************************************************************
class MyCustomWidget : public QWidget {
    Q_OBJECT
public:
    MyCustomWidget(QString name, QWidget* parent = 0 );
    ~MyCustomWidget();

    void setNameLabel(QString);

private:
    QLabel*           m_label;
    QTableView*       m_view;
    CustomModel*      m_model;


};

// ********************************************************************************
//class CustomModel : public QAbstractTableModel {
//    Q_OBJECT
//public:
//    CustomModel( QObject* parent = 0 );

//    int rowCount( const QModelIndex& parent ) const;
//    int columnCount( const QModelIndex& parent ) const;
//    QVariant data( const QModelIndex& index, int role ) const;
//    bool setData( const QModelIndex& index, const QVariant& value, int role );
//    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
//    Qt::ItemFlags flags( const QModelIndex& index ) const;


//private:
//    enum Column {
//        SURNAME = 0,
//        NAME,
//        PATRONYMIC,
//        SELECTION,
//        IMAGE,
//        LAST
//    };

//    typedef QHash< Column, QVariant > PersonData;
//    typedef QList< PersonData > Persons;
//    Persons m_persons;
//};

#endif // MYCUSTOMWIDGET_H
