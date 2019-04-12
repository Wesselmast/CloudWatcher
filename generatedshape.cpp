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
        // MAKE THESE VARIABLE!
        int margin = 180;
        int pointOfBalance = 99;

        double slope = ((boundingRect().height() - margin) - margin) / 99;
        int BDHeight = qFloor(margin + qRound(slope * (99 - pointOfBalance)));

        QPolygon poly;
        QPoint A(qFloor(boundingRect().width() / 2), margin);
        QPoint B(qFloor(boundingRect().width()) - margin, BDHeight);
        QPoint C(qFloor(boundingRect().width() / 2), qFloor(boundingRect().height()) - margin);
        QPoint D(margin, BDHeight);

        poly << A;
        poly << B;
        poly << C;
        poly << D;
        painter->drawPolygon(poly);

        for (int i = 0; i < amtOfSmallPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            smallPolygons[i] = QPolygon(generatePolygon(point.x(), point.y(), 20, spikeynessSmall, complexitySmall, 1));
        }
        for (int i = 0; i < amtOfMediumPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            mediumPolygons[i] = QPolygon(generatePolygon(point.x(), point.y(), 40, spikeynessMedium, complexityMedium, 5));
        }
        for (int i = 0; i < amtOfBigPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            bigPolygons[i] = QPolygon(generatePolygon(point.x(), point.y(), 60, spikeynessBig, complexityBig, 2));
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

QPoint GeneratedShape::randomPositionInTriangle(QPoint A, QPoint B, QPoint C) {
    double r1 = randomDouble(0, 1);
    double r2 = randomDouble(0, 1);

    return QPoint(
                qFloor(
                    (1 - sqrt(r1)) * A.x() +
                    (sqrt(r1) * (1 - r2)) * B.x() +
                    (sqrt(r1) * r2) * C.x()),
                qFloor(
                    (1 - sqrt(r1)) * A.y() +
                    (sqrt(r1) * (1 - r2)) * B.y() +
                    (sqrt(r1) * r2) * C.y())
                );
}


void GeneratedShape::generate() {
    canGenerate = true;
    update();
}

QPolygon GeneratedShape::generatePolygon(int xPos, int yPos, double radius, double spikeyness, int numVerts, int numSplines) {
    spikeyness = clip(spikeyness, 0, 1) * radius;

    QList<double> angleSteps;
    double sum = 0;
    for(int i = 0; i < numVerts; ++i) {
        angleSteps.push_back(2 * M_PI / numVerts);
        sum += 2 * M_PI / numVerts;
    }
    double k = sum / (2 * M_PI);
    for(int i = 0; i < numVerts; ++i) {
        angleSteps[i] = angleSteps[i] / k;
    }
    double angle = randomDouble(0, 2 * M_PI);
    std::normal_distribution<double> distribution(radius, spikeyness);
    QPolygon poly;
    QList<QPoint> points;
    for(int i = 0; i < numVerts; ++i) {
        double random = clip(distribution(*QRandomGenerator::global()), 0, 2 * radius);
        points.push_back(QPoint(xPos + qFloor(random * qCos(angle)), yPos + qFloor(random * qSin(angle))));
        angle += angleSteps[i];
    }
    QList<QPoint> splinedPoints = generateSplines(points, numSplines);
    for(int i = 0; i < splinedPoints.length(); ++i) {
        poly << splinedPoints[i];
    }
    return poly;
}

QList<QPoint> GeneratedShape::generateSplines(QList<QPoint> points, int numSplines) {
    QList<QPoint> splinePoints;
    for (int i = 0; i < points.size() - 3; i++) {
        for (int j = 0; j < numSplines; j++) {
            splinePoints.push_back(pointOnCurve(points[i], points[i + 1], points[i + 2], points[i + 3], (1.0f / numSplines) * j));
        }
    }
    splinePoints.push_back(points[points.length() - 2]);
    return splinePoints;
}

QPoint GeneratedShape::pointOnCurve(QPoint p0, QPoint p1, QPoint p2, QPoint p3, float t) {
    QPoint spline;

    float t2 = t * t;
    float t3 = t2 * t;

    spline.setX(qRound(0.5f * ((2.0f * p1.x()) +
    (-p0.x() + p2.x()) * t +
    (2.0f * p0.x() - 5.0f * p1.x() + 4 * p2.x() - p3.x()) * t2 +
    (-p0.x() + 3.0f * p1.x() - 3.0f * p2.x() + p3.x()) * t3)));

    spline.setY(qRound(0.5f * ((2.0f * p1.y()) +
    (-p0.y() + p2.y()) * t +
    (2.0f * p0.y() - 5.0f * p1.y() + 4 * p2.y() - p3.y()) * t2 +
    (-p0.y() + 3.0f * p1.y() - 3.0f * p2.y() + p3.y()) * t3)));

    return spline;
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
