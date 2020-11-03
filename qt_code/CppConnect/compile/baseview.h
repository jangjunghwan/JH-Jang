#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QObject>
#include <QQmlContext>

#include "baseconnect.h"

class BaseView: public QGuiApplication
{
public:
    BaseView( int &, char **);

    void initBase();

private:
    QQmlApplicationEngine *m_BaseEngine;
    QQuickWindow *m_BaseWindow;
    QObject *m_BaseObject;
    baseConnect *m_pBaseConnect;
};

#endif // BASEVIEW_H
