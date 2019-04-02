#ifndef COMPLETESHAPE_H
#define COMPLETESHAPE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtMath>
#include <random>
#include <QRandomGenerator>
#include <memory>
#include <QtDebug>
#include "generatedshape.h"

class CompleteShape : public QGraphicsItem
{
public:
    CompleteShape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generate();
    void changeLineThickness(int value);
    double spikeyness;
    double wonkyness;
    int complexity;
    ~CompleteShape();
private:
    GeneratedShape *shapes;
    const int amtOfShapes = 10;
};

#endif // COMPLETESHAPE_H
