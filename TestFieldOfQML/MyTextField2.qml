import QtQuick 2.0
import QtQuick.Controls.Styles 1.2
import QtQuick.Controls 1.2

Item {

    Image{

        source: "qrc:/img/textfield_3.png"
        width: 420
        height: 300

        TextField{

            id: textField
            anchors {

               left: parent.left
               leftMargin: 40
               top: parent.top
               topMargin: 155
            }

            rotation: -8
            width: parent.width - 170
            font.pointSize: 32

            smooth: true
            antialiasing: true

            style: TextFieldStyle{

                background: BorderImage {

                }


            }
        }

    }

}
