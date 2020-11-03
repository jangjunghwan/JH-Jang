import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: root

    property alias buttonText: basicButton.text

    signal clicked()
    signal released()
    signal pressed()

    Button {
        id: basicButton
        text: "Select Bnf File"

        onClicked: root.clicked()
        onReleased: root.released()
        onPressed: root.pressed()
        highlighted: true
    }
}
