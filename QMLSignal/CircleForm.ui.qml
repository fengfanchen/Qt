import QtQuick 2.4

Item {
    width: 200
    height: 200
    property alias buttonColor: button.color
    property alias displayText: display.text

    Rectangle {
        id: button
        color: "#f03131"
        radius: width * 0.5
        anchors.fill: parent

        Text {
            id: display
            x: 88
            y: 94
            color: "#fbfbfb"
            text: qsTr("Text")
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 28
        }
    }
}
