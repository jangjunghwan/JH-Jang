#include "BaseConnect.h"

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
