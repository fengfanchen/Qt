import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sprite Demo")

    Image {
        id: bg
        source: "qrc:/img/bg.jpeg"
        fillMode: Image.Pad
    }

    Soldier{

        id : soldier
    }
}
