#ifndef RENDERINGWINDOW_H
#define RENDERINGWINDOW_H

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
#include <QQuickWidget>
#include <QBoxLayout>
#include <QQmlEngine>
#include <QQmlContext>
#include <QLabel>
#include "backend.h"
#include "_include/globals.h"

class RenderingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RenderingWindow(QWidget *parent = nullptr);
    ~RenderingWindow();
private:
    void keyPressEvent(QKeyEvent *key);
private:
    QQuickWidget *qmlView;
    QRandomGenerator *generator;
    QGraphicsScene *scene;
    GeneratedShape *shape;
    QGraphicsView *graphicsView;

    const unsigned short width = 800;
    const unsigned short height = 800;
private slots:
    void generateShapeButton();
    void exportShapeButton();
};

#endif // RENDERINGWINDOW_H
