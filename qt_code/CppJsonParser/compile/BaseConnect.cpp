#include "BaseConnect.h"

BaseConnect::BaseConnect()
{
    m_pBaseJsonParser = new BaseJsonParser;
}

void BaseConnect::connectPrint( QString getString ) {
    qDebug() << "GetString: " << getString;
}

void BaseConnect::sendCode( QString getCode ) {
    QString resultMessage;

    m_pBaseJsonParser->isJsonFileSearch( getCode, resultMessage );

    m_pResultMessage = resultMessage;
}

QString BaseConnect::getFunMessage() {

    return m_pResultMessage;
}
