#include "modelviewdemowidget.h"
#include "checkboxdelegate.h"
#include "imagedelegate.h"
#include "checkboxheader.h"

#include <QTableView>
#include <QHeaderView>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>

// ********************************************************************************
ModelViewDemoWidget::ModelViewDemoWidget( QWidget* parent ) : QWidget( parent ) {



    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout( mainLayout );

    QLabel* mainName = new QLabel( tr( "ПП х.х Название"));
    mainName->setStyleSheet("QLabel { background-color : white; color : red; }");
    mainLayout->addWidget(mainName);






    m_view = new QTableView;


    m_view->setModel( m_model = new PersonsModel );


    //Устанавливаем делегат в столбец
    CheckBoxDelegate *delegate = new CheckBoxDelegate();
    Imagedelegate *imagedelete = new Imagedelegate();
    m_view->setItemDelegateForColumn(3,delegate);

    m_view->setItemDelegateForColumn(4,imagedelete);

    mainLayout->addWidget( m_view );

    QGridLayout* panelLayout = new QGridLayout;
    mainLayout->addLayout( panelLayout );

    QLabel* lbRemove = new QLabel( tr( "<a href=\"#\">Удалить</a>" ) );
    connect( lbRemove, SIGNAL( linkActivated( QString ) ), m_model, SLOT( removeSelected() ) );
    lbRemove->setAlignment( Qt::AlignRight );
    panelLayout->addWidget( lbRemove, 0, 10 );

    QLabel* lbSurname = new QLabel( tr( "Параметр1" ) );
    panelLayout->addWidget( lbSurname, 1, 0 );
    m_surnameEdit = new QLineEdit;
    panelLayout->addWidget( m_surnameEdit, 1, 1 );

    QLabel* lbName = new QLabel( tr( "Параметр2" ) );
    panelLayout->addWidget( lbName, 1, 2 );
    m_nameEdit = new QLineEdit;
    panelLayout->addWidget( m_nameEdit, 1, 3 );

    QLabel* lbPatronymic = new QLabel( tr( "Параметр3" ) );
    panelLayout->addWidget( lbPatronymic, 1, 4 );
    m_patronymicEdit = new QLineEdit;
    panelLayout->addWidget( m_patronymicEdit, 1, 5 );

    QLabel* lbState = new QLabel( tr( "Параметр4" ) );
    panelLayout->addWidget( lbState, 1, 6 );
    m_stateEdit = new QLineEdit;
    panelLayout->addWidget( m_stateEdit, 1, 7 );

    QLabel* lbImage = new QLabel( tr( "Параметр5" ) );
    panelLayout->addWidget( lbImage, 1, 8 );
    m_imageEdit = new QLineEdit;
    panelLayout->addWidget( m_imageEdit, 1, 9 );


    QPushButton* bnAdd = new QPushButton( tr( "Добавить" ) );
    connect( bnAdd, SIGNAL( clicked() ), SLOT( onAppend() ) );
    panelLayout->addWidget( bnAdd, 1, 10);




    resize( 800, 600 );
}

ModelViewDemoWidget::~ModelViewDemoWidget() {
}

void ModelViewDemoWidget::onAppend() {
      m_model->appendPerson(
        m_surnameEdit->text(),
        m_nameEdit->text(),
        m_patronymicEdit->text(),
        m_stateEdit->text()

    );

}

// ********************************************************************************
PersonsModel::PersonsModel( QObject* parent ) : QAbstractTableModel( parent ) {
}

int PersonsModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return m_persons.count();
}

int PersonsModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return LAST;
}

QVariant PersonsModel::data( const QModelIndex& index, int role ) const {
    if(
        !index.isValid() ||
        m_persons.count() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole )
    ) {
        return QVariant();
    }

    return m_persons[ index.row() ][ Column( index.column() ) ];
}

bool PersonsModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || m_persons.count() <= index.row() ) {
        return false;
    }

    m_persons[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}

QVariant PersonsModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case SURNAME:
        return tr( "Параметр1" );
    case NAME:
        return tr( "Параметр2" );
    case PATRONYMIC:
        return tr( "Параметр3" );
    case SELECTION:
        return tr( "Параметр4" );
    case IMAGE:
        return tr("Параметр5");
    }

    return QVariant();
}

Qt::ItemFlags PersonsModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    if( index.isValid() ) {
        if( index.column() == SELECTION ) {
            flags |= Qt::ItemIsEditable;
        }
    }

    return flags;
}

void PersonsModel::appendPerson( const QString& surname, const QString& name, const QString& patronymic, const QString& status) {
    PersonData person;
    person[ SURNAME ] = surname;
    person[ NAME ] = name;
    person[ PATRONYMIC ] = patronymic;
    person[ SELECTION ] = false;
    person[IMAGE] = status;

    int row = m_persons.count();
    beginInsertRows( QModelIndex(), row, row );
    m_persons.append( person );
    endInsertRows();
}

void PersonsModel::removeSelected() {
    int i = 0;
    Persons::iterator it = m_persons.begin();
    while( it != m_persons.end() ) {
        if( it->value( SELECTION, false ).toBool() ) {
            beginRemoveRows( QModelIndex(), i, i );
            it = m_persons.erase( it );
            endRemoveRows();
        } else {
            ++i;
            ++it;
        }

        if( it == m_persons.end() ) {
            break;
        }
    }
}
