#ifndef GENERATEDSHAPE_H
#define GENERATEDSHAPE_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QtMath>
#include <random>
#include "_include/math.h"
#include <QRandomGenerator>
#include "_include/globals.h"
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QList>
#include <memory>

class GeneratedShape : public QObject, public QGraphicsItem {
public:
    GeneratedShape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generate();
    ~GeneratedShape();
public:
    QPen* pen;
    QBrush* brush;

    const QColor color = Qt::black;
    const unsigned short width = 450;
    const unsigned short height = 450;
public slots:
    void rotateShape(int amt);
    void doHorizontalFlip();
    void doVerticalFlip();
protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
    QPolygon generatePolygon(int xPos, int yPos, double radius, double spikeyness, int numVerts, int numSplines);
    QPoint randomPositionInTriangle(QPoint A, QPoint B, QPoint C);
    QList<QPoint>generateSplines(QList<QPoint> points, int numSplines);
    QPoint pointOnCurve(QPoint p0, QPoint p1, QPoint p2, QPoint p3, float t);
private:
    QRandomGenerator *generator;
    QList<QPolygon> polygons;
    QList<QPoint> points;
    QRectF localBoundingRect;
    const bool drawSizePolygon = false;

    int localAmtOfPolygons = 5;
    int amtOfNegativePolygons = 4;
    int amtOfSecondaryPolygons = 5;
    int amtOfPrimaryPolygons = 5;

    bool firstTime = true;
    bool canGenerate = true;
};

#endif // GENERATEDSHAPE_H
