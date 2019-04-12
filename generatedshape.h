#ifndef GENERATEDSHAPE_H
#define GENERATEDSHAPE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtMath>
#include <random>
#include <QRandomGenerator>
#include "globals.h"

class GeneratedShape : public QGraphicsItem {
public:
    GeneratedShape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generate();
    ~GeneratedShape();
public:
    QPen* pen;
    QBrush* brush;
private:
    QPolygon generatePolygon(int xPos, int yPos, double radius, double spikeyness, int numVerts, int numSplines);
    double clip(double number, double max, double min);
    double randomDouble(double a, double b);
    QPoint randomPositionInTriangle(QPoint A, QPoint B, QPoint C);
    QList<QPoint>generateSplines(QList<QPoint> points, int numSplines);
    QPoint pointOnCurve(QPoint p0, QPoint p1, QPoint p2, QPoint p3, float t);

private:
    QPolygon *smallPolygons;
    QPolygon *mediumPolygons;
    QPolygon *bigPolygons;
    const int amtOfSmallPolygons = 0;
    const int amtOfMediumPolygons = 3;
    const int amtOfBigPolygons = 3;

    bool canGenerate = true;
};

#endif // GENERATEDSHAPE_H
