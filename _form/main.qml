import cloudwatching.backend 1.0

import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

Rectangle {
    property int uiWidth: 200
    property int sliderHeight: 7
    property int sliderHandleSize: 16

    visible: true
    width: uiWidth
    height: 8000
    color: "#292929"

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
    focus: true
    Keys.onPressed: { if(event.key === Qt.Key_R) randomize() }

    ColumnLayout {
        UIForm {
        }

        spacing: 8

        //PRIMARY SHAPES
        Label {
            color: "white"
            font.pointSize: 10
            font.bold: true
            font.family: "Verdana"
            text: "Primary Shapes"
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Radius"
        }
        Slider {
            id: primaryRadius
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.primaryRadius = value
            }
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Complexity"
        }
        Slider {
            id: primarySpikeyness
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.primarySpikeyness = value
            }
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Curvyness"
        }
        Slider {
            id: primaryCurvyness
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.primaryCurvyness = value
            }
        }

        Item {
            width: 1
            height: 20
        }

        //SECONDARY SHAPES
        Label {
            color: "white"
            font.pointSize: 10
            font.bold: true
            font.family: "Verdana"
            text: "Secondary Shapes"
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Radius"
        }
        Slider {
            id: secondaryRadius
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.secondaryRadius = value
            }
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Complexity"
        }
        Slider {
            id: secondarySpikeyness
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.secondarySpikeyness = value
            }
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Curvyness"
        }
        Slider {
            id: secondaryCurvyness
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.secondaryCurvyness = value
            }
        }

        Item {
            width: 1
            height: 20
        }

        //NEGATIVE SHAPES
        Label {
            color: "white"
            font.pointSize: 10
            font.bold: true
            font.family: "Verdana"
            text: "Negative Shapes"
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Radius"
        }
        Slider {
            id: negativeRadius
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.negativeRadius = value
            }
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Complexity"
        }
        Slider {
            id: negativeSpikeyness
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.negativeSpikeyness = value
            }
        }
        Label {
            color: "white"
            font.family: "Roboto Light"
            text: "Curvyness"
        }
        Slider {
            id: negativeCurvyness
            style: SliderStyle {
                groove: Image {
                    source: "PV-Slider1-Test.png"
                    sourceSize.width: uiWidth
                    width: uiWidth;
                    height: sliderHeight;
                }
                handle: Image {
                    source: "PV-Slider2-Test.png"
                    sourceSize.width: sliderHandleSize;
                    sourceSize.height: sliderHandleSize;
                }
            }
            value: .5
            onValueChanged: {
                BackEnd.negativeCurvyness = value
            }
        }

        Item {
            width: 1
            height: 20
        }

        Button {
            style: ButtonStyle {
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 25
                    color: "#019bd8"
                    radius: 4
                }
            }
            text:  "<font color='#fefefe'>Randomize</font>"
            onClicked: {
                randomize()
            }
        }

        Button {
            style: ButtonStyle {
                background: Rectangle {
                    implicitWidth: uiWidth
                    implicitHeight: 25
                    color: "#019bd8"
                    radius: 4
                }
            }
            text:  "<font color='#fefefe'>Generate</font>"
            onClicked: {
                BackEnd.generate()
            }
        }
    }
}
