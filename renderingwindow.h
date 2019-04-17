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
#include "globals.h"

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
    QList<QSpinBox*> spinBoxes;
private slots:
    void generateShapeButton();
    void exportShapeButton();
    void randomizeShapeButton();
    void on_LineThickSlider_valueChanged(int value);
    void on_AggresivenessSmallSlider_valueChanged(int value);
    void on_ComplexitySmallSlider_valueChanged(int value);
    void on_AggresivenessMediumSlider_valueChanged(int value);
    void on_ComplexityMediumSlider_valueChanged(int value);
    void on_AggresivenessBigSlider_valueChanged(int value);
    void on_ComplexityBigSlider_valueChanged(int value);
    void on_CurvynessSmallSlider_valueChanged(int value);
    void on_CurvynessMediumlSlider_valueChanged(int value);
    void on_CurvynessBigSlider_valueChanged(int value);
    void on_OuterMarginSlider_valueChanged(int value);
    void on_CenterOfBalanceSlider_valueChanged(int value);
    void on_AmountOfSmallShapes_valueChanged(int arg1);
    void on_AmountOfMediumShapes_valueChanged(int arg1);
    void on_AmountOfBigShapes_valueChanged(int arg1);
    void on_RadiusSmallSlider_valueChanged(int value);
    void on_RadiusMediumSlider_valueChanged(int value);
    void on_RadiusBigSlider_valueChanged(int value);
    void on_VerticalDiagonalSlider_valueChanged(int value);
};

#endif // RENDERINGWINDOW_H
