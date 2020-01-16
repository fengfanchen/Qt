import QtQuick 2.0

Circle {

    id: sendButton

    property int counter: 0
    property Receiver target: null

    signal send(string value)
    onTargetChanged: send.connect(target.receive)

    MouseArea{

        anchors.fill: parent

        onClicked: {

            counter++
            parent.send(counter)
        }

        onPressed: parent.buttonColor = "green"
        onReleased: parent.buttonColor = "blue"
    }
}
