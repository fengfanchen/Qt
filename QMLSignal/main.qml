import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Background {
        id: background
        clip: false
        visible: true
        anchors.fill: parent

        target: sender

        Receiver {
            id: receiver
            y: 148
            displayText: "Receiver"
            buttonColor: "#3170f0"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 50
            width: sender.width
        }

        Sender {
            id: sender
            x: 320
            y: 148
            width: 200
            height: 200
            displayText: "Send"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 50
            target: receiver
        }
    }
}

/*##^##
Designer {
    D{i:2;anchors_x:50}D{i:1;anchors_x:148;anchors_y:56}
}
##^##*/
