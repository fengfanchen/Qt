import QtQuick 2.5
import QtQuick.Window 2.2

Window {

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "black"

    Image{

        id: loveImg
        source: "qrc:/img/love_PNG89.png"
        anchors.centerIn: parent

//        SequentialAnimation{

//            running: true
//            loops: Animation.Infinite
//            ScaleAnimator{

//                target: loveImg
//                from: 0.2
//                to: 1
//                duration: 400
//            }

//            ScaleAnimator{

//                target: loveImg
//                from: 1
//                to: 0.2
//                duration: 400
//            }
//        }

        transform: Scale{

            id: loveTransform
            property real scaleValue: 1
            origin.x: loveImg.width / 2
            origin.y: loveImg.height / 2
            xScale: scaleValue
            yScale: scaleValue
        }

        SequentialAnimation{

            running: true
            loops: Animation.Infinite
            PropertyAnimation{

                target: loveTransform
                properties: "scaleValue"
                from: 0.5
                to: 1
                duration: 400
            }
            PropertyAnimation{

                target: loveTransform
                properties: "scaleValue"
                from: 1
                to: 0.5
                duration: 400
            }
        }
    }
}
