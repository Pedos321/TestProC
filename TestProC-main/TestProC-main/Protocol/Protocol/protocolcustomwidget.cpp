#include "protocolcustomwidget.h"
#include <QDebug>
#include <QVBoxLayout>

#include <QHeaderView>


// ********************************************************************************
ProtocolCustomWidget::ProtocolCustomWidget(QWidget *parent):  QWidget( parent )
{

    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout( layout );

    lblProtocolName = new QLabel();



    tblProtocol = new QTableView;
    tblProtocol->setModel( unitModel = new UnitsModel );
    tblProtocol->horizontalHeader()->setResizeContentsPrecision(QHeaderView::Stretch);


    qDebug() << "ProtocolCustomWidget Constructor";

    layout->addWidget(lblProtocolName);
    layout->addWidget(tblProtocol);

    resize( 800, 600 );
}

ProtocolCustomWidget::~ProtocolCustomWidget() {
}

void ProtocolCustomWidget::setName(const QString &name){
   lblProtocolName->setText(lblProtocolName->text() + name);
   lblProtocolName->setStyleSheet("QLabel { background-color : white; color : red; }");
   qDebug()<<lblProtocolName->text();
}
void ProtocolCustomWidget::setModel(QStringList *headers){



}

// ********************************************************************************
// ********************************************************************************
UnitsModel::UnitsModel( QObject* parent ) : QAbstractTableModel( parent ) {
}

int UnitsModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return units.count();
}

int UnitsModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return LAST;
}

QVariant UnitsModel::data( const QModelIndex& index, int role ) const {
    if(
        !index.isValid() ||
        units.count() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole )
    ) {
        return QVariant();
    }

    return units[ index.row() ][ Column( index.column() ) ];
}

bool UnitsModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || units.count() <= index.row() ) {
        return false;
    }

    units[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}

QVariant UnitsModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case UNITONE:
        return tr( "Параметр1-str" );
    case UNITTWO:
        return tr( "Параметр2-str" );
    case UNITTHREE:
        return tr( "Параметр3-str" );
    case SELECTION:
        return tr( "Параметр4-bool" );
    case IMAGE:
        return tr("Статус");
    }

    return QVariant();
}

Qt::ItemFlags UnitsModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    if( index.isValid() ) {
        if( index.column() == SELECTION ) {
            flags |= Qt::ItemIsEditable;
        }
    }

    return flags;
}
