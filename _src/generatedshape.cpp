#include "_include/generatedshape.h"
#include <QDebug>

GeneratedShape::GeneratedShape() {
    pen = new QPen(Qt::black);
    brush = new QBrush(Qt::black);
    localBoundingRect = QRectF(0, 0, width, height);
    startTransform = transform();
    initPolygons();
    canGenerate = false;
}

QRectF GeneratedShape::boundingRect() const {
    return localBoundingRect;
}

void GeneratedShape::initPolygons() {
    smallPolygons = new QPolygon[amtOfSmallPolygons];
    mediumPolygons = new QPolygon[amtOfMediumPolygons];
    bigPolygons = new QPolygon[amtOfBigPolygons];
}

void GeneratedShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    pen->setJoinStyle(Qt::RoundJoin);
    if(canGenerate) {
        setTransform(startTransform);

        localBigAmtOfPolygons = amtOfBigPolygons;
        localMediumAmtOfPolygons = amtOfMediumPolygons;
        localSmallAmtOfPolygons = amtOfSmallPolygons;

        double heightSlope = ((height - margin) - margin) / 99.0;
        double widthSlope = ((width - margin) - margin) / 99.0;
        int localPointOfBalance = qFloor(margin + qRound(heightSlope * (99.0 - pointOfBalance)));
        int mappedAngularness = qFloor(widthSlope * angularness);
        int localAngularness = (rand() % 2 + 1) == 1 ? width/2 - mappedAngularness/2 : width/2 + mappedAngularness/2;

        QPoint A(localAngularness, margin);
        QPoint B(width - margin, localPointOfBalance);
        QPoint C(localAngularness, height - margin);
        QPoint D(margin, localPointOfBalance);

        if(drawSizePolygon) {
            QPolygon poly;
            poly << A;
            poly << B;
            poly << C;
            poly << D;
            painter->drawPolygon(poly);
            painter->drawText(A, "A");
            painter->drawText(B, "B");
            painter->drawText(C, "C");
            painter->drawText(D, "D");
        }

        for (int i = 0; i < amtOfSmallPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            smallPolygons[i] = QPolygon(generatePolygon(point.x(), point.y(), radiusSmall, spikeynessSmall, complexitySmall, curvynessSmall));
        }
        for (int i = 0; i < amtOfMediumPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            mediumPolygons[i] = QPolygon(generatePolygon(point.x(), point.y(), radiusMedium, spikeynessMedium, complexityMedium, curvynessMedium));
        }
        for (int i = 0; i < amtOfBigPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            bigPolygons[i] = QPolygon(generatePolygon(point.x(), point.y(), radiusBig, spikeynessBig, complexityBig, curvynessBig));
        }
        firstTime = false;
        canGenerate = false;
    }
    if(firstTime) return;
    painter->setPen(*pen);
    if(drawSizePolygon) return;
    double minimumX = 9999;
    double maximumX = -9999;
    double minimumY = 9999;
    double maximumY = -9999;

    double edgeMargin = 35;

    for (int i = 0; i < localMediumAmtOfPolygons; ++i) {
        QPainterPath path;
        path.addPolygon(mediumPolygons[i]);
        painter->fillPath(path, *brush);
        painter->drawPolygon(mediumPolygons[i]);
        if(mediumPolygons[i].boundingRect().x() < minimumX) {
            minimumX = mediumPolygons[i].boundingRect().x() - edgeMargin;
        }
        else if(mediumPolygons[i].boundingRect().x() + mediumPolygons[i].boundingRect().width() > maximumX) {
            maximumX = mediumPolygons[i].boundingRect().x() + mediumPolygons[i].boundingRect().width() + edgeMargin;
        }
        if(mediumPolygons[i].boundingRect().y() < minimumY) {
            minimumY = mediumPolygons[i].boundingRect().y() - edgeMargin;
        }
        else if(mediumPolygons[i].boundingRect().y() + mediumPolygons[i].boundingRect().height() > maximumY) {
            maximumY = mediumPolygons[i].boundingRect().y() + mediumPolygons[i].boundingRect().height() + edgeMargin;
        }
    }
    for (int i = 0; i < localBigAmtOfPolygons; ++i) {
        QPainterPath path;
        path.addPolygon(bigPolygons[i]);
        painter->fillPath(path, *brush);
        painter->drawPolygon(bigPolygons[i]);
        if(bigPolygons[i].boundingRect().x() < minimumX) {
            minimumX = bigPolygons[i].boundingRect().x() - edgeMargin;
        }
        else if(bigPolygons[i].boundingRect().x() + bigPolygons[i].boundingRect().width() > maximumX) {
            maximumX = bigPolygons[i].boundingRect().x() + bigPolygons[i].boundingRect().width() + edgeMargin;
        }
        if(bigPolygons[i].boundingRect().y() < minimumY) {
            minimumY = bigPolygons[i].boundingRect().y() - edgeMargin;
        }
        else if(bigPolygons[i].boundingRect().y() + bigPolygons[i].boundingRect().height() > maximumY) {
            maximumY = bigPolygons[i].boundingRect().y() + bigPolygons[i].boundingRect().height() + edgeMargin;
        }
    }
    //brush->setColor(Qt::white);
    //painter->setPen(QPen(Qt::white));
    for (int i = 0; i < localSmallAmtOfPolygons; ++i) {
        QPainterPath path;
        path.addPolygon(smallPolygons[i]);
        painter->fillPath(path, *brush);
        painter->drawPolygon(smallPolygons[i]);
        if(smallPolygons[i].boundingRect().x() < minimumX) {
            minimumX = smallPolygons[i].boundingRect().x() - edgeMargin;
        }
        else if(smallPolygons[i].boundingRect().x() + smallPolygons[i].boundingRect().width() > maximumX) {
            maximumX = smallPolygons[i].boundingRect().x() + smallPolygons[i].boundingRect().width() + edgeMargin;
        }
        if(smallPolygons[i].boundingRect().y() < minimumY) {
            minimumY = smallPolygons[i].boundingRect().y() - edgeMargin;
        }
        else if(smallPolygons[i].boundingRect().y() + smallPolygons[i].boundingRect().height() > maximumY) {
            maximumY = smallPolygons[i].boundingRect().y() + smallPolygons[i].boundingRect().height() + edgeMargin;
        }
    }
    //brush->setColor(Qt::black);
    //painter->setPen(Qt::black);
    localBoundingRect = QRectF(minimumX, minimumY, maximumX-minimumX, maximumY-minimumY);
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

void GeneratedShape::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    QMenu *menu = new QMenu();
    QMenu *rotateCanvas = new QMenu("Rotate Canvas");
    QAction* clockwise = new QAction("90° CW");
    QAction* counterClockwise = new QAction("90° CCW");
    QAction* horizontalFlip = new QAction("Flip Horizontal");
    QAction* verticalFlip = new QAction("Flip Vertical");
    rotateCanvas->addAction(clockwise);
    rotateCanvas->addAction(counterClockwise);
    rotateCanvas->addSeparator();
    rotateCanvas->addAction(horizontalFlip);
    rotateCanvas->addAction(verticalFlip);
    connect(clockwise, &QAction::triggered, this, [=]() { rotateShape(90); });
    connect(counterClockwise, &QAction::triggered, this, [=]() { rotateShape(-90); });
    connect(horizontalFlip, &QAction::triggered, this, [=]() {
        qreal localm31 = boundingRect().width() * scale();
        if(transform().m31() > 0) localm31 = 0;
        setTransform(QTransform(
                         -transform().m11(),
                         transform().m12(),
                         transform().m13(),
                         transform().m21(),
                         transform().m22(),
                         transform().m23(),
                         localm31,
                         transform().m32(),
                         transform().m33()
                         ));
    });
    connect(verticalFlip, &QAction::triggered, this, [=]() {
        qreal localm32 = boundingRect().height() * scale();
        if(transform().m32() > 0) localm32 = 0;
        setTransform(QTransform(
                         transform().m11(),
                         transform().m12(),
                         transform().m13(),
                         transform().m21(),
                         -transform().m22(),
                         transform().m23(),
                         transform().m31(),
                         localm32,
                         transform().m33()
                         ));
    });
    menu->addMenu(rotateCanvas);
    menu->popup(event->screenPos());
}

void GeneratedShape::rotateShape(int amt) {
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + amt);
}

GeneratedShape::~GeneratedShape() {
    delete pen;
    delete brush;
}
