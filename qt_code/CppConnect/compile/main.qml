import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property bool buttonBool: true

    ButtonControl {
        width: 100
        height: 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        buttonText: buttonBool ? "Select Bnf File" : "Click Bnf File"
        onClicked: {
            root.buttonBool ? JANG.isQmltoCpp("Hello World") : JANG.isQmltoCpp("START")
            root.buttonBool = root.buttonBool ? false : true

            baseText.text = JANG.getValue
        }
    }
    Text {
        id: baseText
        anchors.horizontalCenter: parent.horizontalCenter
        y: 180
        text: "START"
    }
}
