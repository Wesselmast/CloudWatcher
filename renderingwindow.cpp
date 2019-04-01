#include "renderingwindow.h"
#include "ui_renderingwindow.h"

RenderingWindow::RenderingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderingWindow)
{
    srand(time_t(NULL));
    ui->setupUi(this);
    spikeyness = 0;
    wonkyness = 0;
    complexity = 5;

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    shapes = new GeneratedShape[amtOfShapes];
    for(int i = 0; i < amtOfShapes; ++i) {
        scene->addItem(&shapes[i]);
    }

    connect(ui->generateButton, SIGNAL(released()), this, SLOT(generateShapeButton()));
}

void RenderingWindow::generateShapeButton() {
    for(int i = 0; i < amtOfShapes; ++i) {
        shapes[i].generate((rand() % 150) - 75, (rand() % 200) - 100, 55, wonkyness, spikeyness, complexity);
        shapes[i].setRotation(rand() % 360);
    }
}

void RenderingWindow::on_AggresivenessSlider_valueChanged(int value) {
    spikeyness = static_cast<double>(value * .005);
}

void RenderingWindow::on_IrregularitySlider_valueChanged(int value) {
    wonkyness = static_cast<double>(value * .005);
}

void RenderingWindow::on_ComplexitySlider_valueChanged(int value) {
    complexity = value;
}

RenderingWindow::~RenderingWindow() {
    delete ui;
    delete scene;
}
