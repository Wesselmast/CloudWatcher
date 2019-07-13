import cloudwatching.backend 1.0
import "globals.js" as Global

import QtQuick 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    property int uiWidth: 175
    property int sliderHeight: 7
    property int sliderHandleSize: 16

    visible: true
    width: uiWidth + 50
    height: 8000
    color: "#292929"

    function randomizeProgramically() {
        Global.randomized = true
    }

    function randomize() {
        primaryRadius.value = Math.random()
        primarySpikeyness.value = Math.random()
        primaryCurvyness.value = Math.random()

        secondaryRadius.value = Math.random()
        secondarySpikeyness.value = Math.random()
        secondaryCurvyness.value = Math.random()

        negativeRadius.value = Math.random()
        negativeSpikeyness.value = Math.random()
        negativeCurvyness.value = Math.random()
    }

    Timer {
        id: timer
        running: true
        repeat: true
        interval: 1
        onTriggered: {
            if(Global.randomized) {
                randomize()
                Global.randomized = false
            }
        }
    }

    Image {
        id: sliderVlak
        source: "images/UI-Sliders-Vlak"
        sourceSize.width: root.width
        width: root.width
        height: 85
    }

    Image {
        id: primaryVlak
        y: sliderVlak.y + sliderVlak.height + 10
        source: "images/UI-Primary-Vlak"
        sourceSize.width: root.width
        width: root.width
        height: 250
    }

    Image {
        id: secondaryVlak
        y: primaryVlak.y + primaryVlak.height + 10
        source: "images/UI-Primary-Vlak"
        sourceSize.width: root.width
        width: root.width
        height: 250
    }

    Image {
        id: negativeVlak
        y: secondaryVlak.y + secondaryVlak.height + 10
        source: "images/UI-Primary-Vlak"
        sourceSize.width: root.width
        width: root.width
        height: 250
    }

    Image {
        y: negativeVlak.y + negativeVlak.height + 10
        source: "images/UI-Canvas-Vlak"
        sourceSize.width: root.width
        width: root.width
        height: 150
    }

    ColumnLayout {
        x: (root.width - uiWidth)/2

        spacing: 3

        Item {
            width: 1
            height: 5
        }

        //Sliders
        Label {
            color: "#c1c1c1"
            font.pointSize: 9.5
            font.family: "Montserrat ExtraBold"
            text: "SLIDERS"
        }

        Image {
            source: "images/UI-Divider"
            sourceSize.width: uiWidth
            width: uiWidth
        }

        Item {
            width: 1
            height: 5
        }

        Button {
            id: randomButton
            style: ButtonStyle {
                background: Image {
                    source: "images/UI-Sliders-Button1.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                }
                label: Text {
                    color: "#eeeeed"
                    font.pointSize: 8
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Montserrat SemiBold"
                    text: "randomize sliders"
                }
            }

            text:  "<font color='#fefefe'>Randomize</font>"
            onClicked: {
                randomize()
            }
        }

        Item {
            width: 1
            height: 35
        }

        //PRIMARY SHAPES
        Image {
            source: "images/UI-Primary-Icon.png"
            sourceSize.width: 60
        }

        Label {
            color: "#c1c1c1"
            font.pointSize: 9.5
            font.family: "Montserrat ExtraBold"
            text: "PRIMARY SHAPES"
        }

        Image {
            source: "images/UI-Divider"
            sourceSize.width: uiWidth
            width: uiWidth
        }

        Item {
            width: 1
            height: 5
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "radius"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-radius-1.png"
                sourceSize.width: 12
                y: 2
            }
            Slider {
                id: primaryRadius
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.primaryRadius = value
                }
            }
            Image {
                source: "images/UI-radius-2.png"
                sourceSize.width: 25
                y: -4
            }
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "complexity"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-complexity-1.png"
                sourceSize.width: 18
            }
            Slider {
                id: primarySpikeyness
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.primarySpikeyness = value
                }
            }
            Image {
                source: "images/UI-complexity-2.png"
                sourceSize.width: 22
                y: -1
            }
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "curvyness"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-curvyness-1.png"
                sourceSize.width: 16
                y: -2
            }
            Slider {
                id: primaryCurvyness
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.primaryCurvyness = value
                }
            }
            Image {
                source: "images/UI-curvyness-2.png"
                sourceSize.width: 16
                y: -4
            }
        }

        Item {
            width: 1
            height: 35
        }

        //SECONDARY SHAPES
        Image {
            source: "images/UI-Secondary-Icon.png"
            sourceSize.width: 60
        }

        Label {
            color: "#c1c1c1"
            font.pointSize: 9.5
            font.family: "Montserrat ExtraBold"
            text: "SECONDARY SHAPES"
        }

        Image {
            source: "images/UI-Divider"
            sourceSize.width: uiWidth
            width: uiWidth
        }

        Item {
            width: 1
            height: 5
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "radius"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-radius-1.png"
                sourceSize.width: 12
                y: 2
            }
            Slider {
                id: secondaryRadius
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.secondaryRadius = value
                }
            }
            Image {
                source: "images/UI-radius-2.png"
                sourceSize.width: 25
                y: -4
            }
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "complexity"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-complexity-1.png"
                sourceSize.width: 18
            }
            Slider {
                id: secondarySpikeyness
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.secondarySpikeyness = value
                }
            }
            Image {
                source: "images/UI-complexity-2.png"
                sourceSize.width: 22
                y: -1
            }
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "curvyness"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-curvyness-1.png"
                sourceSize.width: 16
                y: -2
            }
            Slider {
                id: secondaryCurvyness
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.secondaryCurvyness = value
                }
            }
            Image {
                source: "images/UI-curvyness-2.png"
                sourceSize.width: 16
                y: -4
            }
        }

        Item {
            width: 1
            height: 35
        }

        //NEGATIVE SHAPES
        Image {
            source: "images/UI-Negative-Icon.png"
            sourceSize.width: 55
        }

        Label {
            color: "#c1c1c1"
            font.pointSize: 9.5
            font.family: "Montserrat ExtraBold"
            text: "NEGATIVE SHAPES"
        }

        Image {
            source: "images/UI-Divider"
            sourceSize.width: uiWidth
            width: uiWidth
        }

        Item {
            width: 1
            height: 5
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "radius"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-radius-1.png"
                sourceSize.width: 12
                y: 2
            }
            Slider {
                id: negativeRadius
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.negativeRadius = value
                }
            }
            Image {
                source: "images/UI-radius-2.png"
                sourceSize.width: 25
                y: -4
            }
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "complexity"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-complexity-1.png"
                sourceSize.width: 18
            }
            Slider {
                id: negativeSpikeyness
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.negativeSpikeyness = value
                }
            }
            Image {
                source: "images/UI-complexity-2.png"
                sourceSize.width: 22
                y: -1
            }
        }
        Label {
            font.pointSize: 8
            color: "#eeeeed"
            font.family: "Montserrat Medium"
            text: "curvyness"
        }
        Row {
            spacing: 10
            Image {
                source: "images/UI-curvyness-1.png"
                sourceSize.width: 16
                y: -2
            }
            Slider {
                id: negativeCurvyness
                style: SliderStyle {
                    groove: Image {
                        source: "images/UI-Slider-Groove.png"
                        sourceSize.width: uiWidth - 45
                        width: uiWidth - 45
                        height: sliderHeight
                    }
                    handle: Image {
                        source: "images/UI-Slider-Handle.png"
                        sourceSize.width: sliderHandleSize
                        sourceSize.height: sliderHandleSize
                    }
                }
                value: Math.random()
                onValueChanged: {
                    BackEnd.negativeCurvyness = value
                }
            }
            Image {
                source: "images/UI-curvyness-2.png"
                sourceSize.width: 16
                y: -4
            }
        }

        Item {
            width: 1
            height: 35
        }

        //Canvas
        Label {
            color: "#c1c1c1"
            font.pointSize: 9.5
            font.family: "Montserrat ExtraBold"
            text: "CANVAS"
        }

        Image {
            source: "images/UI-Divider"
            sourceSize.width: uiWidth
            width: uiWidth
        }

        Item {
            width: 1
            height: 10
        }

        Button {
            style: ButtonStyle {
                background: Image {
                    source: "images/UI-Canvas-Button2.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                }
                label: Text {
                    color: "#eeeeed"
                    font.pointSize: 8
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    x: 18
                    font.family: "Montserrat ExtraBold"
                    text: "GENERATE SHAPE"
                }
            }
            onClicked: {
                BackEnd.generate()
            }
        }

        Item {
            width: 1
            height: 5
        }

        Button {
            style: ButtonStyle {
                background: Image {
                    source: "images/UI-Canvas-Button3.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                }
                label: Text {
                    color: "#eeeeed"
                    font.pointSize: 8
                    renderType: Text.NativeRendering
                    verticalAlignment: Text.AlignVCenter
                    x: 18
                    font.family: "Montserrat SemiBold"
                    text: "export shape as..."
                }
            }
            onClicked: {
                BackEnd.doExport()
            }
        }
    }
}
