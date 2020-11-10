#include "BaseJsonParser.h"

BaseJsonParser::BaseJsonParser()
{

}

void BaseJsonParser::isJsonFileSearch( QString getCode, QString &resultMessage ) {
    QFile jsonFile(QStringLiteral( "../CodeControl.json" ));

    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed jsonFile Open";

        return;
    }

    QByteArray jsonData = jsonFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(jsonData));

    jsonObj = loadDoc.object();

    QString code = jsonObj[getCode].toString();

    resultMessage = code;
}
