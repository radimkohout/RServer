#ifndef SSL_H
#define SSL_H
#include <QObject>
#include <QFile>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QIODevice>
#include <qrsaencryption.h>
class Ssl
{
public:
    Ssl();
    void GenKey();
    void Load();
    QByteArray Pri();
    QByteArray Pub();
    QByteArray pri;
    QByteArray pub;
    QByteArray cpub;
    void FromClient(QByteArray key);
    QByteArray Encrypt(QByteArray data);
    QByteArray Decrypt(QByteArray data);
private:
    QRSAEncryption e;
};

#endif // SSL_H
