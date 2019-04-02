#include "generatedshape.h"
#include <QDebug>

static bool firstTime = false;

GeneratedShape::GeneratedShape() {
    canGenerate = false;
    pen = new QPen(Qt::black);
    brush = new QBrush(Qt::black);
}

QRectF GeneratedShape::boundingRect() const {
    return QRectF(-150, -150, 300, 300);
}

void GeneratedShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    pen->setJoinStyle(Qt::RoundJoin);
    QPainterPath path;
    if(canGenerate) {
        poly = new QPolygon(generatePolygon(xPos, yPos, radius, wonkyness, spikeyness, numVerts));
        firstTime = true;
        canGenerate = false;
    }
    if(firstTime) {
        path.addPolygon(*poly);
        painter->setPen(*pen);
        painter->fillPath(path, *brush);
        painter->drawPolygon(*poly);
    }
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

QPolygon GeneratedShape::generatePolygon(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts) {
    wonkyness = clip(wonkyness, 0, 1) * 2 * M_PI / numVerts;
    spikeyness = clip(spikeyness, 0, 1) * radius;

    QList<double> angleSteps;
    double lower = (2 * M_PI / numVerts) - wonkyness;
    double upper = (2 * M_PI / numVerts) + wonkyness;
    double sum = 0;
    for(int i = 0; i < numVerts; ++i) {
        double temp = randomDouble(lower, upper);
        angleSteps.push_back(temp);
        sum += temp;
    }
    double k = sum / (2 * M_PI);
    for(int i = 0; i < numVerts; ++i) {
        angleSteps[i] = angleSteps[i] / k;
    }
    double angle = randomDouble(0, 2 * M_PI);
    std::normal_distribution<double> distribution(radius, spikeyness);
    QPolygon poly;
    for(int i = 0; i < numVerts; ++i) {
        double random = clip(distribution(*QRandomGenerator::global()), 0, 2 * radius);
        poly << QPoint(xPos + qFloor(random * qCos(angle)), yPos + qFloor(random * qSin(angle)));
        angle += angleSteps[i];
    }
    return poly;
}

double GeneratedShape::clip(double number, double max, double min) {
    if(min > max) return number;
    else if(number < min) return min;
    else if(number > max) return max;
    else return number;
}

double GeneratedShape::randomDouble(double a, double b) {
    double random = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    return a + (random * (b - a));
}

GeneratedShape::~GeneratedShape() {
    delete poly;
    delete pen;
    delete brush;
}
