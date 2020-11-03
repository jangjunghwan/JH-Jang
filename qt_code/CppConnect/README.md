*connect 호출 방식*

```
/*Cpp Code(baseconnect.cpp)*/
connect( this, SIGNAL( isSignals( QString ) ), this, SLOT(isSolts( QString )) );
```

**SIGNAL:** _특정 부분에 사용하여 SLOT을 호출 하는 함수, 함수안 매개변수를 SLOT이 받아 사용 가능._
```
/*Cpp Code(baseconnect.h)*/
public slots:
    void isSolts( QString );
```

**SLOT:** _SIGNAL사용시에 호출되는 함수, 기능 작업 할 수 있는 함수._
```
/*Cpp Code(baseconnect.h)*/
signals:
    void isSignals( QString );
```
```
/*Cpp Code(baseconnect.cpp)*/
void baseConnect::isSolts( QString result ) {
    qDebug() << "Start Slot: " << result;
}
```

