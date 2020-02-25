#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void MyServer::newConnection()
{

    QTcpSocket *socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
/*
    //socket->write("hello client\r\n");
    //socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();*/
}
void MyServer::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
        if (nullptr != sender){
        QString a = QString::fromStdString(datas.toStdString());
        QString com = a.mid(0,3);
        //41
        if(com == "/k/"){
            if(a.length() > 3){
                //ulož si klíč
                //bez něj end to end nemůže fungovat
                qDebug()<<a.mid(3,a.length()-3);
                QByteArray cpub = a.mid(3,a.length()-3).toUtf8();
            }
            else{
                Ssl l;
                l.Load();
                qDebug()<<l.Pub().toBase64();
                sender->write(l.Pub().toBase64());
            }
        }
        else if (com=="/g/"){
           //pošli
            sender->write("");
        }
        else if (com=="/s/") {
           //ulož ke zpracování
        }
        else if (com=="/o/") {
           //kompresuj příjem
        }
        else {
            sender->write("Nope");
        }
        //sender->write("SA");
        sender->flush();
        sender->waitForBytesWritten(5000);
       // sender->close();
    }
}
