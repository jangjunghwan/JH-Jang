#include "baseconnect.h"

baseConnect::baseConnect()
{
    connect( this, SIGNAL( isSignals( QString ) ), this, SLOT(isSolts( QString )) );
}

void baseConnect::isQmltoCpp( QString result ) {

    qDebug() << result;
    this->setQmlData( result );
}

QString baseConnect::getQmlData() {

    return m_pSendValue;
}

void baseConnect::setQmlData( QString &result ) {

    m_pSendValue = result;
    this->isSignals( result );

    emit qmlDataChanged();
}

void baseConnect::isSolts( QString result ) {
    qDebug() << "Start Slot: " << result;
}
