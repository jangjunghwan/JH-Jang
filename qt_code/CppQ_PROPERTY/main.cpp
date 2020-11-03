#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "baseconnect.h"

int main(int argc, char *argv[])
{

    QGuiApplication app( argc, argv );

    QQmlApplicationEngine engine;

    BaseConnect *baseEvent = new BaseConnect();

    engine.rootContext()->setContextProperty( "JJH", baseEvent );
    engine.load( QUrl( QStringLiteral( "qrc:/main.qml" )));
    QObject *root = engine.rootObjects()[0];

    baseEvent->setWindow( qobject_cast< QQuickWindow * >( root ));

    if ( engine.rootObjects().isEmpty() ){
        return -1;
    }

    return app.exec();
}
