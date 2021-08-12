#ifndef MODELVIEWDEMOWIDGET_H
#define MODELVIEWDEMOWIDGET_H

#include <QWidget>
#include <QAbstractTableModel>

class QTableView;
class QLineEdit;

class PersonsModel;

// ********************************************************************************
class ModelViewDemoWidget : public QWidget {
    Q_OBJECT

public:
    ModelViewDemoWidget( QWidget* parent = 0 );
    ~ModelViewDemoWidget();

private slots:
    void onAppend();

private:
    QTableView* m_view;
    PersonsModel* m_model;

    QLineEdit* m_surnameEdit;
    QLineEdit* m_nameEdit;
    QLineEdit* m_patronymicEdit;
    QLineEdit* m_stateEdit;
};

// ********************************************************************************
class PersonsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    PersonsModel( QObject* parent = 0 );

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendPerson( const QString& surname, const QString& name, const QString& patronymic, const QString& status );

public slots:
    void removeSelected();

private:
    enum Column {
        SURNAME = 0,
        NAME,
        PATRONYMIC,
        SELECTION,
        IMAGE,
        LAST
    };

    typedef QHash< Column, QVariant > PersonData;
    typedef QList< PersonData > Persons;
    Persons m_persons;

};

#endif // MODELVIEWDEMOWIDGET_H
