#include "pooler.h"
Pooler::Pooler()
{
QString s = QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.Rserver/work/";

if(!(QDir(s).exists())){
QDir(s).mkpath(s);
}
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
if(!db.open()){
 qDebug()<<"sheize";
 exit(1);
}
db.open();
QSqlQuery qsq;
if(qsq.exec("SELECT * FROM data where completation = 0")){
qDebug()<<"Yes, we did it.";
}else{
    qDebug()<<"Fuck off";
}
if (true) {

}
}
