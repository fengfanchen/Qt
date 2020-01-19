import QtQuick 2.6
import QtQuick.Window 2.14
import QtQuick.Controls 2.2
import cn.it1995.bakend 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BackEnd{

        id: backend
    }

    TextField{

        text: backend.userName
        placeholderText: "user name"
        anchors.centerIn: parent
        onTextChanged: backend.userName = text
    }

}
