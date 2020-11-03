#ifndef BASECONNECT_H
#define BASECONNECT_H

#include <QQuickView>
#include <QObject>
#include <QDebug>

class BaseConnect: public QObject
{
    Q_OBJECT
public:
    BaseConnect();
    ~BaseConnect();

    void setWindow( QQuickWindow *Window );

    Q_INVOKABLE void connectPrint( QString );

private:
    QQuickWindow *m_pMainView;

};

#endif // BASECONNECT_H
