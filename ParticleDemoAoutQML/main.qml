import QtQuick 2.9
import QtQuick.Window 2.2

Window {

    id: window
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")

    Image{

        id: image
        source: "qrc:/img/bg.jpg"
        transformOrigin: Item.Center
        anchors.centerIn: parent

        NumberAnimation on rotation {

            from: 0
            to: 360
            duration: 20000
            loops: Animation.Infinite
        }


    }

    MyParticle{

        id: myParticle
    }
}
