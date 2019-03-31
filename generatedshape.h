#ifndef GENERATEDSHAPE_H
#define GENERATEDSHAPE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtMath>
#include <random>
#include <QRandomGenerator>

class GeneratedShape : public QGraphicsItem {
public:
    GeneratedShape();
    GeneratedShape(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generate(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts);

private:
    QPolygon* poly;
    QPolygon generatePolygon(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts);
    double clip(double number, double max, double min);
    double randomDouble(double a, double b);
    std::default_random_engine generator;
    double radius;
    double wonkyness;
    double spikeyness;
    int xPos;
    int yPos;
    int numVerts;
    bool canGenerate;
};

#endif // GENERATEDSHAPE_H
