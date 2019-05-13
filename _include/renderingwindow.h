#ifndef RENDERINGWINDOW_H
#define RENDERINGWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include "generatedshape.h"
#include <QSlider>
#include <QList>
#include <QStyleOptionGraphicsItem>
#include <QFileDialog>
#include <QSpinBox>
#include "_include/globals.h"

namespace Ui {
class RenderingWindow;
}

class RenderingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RenderingWindow(QWidget *parent = nullptr);
    ~RenderingWindow();
private:
    void setGlobalsToSliders();
    void generateShape(GeneratedShape *shapeCollection, int size, int amtOfShapes, double wonkyness, double spikeyness, int complexity);
    void lineThickness(GeneratedShape *shapeCollection, int value, int amtOfShapes);
    void keyPressEvent(QKeyEvent *key);
private:
    QRandomGenerator *generator;
    Ui::RenderingWindow *ui;
    QGraphicsScene *scene;
    GeneratedShape *shape;
    QList<QSlider*> sliders;
private slots:
    void generateShapeButton();
    void exportShapeButton();
    void randomizeShapeButton();
    void on_presetDropdown_currentIndexChanged(int index);
    void on_primaryComplexitySlider_valueChanged(int value);
    void on_primaryEdgeSlider_valueChanged(int value);
    void on_primaryRadiusSlider_valueChanged(int value);
    void on_secondaryComplexitySlider_valueChanged(int value);
    void on_secondaryEdgeSlider_valueChanged(int value);
    void on_secondaryRadiusSlider_valueChanged(int value);
    void on_negativeComplexitySlider_valueChanged(int value);
    void on_negativeEdgeSlider_valueChanged(int value);
    void on_negativeRadiusSlider_valueChanged(int value);
};

#endif // RENDERINGWINDOW_H
