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
    qDebug() << word;
}

void BaseConnect::connectQmlData( QString qmlData ) {
    this->setQmlData( qmlData );
}
QString BaseConnect::getQmlData() {
    qDebug() << "getQmlData: " << m_pCppData;
    return this->m_pCppData;
}
void BaseConnect::setQmlData( QString &qmlData ) {
    qDebug() << "setQmlData_qmlData: " << qmlData;
    this->m_pCppData = qmlData;
    qDebug() << "setQmlData_m_pCppData: " << m_pCppData;

    /*getQmlData Function Call*/
    emit qmlDataChanged();
}
