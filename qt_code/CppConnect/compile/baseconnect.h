#ifndef BASECONNECT_H
#define BASECONNECT_H

#include <QObject>
#include <QDebug>

class baseConnect: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString getValue READ getQmlData WRITE setQmlData NOTIFY qmlDataChanged)
public:
    baseConnect();

    Q_INVOKABLE void isQmltoCpp( QString );

    QString getQmlData();
    void setQmlData( QString & );

private:
    QString m_pSendValue;

signals:
    void qmlDataChanged();
    void isSignals( QString );

public slots:
    void isSolts( QString );

};

#endif // BASECONNECT_H
