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
    void generateShape(GeneratedShape *shapeCollection, int size, int amtOfShapes, double wonkyness, double spikeyness, int complexity);
    void lineThickness(GeneratedShape *shapeCollection, int value, int amtOfShapes);
private:
    Ui::RenderingWindow *ui;
    QGraphicsScene *scene;
    GeneratedShape *shape;
    QList<QSlider*> sliders;
    double spikeynessSmall = 0;
    double wonkynessSmall = 0;
    int complexitySmall = 5;
    double spikeynessMedium = 0;
    double wonkynessMedium = 0;
    int complexityMedium = 5;
    double spikeynessBig = 0;
    double wonkynessBig = 0;
    int complexityBig = 5;
private slots:
    void generateShapeButton();
    void exportShapeButton();
    void randomizeShapeButton();
    void on_LineThickSlider_valueChanged(int value);
    void on_AggresivenessSmallSlider_valueChanged(int value);
    void on_ComplexitySmallSlider_valueChanged(int value);
    void on_IrregularitySmallSlider_valueChanged(int value);
    void on_AggresivenessMediumSlider_valueChanged(int value);
    void on_ComplexityMediumSlider_valueChanged(int value);
    void on_IrregularityMediumSlider_valueChanged(int value);
    void on_AggresivenessBigSlider_valueChanged(int value);
    void on_ComplexityBigSlider_valueChanged(int value);
    void on_IrregularityBigSlider_valueChanged(int value);
};

#endif // RENDERINGWINDOW_H
