#include "mainwindow.h"
#include <QApplication>
//#include "myserver.h"
//#include "ssl.h"
#include <QObject>
#include <QDebug>
#include <qrsaencryption.h>
//#include <openssl/applink.c>
bool testEncryptAndDecryptExample() {

    QByteArray pub, priv;
    QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);
    e.generatePairKey(pub, priv); // or other rsa size

    QByteArray msg = "test message";

    auto encryptMessage = e.encode(msg, pub);

    if (encryptMessage == msg)
        return false;

    auto decodeMessage = e.decode(encryptMessage, priv);

    return decodeMessage == msg;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
  //  MyServer S;
    if (testEncryptAndDecryptExample()) {
            qInfo() << "Success!";
        }
    /* if(!QFile::exists((QStandardPaths::HomeLocation+"/.Rserver/private.pem"))){
    qDebug()<<QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    BIGNUM *e=BN_new();
    BN_set_word(&*e, 41);
    RSA *rsa = RSA_new();
    RSA_generate_key_ex(rsa, 1024, &*e, nullptr);
    BIO *bio_out;
    bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);
    BIO_printf(bio_out, "Hello World\n");
    FILE  *fp  = nullptr;
        //fp = fopen((QStandardPaths::HomeLocation+"/.Rserver/public.key"), "w");
        PEM_write_RSAPublicKey(fp, rsa);
        fclose(fp);
        fp = fopen((QStandardPaths::HomeLocation+"/.Rserver/private.key"), "w");
        //PEM_write_RSAPrivateKey(fp, rsa,nullptr, nullptr, NULL, nullptr, nullptr);
        fclose(fp);
      }*/
   // Ssl l;
return a.exec();
}
