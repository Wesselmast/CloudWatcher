#ifndef RENDERINGWINDOW_H
#define RENDERINGWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include "generatedshape.h"

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
    void generateShape(int size);
private:
    Ui::RenderingWindow *ui;
    QGraphicsScene *scene;
    GeneratedShape *shapes;
    const int amtOfShapes = 10;
    double spikeyness;
    double wonkyness;
    int complexity;
private slots:
    void generateShapeButton();
    void on_AggresivenessSlider_valueChanged(int value);
    void on_ComplexitySlider_valueChanged(int value);
    void on_IrregularitySlider_valueChanged(int value);
};

#endif // RENDERINGWINDOW_H
