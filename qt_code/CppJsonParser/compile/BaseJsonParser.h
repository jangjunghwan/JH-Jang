#ifndef BASEJSONPARSER_H
#define BASEJSONPARSER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QString>
#include <QDebug>
#include <QFile>

class BaseJsonParser
{
public:
    BaseJsonParser();

    QJsonObject jsonObj;

    void isJsonFileSearch( QString, QString & );
};

#endif // BASEJSONPARSER_H
