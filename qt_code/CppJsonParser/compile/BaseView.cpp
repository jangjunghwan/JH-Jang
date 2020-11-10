#include "BaseView.h"

BaseView::BaseView( int &argc, char **argv )
    :QGuiApplication ( argc, argv )
{
    m_pQQmlApplicationEngine = new QQmlApplicationEngine;
    m_pQQuickWindow = new QQuickWindow;
    m_pBaseConnect = new BaseConnect;
    m_pQObject = new QObject;

    initBase();
}

void BaseView::initBase() {
    m_pQQmlApplicationEngine->rootContext()->setContextProperty( "JJH", m_pBaseConnect );
    m_pQQmlApplicationEngine->load( QUrl( "qrc:/main.qml" ));
    m_pQObject = m_pQQmlApplicationEngine->rootObjects().value( 0 );
    m_pQQuickWindow = qobject_cast< QQuickWindow * >( m_pQObject );

    m_pQQuickWindow->show();
}
