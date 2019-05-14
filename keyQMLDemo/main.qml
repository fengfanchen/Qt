import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("CSDN IT1995")

    Image {
        anchors.fill: parent
        id: bg
        source: "qrc:/img/bg.jpg"
    }

    Rect{

        id: keys
    }
}
