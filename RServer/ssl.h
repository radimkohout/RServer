#ifndef SSL_H
#define SSL_H
#include <QObject>
//#include <openssl/rsa.h>
#include <QFile>
#include <QStandardPaths>
/*#include <openssl/bn.h>
#include <openssl/pem.h>*/
#include <QDebug>
#include <QDir>
#include <QIODevice>
class Ssl
{
public:
    Ssl();
    void GenKey();
};

#endif // SSL_H
