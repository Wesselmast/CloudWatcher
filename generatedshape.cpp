#include "generatedshape.h"
#include <QDebug>

static bool firstTime = true;

GeneratedShape::GeneratedShape() {
    setFlag(ItemIsMovable);
    pen = new QPen(Qt::black);
    brush = new QBrush(Qt::black);
    smallPolygons = new QPolygon[amtOfSmallPolygons];
    mediumPolygons = new QPolygon[amtOfMediumPolygons];
    bigPolygons = new QPolygon[amtOfBigPolygons];
    canGenerate = false;
}

QRectF GeneratedShape::boundingRect() const {
    return QRectF(0, 0, 512, 512);
}

void GeneratedShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    pen->setJoinStyle(Qt::RoundJoin);

    if(canGenerate) {
        // MAKE THIS VARIABLE!
        int leniency = 80;

        int maxX = qFloor((boundingRect().width() / 2) + leniency);
        int minX = qFloor((boundingRect().width() / 2) - leniency);
        int maxY = qFloor((boundingRect().height() / 2) + leniency);
        int minY = qFloor((boundingRect().height() / 2) - leniency);

        for (int i = 0; i < amtOfSmallPolygons; ++i) {
            int xPos = rand() % (maxX-minX) + minX;
            int yPos = rand() % (maxY-minY) + minY;
            smallPolygons[i] = QPolygon(generatePolygon(xPos, yPos, 15, wonkynessSmall, spikeynessSmall, complexitySmall));
        }
        for (int i = 0; i < amtOfMediumPolygons; ++i) {
            int xPos = rand() % (maxX-minX) + minX;
            int yPos = rand() % (maxY-minY) + minY;
            mediumPolygons[i] = QPolygon(generatePolygon(xPos, yPos, 35, wonkynessMedium, spikeynessMedium, complexityMedium));
        }
        for (int i = 0; i < amtOfBigPolygons; ++i) {
            int xPos = rand() % (maxX-minX) + minX;
            int yPos = rand() % (maxY-minY) + minY;
            bigPolygons[i] = QPolygon(generatePolygon(xPos, yPos, 60, wonkynessBig, spikeynessBig, complexityBig));
        }

        firstTime = false;
        canGenerate = false;
    }
    if(firstTime) return;
    painter->setPen(*pen);
    for (int i = 0; i < amtOfSmallPolygons; ++i) {
        QPainterPath path;
        path.addPolygon(smallPolygons[i]);
        painter->fillPath(path, *brush);
        painter->drawPolygon(smallPolygons[i]);
    }
    for (int i = 0; i < amtOfMediumPolygons; ++i) {
        QPainterPath path;
        path.addPolygon(mediumPolygons[i]);
        painter->fillPath(path, *brush);
        painter->drawPolygon(mediumPolygons[i]);
    }
    for (int i = 0; i < amtOfBigPolygons; ++i) {
        QPainterPath path;
        path.addPolygon(bigPolygons[i]);
        painter->fillPath(path, *brush);
        painter->drawPolygon(bigPolygons[i]);
    }
}

void GeneratedShape::generate(double wonkynessSmall, double spikeynessSmall, int complexitySmall,
                              double wonkynessMedium, double spikeynessMedium, int complexityMedium,
                              double wonkynessBig, double spikeynessBig, int complexityBig) {
    canGenerate = true;
    this->wonkynessSmall = wonkynessSmall;
    this->wonkynessMedium = wonkynessMedium;
    this->wonkynessBig = wonkynessBig;
    this->spikeynessSmall = spikeynessSmall;
    this->spikeynessMedium = spikeynessMedium;
    this->spikeynessBig = spikeynessBig;
    this->complexitySmall = complexitySmall;
    this->complexityMedium = complexityMedium;
    this->complexityBig = complexityBig;
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
    delete pen;
    delete brush;
}
