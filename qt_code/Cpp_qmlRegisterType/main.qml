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

    Text {
        id: testText
        width: 100
        height: 100
        x: 220
        y: 200
        text: "hello"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                baseConnect.connectPrint( "hi" )
            }
        }

    }
}
