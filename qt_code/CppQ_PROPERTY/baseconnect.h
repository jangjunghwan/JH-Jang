#ifndef BASECONNECT_H
#define BASECONNECT_H

#include <QQmlContext>
#include <QQuickView>
#include <QObject>
#include <QDebug>
#include <QString>

class BaseConnect: public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString getValue READ getQmlData WRITE setQmlData NOTIFY qmlDataChanged )

public:
    BaseConnect();
    ~BaseConnect();

    void setWindow( QQuickWindow *Window );

    /*Base Connect Function*/
    Q_INVOKABLE void connectPrint( QString );
    Q_INVOKABLE void connectQmlData( QString );
    QString getQmlData();
    void setQmlData( QString & );

private:
    QQuickWindow *m_pMainView;
    QQuickView *m_pQQuickView;

    QString m_pCppData;

signals:
    void qmlDataChanged();

};

#endif // BASECONNECT_H
