#include "_include/generatedshape.h"
#include <QDebug>

GeneratedShape::GeneratedShape() {
    pen = new QPen(color);
    brush = new QBrush(color);
    generator = QRandomGenerator::global();
    localBoundingRect = QRectF(0, 0, width, height);
    canGenerate = false;
}

QRectF GeneratedShape::boundingRect() const {
    return localBoundingRect;
}

void GeneratedShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    pen->setJoinStyle(Qt::RoundJoin);
    painter->setRenderHint(QPainter::Antialiasing);
    if(canGenerate) {
        polygons.clear();

        amtOfPrimaryPolygons = qRound(randomDouble(5, 8));
        amtOfSecondaryPolygons = qRound(randomDouble(5, 8));
        amtOfNegativePolygons = 3;

        int halfWidth = width/2;
        int halfHeight = height/2;

        int margin = 50;
        int localPointOfBalance = qFloor(randomDouble(height - margin, margin));
        int mappedAngularness = qFloor(randomDouble(0, width - (margin * 2)) * 0.5);
        int localAngularness = (rand() % 2 + 1) == 1 ? halfWidth - mappedAngularness : halfWidth + mappedAngularness;

        QPoint A(halfWidth + localAngularness, halfHeight + margin);
        QPoint B(halfWidth + width - margin,   halfHeight + localPointOfBalance);
        QPoint C(halfWidth + localAngularness, halfHeight + height - margin);
        QPoint D(halfWidth + margin,           halfHeight + localPointOfBalance);

        if(drawSizePolygon) {
            QPolygon poly;
            poly << A << B << C << D;
            painter->drawPolygon(poly);
            painter->drawText(A, "A");
            painter->drawText(B, "B");
            painter->drawText(C, "C");
            painter->drawText(D, "D");
        }

        for (int i = 0; i < amtOfPrimaryPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            polygons.push_back(QPolygon(generatePolygon(point.x(), point.y(), primaryRadius, primarySpikeyness, primaryComplexity, primaryCurvyness)));
        }
        for (int i = 0; i < amtOfSecondaryPolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            polygons.push_back(QPolygon(generatePolygon(point.x(), point.y(), secondaryRadius, secondarySpikeyness, secondaryComplexity, secondaryCurvyness)));
        }
        for (int i = 0; i < amtOfNegativePolygons; ++i) {
            QPoint point = (rand() % 2 + 1) == 1 ? randomPositionInTriangle(A, B, C) : randomPositionInTriangle(B, C, D);
            polygons.push_back(QPolygon(generatePolygon(point.x(), point.y(), negativeRadius, negativeSpikeyness, negativeComplexity, negativeCurvyness)));
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

    for (int i = 0; i < polygons.size(); ++i) {
        QPainterPath path;
        path.addPolygon(polygons[i]);
        QBrush localBrush = *brush;
        if(i > (polygons.size() - amtOfNegativePolygons - 1)) {
            painter->setPen(QPen(Qt::white));
            localBrush = QBrush(Qt::white);
        }
        painter->fillPath(path, localBrush);
        painter->drawPolygon(polygons[i]);
        if(polygons[i].boundingRect().x() < minimumX) {
            minimumX = polygons[i].boundingRect().x();
        }
        if(polygons[i].boundingRect().x() + polygons[i].boundingRect().width() > maximumX) {
            maximumX = polygons[i].boundingRect().x() + polygons[i].boundingRect().width();
        }
        if(polygons[i].boundingRect().y() < minimumY) {
            minimumY = polygons[i].boundingRect().y();
        }
        if(polygons[i].boundingRect().y() + polygons[i].boundingRect().height() > maximumY) {
            maximumY = polygons[i].boundingRect().y() + polygons[i].boundingRect().height();
        }
    }
    localBoundingRect = QRectF(minimumX, minimumY, maximumX-minimumX, maximumY-minimumY);
}

QPoint GeneratedShape::randomPositionInTriangle(QPoint A, QPoint B, QPoint C) {
    double r1 = randomDouble(0, 1);
    double r2 = randomDouble(0, 1);

    return QPoint(
                qFloor(
                    (1 - sqrt(r1)) * A.x()             +
                    (sqrt(r1)      * (1 - r2)) * B.x() +
                    (sqrt(r1)      * r2)       * C.x()),
                qFloor(
                    (1 - sqrt(r1)) * A.y()             +
                    (sqrt(r1)      * (1 - r2)) * B.y() +
                    (sqrt(r1)      * r2)       * C.y())
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
        double random = clip(distribution(*generator), 0, 2 * radius);
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

QPoint GeneratedShape::pointOnCurve(QPoint p, QPoint p2, QPoint p3, QPoint p4, float t) {
    float t2 = t * t;
    float t3 = t2 * t;

    return QPoint(
                qRound(
                    0.5f     * ((2.0f  * p2.x())          +
                    (-p.x()  + p3.x()) * t                +
                    (2.0f    * p.x()   - 5.0f    * p2.x() +
                    4        * p3.x()  - p4.x()) * t2     +
                    (-p.x()  + 3.0f    * p2.x()  - 3.0f   *
                     p3.x()  + p4.x()) * t3)),
                qRound(
                    0.5f     * ((2.0f  * p2.y())          +
                    (-p.y()  + p3.y()) * t                +
                    (2.0f    * p.y()   - 5.0f    * p2.y() +
                    4        * p3.y()  - p4.y()) * t2     +
                    (-p.y()  + 3.0f    * p2.y()  - 3.0f   *
                     p3.y()  + p4.y()) * t3))
                );
}

void GeneratedShape::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    QMenu *menu = new QMenu();
    QMenu *rotateCanvas = new QMenu("Rotate Shape");
    QAction* clockwise = new QAction("90° CW");
    QAction* counterClockwise = new QAction("90° CCW");
    QAction* horizontalFlip = new QAction("Flip Horizontal");
    QAction* verticalFlip = new QAction("Flip Vertical");

    rotateCanvas->addAction(clockwise);
    rotateCanvas->addAction(counterClockwise);
    rotateCanvas->addSeparator();
    rotateCanvas->addAction(horizontalFlip);
    rotateCanvas->addAction(verticalFlip);
    connect(clockwise, &QAction::triggered, this, [=]() {
        rotateShape(90);
    });
    connect(counterClockwise, &QAction::triggered, this, [=]() {
        rotateShape(-90);
    });
    connect(horizontalFlip, &QAction::triggered, this, [=]() {
        doHorizontalFlip();
    });
    connect(verticalFlip, &QAction::triggered, this, [=]() {
        doVerticalFlip();
    });
    menu->addMenu(rotateCanvas);
    menu->popup(event->screenPos());
}

void GeneratedShape::rotateShape(int amt) {
    setTransformOriginPoint(boundingRect().center());
    setRotation(rotation() + amt);
}

void GeneratedShape::doHorizontalFlip() {
    double localm31 = width * 2 * scale();
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
}

void GeneratedShape::doVerticalFlip() {
    double localm32 = height * 2 * scale();
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
}

GeneratedShape::~GeneratedShape() {
    delete pen;
    delete brush;
}
