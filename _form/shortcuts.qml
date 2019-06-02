import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    property int uiWidth: 175

    visible: true
    width: uiWidth + 50
    height: 8000
    color: "#292929"

    Image {
        id: shortcuts
        source: "images/UI-Sliders-Vlak"
        sourceSize.width: root.width
        width: root.width
        height: 85
    }

    Image {
        y: shortcuts.height - 1
        source: "images/UI-Primary-Vlak"
        sourceSize.width: root.width
        width: root.width
        height: 250
    }

    ColumnLayout {
        x: (root.width - uiWidth)/2
        spacing: 5

        Item {
            width: 1
            height: 5
        }

        Label {
            color: "#c1c1c1"
            font.pointSize: 9.5
            font.family: "Montserrat ExtraBold"
            text: "SHORTCUTS"
        }
        Image {
            source: "images/UI-Divider"
            sourceSize.width: uiWidth
            width: uiWidth
        }
        Item {
            width: 1
            height: 8
        }

        Label {
            font.pointSize: 8
            color: "#c1c1c1"
            font.family: "Montserrat Medium"
            text: "[ , ] : rotate shape 90° CW"
        }

        Label {
            font.pointSize: 8
            color: "#c1c1c1"
            font.family: "Montserrat Medium"
            text: "[ . ] : rotate shape 90° CCW"
        }

        Label {
            font.pointSize: 8
            color: "#c1c1c1"
            font.family: "Montserrat Medium"
            text: "[ < ] : flip shape horizontal"
        }

        Label {
            font.pointSize: 8
            color: "#c1c1c1"
            font.family: "Montserrat Medium"
            text: "[ > ] : flip shape vertical"
        }

        Label {
            font.pointSize: 8
            color: "#c1c1c1"
            font.family: "Montserrat Medium"
            text: "[ space ] : generate shape"
        }

        Label {
            font.pointSize: 8
            color: "#c1c1c1"
            font.family: "Montserrat Medium"
            text: "[ r ] : randomize sliders"
        }

        Label {
            font.pointSize: 8
            color: "#c1c1c1"
            font.family: "Montserrat Medium"
            text: "[ ctrl + s ] : quick export"
        }
    }
}
