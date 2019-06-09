import QtQuick 2.0

Rectangle {
    visible: true
    width: image.width
    height: 8000
    color: "#292929"

    Image {
        id: image
        source: "images/UI-Shortcuts.png"
        width: 225
        fillMode: Image.PreserveAspectFit
    }
}
