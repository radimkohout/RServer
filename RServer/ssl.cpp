#include "ssl.h"
Ssl::Ssl()
{
if(!QFile::exists(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pri")||!QFile::exists(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/key.pub")){
    GenKey();
}
}
void Ssl::GenKey(){

    }
