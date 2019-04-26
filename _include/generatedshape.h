#ifndef GENERATEDSHAPE_H
#define GENERATEDSHAPE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtMath>
#include <random>
#include <QRandomGenerator>
#include "_include/globals.h"
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>

class GeneratedShape : public QObject, public QGraphicsItem {
public:
    GeneratedShape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void initPolygons();
    void generate();
    ~GeneratedShape();
public:
    QPen* pen;
    QBrush* brush;
protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
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
    QRectF localBoundingRect;
    QTransform startTransform;
    int localSmallAmtOfPolygons = 5;
    int localMediumAmtOfPolygons = 5;
    int localBigAmtOfPolygons = 5;

    const int width = 350;
    const int height = 500;
    const bool drawSizePolygon = false;

    bool firstTime = true;
    bool canGenerate = true;
private slots:
    void rotateShape(int amt);
};

#endif // GENERATEDSHAPE_H
