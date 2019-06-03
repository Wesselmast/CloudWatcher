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
#include <QQmlComponent>
#include <QDesktopServices>
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
    void exportShape(bool quickexport = false);
private:
    QQuickWidget *qmlView;
    QGraphicsScene *scene;
    GeneratedShape *shape;
    QGraphicsView *graphicsView;

    QDir exportDir;

    const unsigned short width = 900;
    const unsigned short height = 900;
private slots:
    void generateShapeButton();
};

#endif // RENDERINGWINDOW_H
