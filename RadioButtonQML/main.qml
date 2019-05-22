import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row{

        anchors.centerIn: parent

        ColumnLayout{

            RadioButton{
                checked: true
                text: "单选一"
            }

            RadioButton{

                checked: false
                text: "chose 1"
            }

            RadioButton{

                text: "chose 2"
            }
        }

        Column{

            id: column

            RadioButton{
                checked: true
                text: "one"
            }

            RadioButton{
                text: "two"
            }

            RadioButton{
                text: "three"
            }
        }

        ButtonGroup { id: radioGroup }

        Column {
            Label {
                text: qsTr("Radio:")
            }

            RadioButton {
                checked: true
                text: qsTr("DAB")
                ButtonGroup.group: radioGroup
            }

            RadioButton {
                text: qsTr("FM")
                ButtonGroup.group: radioGroup
            }

            RadioButton {
                text: qsTr("AM")
                ButtonGroup.group: radioGroup
            }
        }

    }

    Rectangle{

        RadioButton{
            text: "value1"
            y:0
        }

        RadioButton{
            text: "value2"
            y:20
        }

        RadioButton{
            text: "value3"
            y:40
        }
    }
}
