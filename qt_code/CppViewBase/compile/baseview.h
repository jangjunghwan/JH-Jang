#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QObject>

class BaseView: public QGuiApplication
{
public:
    BaseView( int &, char **);

    void initBase();

private:
    QQmlApplicationEngine *m_BaseEngine;
    QQuickWindow *m_BaseWindow;
    QObject *m_BaseObject;
};

#endif // BASEVIEW_H
