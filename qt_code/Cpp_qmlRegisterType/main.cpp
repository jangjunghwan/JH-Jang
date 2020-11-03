#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "BaseConnect.h"

int main(int argc, char *argv[])
{

    QGuiApplication app( argc, argv );

    QQmlApplicationEngine engine;

    BaseConnect *baseEvent = new BaseConnect();

    engine.load( QUrl( QStringLiteral( "qrc:/main.qml" )));
    QObject *root = engine.rootObjects()[0];

//    viewEvent->setWindow( qobject_cast< QQuickWindow * >( root ));
    baseEvent->setWindow( qobject_cast< QQuickWindow * >( root ));
    if ( engine.rootObjects().isEmpty() ){
        return -1;
    }

    return app.exec();
}
