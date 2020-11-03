*Q_PROPERTY 호출 방식*
```
    Q_PROPERTY( QString getValue READ getQmlData WRITE setQmlData NOTIFY qmlDataChanged )
```

**1.SetContextProperty System**
```
/*cpp Code(main.cpp)*/
QQmlApplicationEngine engine;
BaseConnect baseEvent;
engine.rootContext()->setContextProperty( "JJH", &baseEvent );
```

```
/*QML Code(main.qml)*/
Text {
        id: testText01
        width: 100
        height: 100
        x: 220
        y: 200
        text: "Test01 Hi"
        MouseArea {
            anchors.fill: parent

            onClicked: {
                JJH.connectQmlData( "Hello World01" )
                testText01.text = JJH.getValue
            }
        }
    }
```

setcontextProperty로 지정한 이름으로 호출 하는 방식.

**2.QmlRegisterType System**
```
/*cpp Code(baseconnect.cpp)*/
BaseConnect::BaseConnect()
{
    qmlRegisterType< BaseConnect >("JangQml", 1, 0, "BaseConnect");
}
```

```
/*QML Code(main.qml)*/
BaseConnect {
    id: baseConnect
}

...
...

Text {
        id: testText02
        width: 100
        height: 100
        x: 400
        y: 200
        text: "Test02 Hi"
        MouseArea {
            anchors.fill: parent

            onClicked: {
                baseConnect.connectQmlData( "Hello World02" )
                testText02.text = baseConnect.getValue
            }
        }
    }
```

qmlRegisterType으로 import명을 지정한 후 호출 하는 방식.

