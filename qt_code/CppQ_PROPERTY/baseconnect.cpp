#include "baseconnect.h"

BaseConnect::BaseConnect()
{
    qmlRegisterType< BaseConnect >("JangQml", 1, 0, "BaseConnect");
}

BaseConnect::~BaseConnect() {

}

void BaseConnect::setWindow( QQuickWindow *Window ) {
    m_pMainView = Window;
}

void BaseConnect::connectPrint( QString word ) {
    qDebug() << word << endl;
}

void BaseConnect::connectQmlData( QString qmlData ) {
    this->setQmlData( qmlData );
}
QString BaseConnect::getQmlData() {

//    m_pCppData = "hello";
//    m_pCppData = sendString;
    qDebug() << "2.getQmlData: " << m_pCppData << endl;

    return m_pCppData;
}
void BaseConnect::setQmlData( QString &qmlData ) {

    m_pCppData = qmlData;
//    sendString = qmlData;

    qDebug() << "1.setQmlData: " << m_pCppData;

    /*getQmlData Function Call*/
    emit qmlDataChanged();
}
