import QtQuick 2.9
import QtQuick.Window 2.2
import JangQml 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BaseConnect {
        id: baseConnect
    }

/*SetContextProperty System*/
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

/*QmlRegisterType System*/
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
}
