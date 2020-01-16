import QtQuick 2.4

BackgroundForm {

    property Circle target: null
    focus: true

    Keys.onPressed: {

        if(event.key == Qt.Key_Plus) target.width = target.width + 10
        if(event.key == Qt.key_Minus) target.width = target.width - 10
    }
}
