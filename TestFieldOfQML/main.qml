import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Particles 2.0

Window {

    id: windows
    visible: true
    width: 1000
    height: 850
    title: qsTr("CSDN IT1995")

    property int columnFactor: 2


    Column{

        id: column
        spacing: 20
        anchors.centerIn: parent


        TextField {

            implicitWidth: windows.width / columnFactor
        }

        TextField {

            style: TextFieldStyle{

                background: BorderImage {
                    id: textFieldBorderImage
                    source: "qrc:/img/textfield_1.png"
                    width: windows.width / columnFactor; height: 100
                    border.left: 5; border.top: 5
                    border.right: 5; border.bottom: 5
                }

            }
            implicitWidth: windows.width / columnFactor
        }

        TextField {

            id: textField3
            style: textFieldStyle
            implicitWidth: windows.width / columnFactor
        }


        MyTextField {

            id: mytextField1
            anchors.top: textField3.bottom
            anchors.topMargin: 20
            width: textField3.width
        }

        MyTextField2{

            id: mytextField2
            anchors.top: mytextField1.bottom
            anchors.topMargin: 60
        }

    }

    Component {

        id: textFieldStyle
        TextFieldStyle {

            background: Rectangle {

                implicitWidth: windows.width / columnFactor
                color: "#f0f0f0"
                antialiasing: true
                border.color: "gray"
                radius: height/2

                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 1
                    color: "transparent"
                    antialiasing: true
                    border.color: "#aaffffff"
                    radius: height/2
                }
            }
        }
    }
}
