import QtQuick 2.9
import QtQuick.Window 2.2

import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("CSDN IT1995")

    Row{

        anchors.centerIn: parent
        spacing: 20


        Button{

            id: pushButton1

            style: ButtonStyle{

                background: BorderImage {

                    id: btn1
                    source: control.pressed ? "qrc:/img/press.png" : "qrc:/img/normal.png"
                    width: 128
                    height: 128
                    antialiasing: true
                    border.left: 5
                    border.top: 5
                    border.right: 5
                    border.bottom: 5
                }
            }

            onClicked: {

                console.debug("pushButton1 pressed!")
            }
        }

        Button{

            id: pushButton2
            style: buttonStyle1
            text: "Hello Word"
            onClicked: {

                console.debug("pushButton2 pressed!");
            }
        }

        Button{

            id: pushButton3
            style: buttonStyle2
            onClicked: {

                console.debug("pushButton3 pressed!");
            }
        }

    }

    Component {

        id: buttonStyle1
        ButtonStyle{

            background: Rectangle{

                implicitHeight: 128
                implicitWidth: 128
                color: control.pressed ? "darkGray" : control.activeFocus ? "#cdd" : "#ccc"
                antialiasing: true
                border.color: "gray"
                radius: height/2
            }
        }
    }

    Component {

        id: buttonStyle2
        ButtonStyle{


            background: Rectangle{

                implicitHeight: 128
                implicitWidth: 128
                color: control.pressed ? "darkGray" : control.activeFocus ? "#cdd" : "#ccc"
                antialiasing: true
                border.color: "gray"
                radius: height/2

                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 1
                    color: "transparent"
                    antialiasing: true
                    visible: !control.pressed
                    border.color: "#aaffffff"
                    radius: height/2
                }
            }
        }
    }
}
