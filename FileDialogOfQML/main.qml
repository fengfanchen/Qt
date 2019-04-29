import QtQuick 2.5
import QtQuick.Dialogs 1.0
import QtQuick.Window 2.1

Window {

    FileDialog {

        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        selectFolder: true
        onAccepted: {

            console.log("You chose: " + fileDialog.fileUrls)
            Qt.quit()
        }

        onRejected: {

            console.log("Canceled")
            Qt.quit()
        }
        //Component.onCompleted: visible = true
    }

    id: root
    visible: true
    width: 1024
    height: 768
    color: "black"

    Component.onCompleted: fileDialog.open()
}
