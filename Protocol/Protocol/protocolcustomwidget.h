#ifndef PROTOCOLCUSTOMWIDGET_H
#define PROTOCOLCUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTableView>



class ProtocolCustomWidget : public QWidget
{
    Q_OBJECT
public:
    ProtocolCustomWidget(QWidget *parent = nullptr);




private :
    QString* SubParagraphName;
    QLabel *lblProtocolName;
    QTableView  *tblProtocol;
private slots:

signals:


};

#endif // PROTOCOLCUSTOMWIDGET_H
