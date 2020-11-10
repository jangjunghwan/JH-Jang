import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Window")

    Button {
        id: baseButton

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Hi"
        onClicked: {
            JJH.connectPrint("Hello")
            baseTextField.focus = true
            baseMessage.text = "Hello User~"
        }
    }

    TextField {
        id: baseTextField
        anchors.horizontalCenter: parent.horizontalCenter
        focus: true
        placeholderText: "Please enter the code."

        Keys.onEnterPressed: {
            if( event.key === Qt.Key_Enter ) {
                //JJH.connectPrint( baseTextField.text )
                JJH.sendCode( baseTextField.text )
                baseTextField.text = ""
                baseMessage.text = JJH.getMessage
            }
            else if (event.key === Qt.Key_Return ) {
                //JJH.connectPrint( baseTextField.text )
                JJH.sendCode( baseTextField.text )
                baseTextField.text = ""
                baseMessage.text = JJH.getMessage
            }
        }
    }
    Text {
        id: baseText
        anchors.horizontalCenter: parent.horizontalCenter
        y: 50
        text: "<-Result->"
    }
    Text {
        id: baseMessage
        anchors.horizontalCenter: parent.horizontalCenter
        y: 70
    }
}
