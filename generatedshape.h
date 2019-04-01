#ifndef GENERATEDSHAPE_H
#define GENERATEDSHAPE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtMath>
#include <random>
#include <QRandomGenerator>
#include <memory>

class GeneratedShape : public QGraphicsItem {
public:
    GeneratedShape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generate(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts);
    ~GeneratedShape();
private:
    QPolygon generatePolygon(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts);
    double clip(double number, double max, double min);
    double randomDouble(double a, double b);
private:
    QPolygon* poly;
    double radius;
    double wonkyness;
    double spikeyness;
    int xPos;
    int yPos;
    int numVerts;
    bool canGenerate = true;
};

#endif // GENERATEDSHAPE_H
