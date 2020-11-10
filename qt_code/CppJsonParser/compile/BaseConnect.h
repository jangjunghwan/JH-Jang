#ifndef BASECONNECT_H
#define BASECONNECT_H

#include <QObject>
#include <QDebug>
#include <QString>

#include "BaseJsonParser.h"

class BaseConnect: public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString getMessage READ getFunMessage );

public:
    BaseConnect();

    Q_INVOKABLE void connectPrint( QString );
    Q_INVOKABLE void sendCode( QString );

    QString getFunMessage();

private:
    BaseJsonParser *m_pBaseJsonParser;

    QString m_pResultMessage;

};

#endif // BASECONNECT_H
