import QtQuick 2.5
import QtQuick.Window 2.2
import QtWebEngine 1.0

Window {
    width: 1024
    height: 750
    visible: true
    WebEngineView {

        anchors.fill: parent
        url: "http://192.1.101.118:8888"
    }
}
