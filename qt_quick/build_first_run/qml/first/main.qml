import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.rightMargin: 142
        anchors.bottomMargin: 167
        anchors.leftMargin: 142
        anchors.topMargin: 164
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    TextInput {
        id: textInput1
        x: 46
        y: 85
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }
}
