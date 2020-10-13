#include "ssl.h"
Ssl::Ssl()
{
if(!QFile::exists(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pri")||!QFile::exists(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pub")){
    GenKey();
}
QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);
}
void Ssl::GenKey(){
    QByteArray pub, priv;
   // QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);
    e.generatePairKey(pub, priv); // or other rsa size
     if(!QFile::exists(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pri")||!QFile::exists(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pub")){
         qDebug()<<"k";
      QDir dir(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/");
      if (!dir.exists()){
      dir.mkpath(".");
      }else{
          //qDebug()<<"";
      }
     QString fpri=QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pri";
      if ( e.save(fpri, priv) )
      {

      }
      else{
       qDebug()<<"Nope";
       exit(EXIT_FAILURE);
      }
      QString fpub = QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pub";
      if ( e.save(fpub,pub) )
      {

      }
      else{
          qDebug()<<"Nope";
          exit(EXIT_FAILURE);
      }
  }
    }
void Ssl::Load(){
    QString publ = QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pub";
    pub = e.load(publ);
    QString priv = QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pri";
    pri = e.load(priv);
}
QByteArray Ssl::Pri(){
    return pri;
}
QByteArray Ssl::Pub(){
    return pub;
}
void Ssl::FromClient(QByteArray key){
    cpub=key;
}
QByteArray Ssl::Encrypt(QByteArray data){
data = e.encode(data,Pri());
data = e.encode(data,cpub);
return data;
}
QByteArray Ssl::Decrypt(QByteArray data){
data = e.decode(data,cpub);
data = e.decode(data,Pri());
return data;
}
