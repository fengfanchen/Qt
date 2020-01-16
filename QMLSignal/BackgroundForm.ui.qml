import QtQuick 2.4

Item {
    width: 400
    height: 400

    Rectangle {
        id: rectangle
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#f7fcfa"
            }

            GradientStop {
                position: 1
                color: "#30cce8"
            }
        }
        anchors.fill: parent
    }
}
