#include "baseview.h"

BaseView::BaseView( int &argc, char **argv )
    :QGuiApplication ( argc, argv )
{
    m_BaseEngine = new QQmlApplicationEngine;
    m_BaseWindow = new QQuickWindow;
    m_BaseObject = new QObject;
    m_pBaseConnect = new baseConnect;

    initBase();
}

void BaseView::initBase() {

    m_BaseEngine->rootContext()->setContextProperty( "JANG", m_pBaseConnect );
    m_BaseEngine->load( QUrl( "qrc:/main.qml" ) );
    m_BaseObject = m_BaseEngine->rootObjects().value( 0 );
    m_BaseWindow = qobject_cast< QQuickWindow * >(m_BaseObject);

    m_BaseWindow->show();
}
