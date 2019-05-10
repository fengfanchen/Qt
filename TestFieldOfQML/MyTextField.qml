import QtQuick 2.0
import QtQuick.Controls.Styles 1.2
import QtQuick.Controls 1.2

Item {

    Image{

         width: parent.width
         source: "qrc:/img/textfield_2.png"

         TextField{

             anchors {

                left: parent.left
                leftMargin: 45
                top: parent.top
                topMargin: 20
             }

             width: parent.width - 90

             font.pointSize: 20

             style: TextFieldStyle{

                 background: BorderImage {

                 }


             }
         }
    }

}
