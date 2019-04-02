#include "completeshape.h"

CompleteShape::CompleteShape() {
    setFlag(ItemIsMovable);
    shapes = new GeneratedShape[amtOfShapes];
    spikeyness = 0;
    wonkyness = 0;
    complexity = 5;
}

QRectF CompleteShape::boundingRect() const {
    return QRectF(-125, -125, 250, 250);
}

void CompleteShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    for(int i = 0; i < amtOfShapes; ++i) {
        painter->drawPolygon(shapes[i]);
    }
}

void CompleteShape::generate() {
    for(int i = 0; i < amtOfShapes; ++i) {
        shapes[i].generate((rand() % 150) - 75, (rand() % 200) - 100, 55, wonkyness, spikeyness, complexity);
        shapes[i].setRotation(rand() % 360);
        qDebug() << "pe";
    }
}

void CompleteShape::changeLineThickness(int value) {
    for(int i = 0; i < amtOfShapes; ++i) {
        shapes[i].pen->setWidth(value);
        shapes[i].update();
    }
}

CompleteShape::~CompleteShape() {

}
