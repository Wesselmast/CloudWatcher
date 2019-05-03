#ifndef GENERATEDSHAPE_H
#define GENERATEDSHAPE_H

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
protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
    QPolygon generatePolygon(int xPos, int yPos, double radius, double spikeyness, int numVerts, int numSplines);
    QPoint randomPositionInTriangle(QPoint A, QPoint B, QPoint C);
    QList<QPoint>generateSplines(QList<QPoint> points, int numSplines);
    QPoint pointOnCurve(QPoint p0, QPoint p1, QPoint p2, QPoint p3, float t);
private:
    QList<QPolygon> polygons;
    QRectF localBoundingRect;
    int localAmtOfPolygons = 5;

    const int width = 350;
    const int height = 500;
    const bool drawSizePolygon = false;

    bool firstTime = true;
    bool canGenerate = true;
private slots:
    void rotateShape(int amt);
};

#endif // GENERATEDSHAPE_H
