#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "baseview.h"

int main(int argc, char *argv[])
{
    BaseView app( argc, argv );

    return app.exec();
}
