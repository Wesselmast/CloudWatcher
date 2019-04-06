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
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generate(double wonkynessSmall, double spikeynessSmall, int complexitySmall,
                  double wonkynessMedium, double spikeynessMedium, int complexityMedium,
                  double wonkynessBig, double spikeynessBig, int complexityBig);
    ~GeneratedShape();
public:
    QPen* pen;
    QBrush* brush;
private:
    QPolygon generatePolygon(int xPos, int yPos, double radius, double wonkyness, double spikeyness, int numVerts);
    double clip(double number, double max, double min);
    double randomDouble(double a, double b);
private:
    QPolygon *smallPolygons;
    QPolygon *mediumPolygons;
    QPolygon *bigPolygons;
    const int amtOfSmallPolygons = 7;
    const int amtOfMediumPolygons = 4;
    const int amtOfBigPolygons = 2;
    double spikeynessSmall = 0;
    double wonkynessSmall = 0;
    int complexitySmall = 5;
    double spikeynessMedium = 0;
    double wonkynessMedium = 0;
    int complexityMedium = 5;
    double spikeynessBig = 0;
    double wonkynessBig = 0;
    int complexityBig = 5;
    bool canGenerate = true;
};

#endif // GENERATEDSHAPE_H
