#ifndef COMPLETESHAPE_H
#define COMPLETESHAPE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtMath>
#include <random>
#include <QRandomGenerator>
#include <memory>

class CompleteShape : public QGraphicsItem {
public:
    CompleteShape();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~CompleteShape();
};

#endif // COMPLETESHAPE_H
