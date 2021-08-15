#ifndef PROTOCOLCUSTOMWIDGET_H
#define PROTOCOLCUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTableView>



class ProtocolCustomWidget : public QWidget
{
    Q_OBJECT
public:
    ProtocolCustomWidget(QString *name, QWidget *parent = nullptr);




private :
    QLabel *lblProtocolName;
    QTableView  *tblProtocol;

    void setName(QString *name);
    void setWidgetName(QString &name);
    void createModel(const QString &tableName, const QStringList &headers);

private slots:

signals:


};

#endif // PROTOCOLCUSTOMWIDGET_H
