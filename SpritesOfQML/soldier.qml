import QtQuick 2.0

Item {

        Image {
            x:200;
            id: image1;
            source: "qrc:/img/soldier.png";
            visible: false
        }

        SpriteSequence {
            id: sequence;
            width: 50;
            height: 100;
            interpolate: false;
            running: false;
            sprites: [
                Sprite {
                    name: "down";
                    source: image1.source;
                    frameCount: 4;
                    frameWidth: image1.width/4;
                    frameHeight: image1.height/4;
                    frameRate: 10;
                },
                Sprite {
                    name: "left";
                    source: image1.source;
                    frameCount: 4;
                    frameY: image1.height/4;
                    frameWidth: image1.width/4;
                    frameHeight: image1.height/4;
                    frameRate: 10;
                },
                Sprite {
                    name: "right";
                    source: image1.source;
                    frameCount: 4;
                    frameY: image1.height/4*2;
                    frameWidth: image1.width/4;
                    frameHeight: image1.height/4;
                    frameRate: 10;
                },
                Sprite {
                    name: "up";
                    source: image1.source;
                    frameCount: 4;
                    frameY: image1.height/4*3;
                    frameWidth: image1.width/4;
                    frameHeight: image1.height/4;
                    frameRate: 10;
                }
            ]
        }
        focus: true;
        Keys.onPressed: {
            switch(event.key)
            {
            case Qt.Key_Up:
                sequence.y -= 5;
                sequence.jumpTo("up");
                sequence.running = true;
                break;
            case Qt.Key_Down:
                sequence.y += 5;
                sequence.jumpTo("down");
                sequence.running = true;
                break;
            case Qt.Key_Left:
                sequence.x -= 5;
                sequence.jumpTo("left");
                sequence.running = true;
                break;
            case Qt.Key_Right:
                sequence.x += 5;
                sequence.jumpTo("right");
                sequence.running = true;
                break;
            default:
                ;
            }
        }
        Keys.onReleased: {
            sequence.running = false;
        }

}
