#ifndef POOLER_H
#define POOLER_H
#include <QString>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
class Pooler
{
public:
    Pooler();
    QDir d;
    QByteArray getData(qint32 type, qint32 count);
    void receiveData();
};

#endif // POOLER_H
