import QtQuick 2.0

Item {
    id: root

    ListModel {
        id: fruitModel

        ListElement {
            name: "Apple"
            cost: 2.45
        }
        ListElement {
            name: "Orange"
            cost: 3.25
        }
        ListElement {
            name: "Banana"
            cost: 1.95
        }
    }

    ListView {
        anchors.fill: parent
        model: fruitModel
        delegate: Row {
            Text { text: "Fruit: " + name }
            Text { text: "Cost: $" + cost }
        }
    }

    MouseArea {
        anchors.fill: parent
//        onClicked: fruitModel.append({"cost": 5.95, "name":"Pizza"})
        onClicked: fruitModel.set(0, {"cost": 1.11, "name":"pizza"})
    }

}
