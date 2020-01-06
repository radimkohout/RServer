#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QFile>
#include <QStandardPaths>
class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    
signals:
    
public slots:
    void newConnection();
    void onReadyRead();

private:
    QTcpServer *server;
    QList<QTcpSocket*>  _sockets;
    QString a;
    QString com;
    QTcpSocket *socket;
};

#endif // MYSERVER_H
