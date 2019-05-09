import QtQuick 2.9
import QtQuick.Window 2.2
import "Test.js" as Test

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{

        id: rectangle
        width: 100
        height: 100
        anchors.left: parent.left
        anchors.leftMargin: - width / 2
        color: "gray"
        radius: width

        Triangle {
            anchors.centerIn: parent
        }


        //定时器
        Timer {

            id: showTimer
            interval: 10
            repeat: true
            triggeredOnStart: true

            onTriggered: {

                console.debug(rectangle.anchors.leftMargin)
                if(rectangle.anchors.leftMargin >= 0){

                    console.debug("show over")
                    showTimer.stop()

                }
                else{

                    Test.showPic(rectangle)
                }
            }
        }

        Timer {

            id : hideTimer
            interval: 10
            repeat: true
            triggeredOnStart: true
            onTriggered: {

                console.debug(rectangle.anchors.leftMargin)
                if(rectangle.anchors.leftMargin < -50){

                    console.debug("hide over")
                    hideTimer.stop()

                }
                else{

                    Test.hidePic(rectangle)
                }
            }
        }

        MouseArea {

            width: parent.width
            height: parent.height

            onEntered: {
                if(rectangle.anchors.leftMargin === 0){

                    hideTimer.start()
                }
                else{

                    showTimer.start()
                }
            }
        }
    }

}
