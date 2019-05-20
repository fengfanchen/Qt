import QtQuick 2.0
import QtQuick.Particles 2.0

Item {

    ParticleSystem{

        id: sys
    }

    ImageParticle{

        system: sys
        source: "qrc:/img/star.png"
    }

    Emitter{

        id: startField
        system: sys

        emitRate: 80
        lifeSpan: 2500
        lifeSpanVariation: 4000

        width: window.width
        height: window.height

        //acceleration: PointDirection { xVariation: 200; yVariation: 200; }

        size: 0
        endSize: 48
        sizeVariation: 10
    }

}
