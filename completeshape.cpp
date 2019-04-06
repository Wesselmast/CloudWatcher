#include "completeshape.h"

CompleteShape::CompleteShape() {

}

QRectF CompleteShape::boundingRect() const {
    return QRectF(-150, -150, 300, 300);
}

void CompleteShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    pen->setJoinStyle(Qt::RoundJoin);
    QPainterPath path;
    if(canGenerate) {
        poly = new QPolygon(generatePolygon(xPos, yPos, radius, wonkyness, spikeyness, numVerts));
        firstTime = false;
        canGenerate = false;
    }
    if(firstTime) return;
    path.addPolygon(*poly);
    painter->setPen(*pen);
    painter->fillPath(path, *brush);
    painter->drawPolygon(*poly);
}

void GeneratedShape::generate(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts) {
    canGenerate = true;
    this->radius = radius;
    this->wonkyness = wonkyness;
    this->spikeyness = spikeyness;
    this->numVerts = numVerts;
    this->xPos = xPos;
    this->yPos = yPos;
    update();
}
