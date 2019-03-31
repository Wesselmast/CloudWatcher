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
    Ui::RenderingWindow *ui;
    QGraphicsScene *scene;
    QList<GeneratedShape*> shapes;
    void generateShape(int size);
    double spikeyness;
private slots:
    void generateShapeButton();
    void on_verticalSlider_valueChanged(int value);
};

#endif // RENDERINGWINDOW_H
