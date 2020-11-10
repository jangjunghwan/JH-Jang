#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "BaseView.h"

int main(int argc, char *argv[])
{
    BaseView app( argc, argv );

    return app.exec();
}
