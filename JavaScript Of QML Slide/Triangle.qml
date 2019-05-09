import QtQuick 2.5

Canvas {

    id: triangle
    property color triangleColor: "blue"
    width: parent.width - parent.width / 3
    height: parent.height -  parent.height / 3
    contextType: "2d"

    onPaint: {

        context.lineWidth = 0
        context.strokeStyle = "#00000000"
        context.fillStyle = triangleColor
        context.beginPath();
        context.moveTo(0, 0)
        context.lineTo(0, triangle.height);
        context.lineTo(triangle.width, triangle.height/2);
        context.closePath();
        context.fill()
        context.stroke();
    }
}
