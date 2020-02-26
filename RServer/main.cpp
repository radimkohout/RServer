#include "mainwindow.h"
#include <QApplication>
#include "myserver.h"
#include "ssl.h"
#include <QObject>
#include <QDebug>
#include <qrsaencryption.h>
#include "pooler.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Pooler p;
    MyServer S;
    Ssl l;
    QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);
    QByteArray msg = "test message";
    l.Load();
    QByteArray pri=l.Pri();
    QByteArray pub=l.Pub();
    QRSAEncryption i(QRSAEncryption::Rsa::RSA_2048);
    QByteArray epri="";
    QByteArray epub="";
    i.generatePairKey(epub,epri);
    auto encryptMessage = e.encode(msg, pri);
    encryptMessage = e.encode(encryptMessage, epub);
    auto decodeMessage = e.decode(encryptMessage, epri);
    decodeMessage = e.decode(decodeMessage, pub);
    qDebug()<<decodeMessage;
return a.exec();
}
