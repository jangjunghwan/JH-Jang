#ifndef BASEVEIW_H
#define BASEVEIW_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QObject>
#include <QQmlContext>

#include "BaseConnect.h"

class BaseView: public QGuiApplication
{
public:
    BaseView( int &, char ** );

    void initBase();

private:
    QQmlApplicationEngine *m_pQQmlApplicationEngine;
    QQuickWindow *m_pQQuickWindow;
    QObject *m_pQObject;
    QQmlContext *m_pQQmlContext;

    BaseConnect *m_pBaseConnect;

};

#endif // BASEVEIW_H
