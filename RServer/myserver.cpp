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
  //  for (QTcpSocket* socket : _sockets) {
        if (nullptr != sender){
        QString a = QString::fromStdString(datas.toStdString());
        QString com = a.mid(0,3);
        //41
        //sender->write(QByteArray::fromStdString(/*sender->peerAddress().toString().toStdString() + ": " +*/ a.mid(0,3).toStdString()));
        //sender->write(QByteArray::fromStdString(com.toStdString()));
        if(com == "/k/"){
          QFile key(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pub");
          key.open(QIODevice::ReadWrite);
          QByteArray b = key.readAll();
          sender->write(b);
        }
        else if (com=="/g/"){
           //pošli
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
        sender->close();
    }
}
//}
