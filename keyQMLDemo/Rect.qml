import QtQuick 2.0

Rectangle {

    id: rectangle

    width: 50
    height: 50

    color: "green"

    focus: true
    Keys.onLeftPressed: rectangle.x -= 8
    Keys.onRightPressed: rectangle.x += 8
    Keys.onUpPressed: rectangle.y -= 8
    Keys.onDownPressed: rectangle.y +=8

    Keys.onPressed: {

        console.debug("preessed")

        switch(event.key){

        case Qt.Key_PageUp:
            rectangle.scale += 0.2
            break
        case Qt.Key_PageDown:
            rectangle.scale -= 0.2
            break
        }
    }

}
