#include "renderingwindow.h"
#include "ui_renderingwindow.h"

RenderingWindow::RenderingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderingWindow)
{
    srand(time_t(NULL));
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    sliders = RenderingWindow::findChildren<QSlider*>();

    bigShapes = new GeneratedShape[amtOfBigShapes];
    mediumShapes = new GeneratedShape[amtOfMediumShapes];
    smallShapes = new GeneratedShape[amtOfSmallShapes];

    for(int i = 0; i < amtOfBigShapes; ++i) {
        scene->addItem(&bigShapes[i]);
    }
    for(int i = 0; i < amtOfMediumShapes; ++i) {
        scene->addItem(&mediumShapes[i]);
    }
    for(int i = 0; i < amtOfSmallShapes; ++i) {
        scene->addItem(&smallShapes[i]);
    }

    connect(ui->generateButton, SIGNAL(released()), this, SLOT(generateShapeButton()));
    connect(ui->exportButton, SIGNAL(released()), this, SLOT(exportShapeButton()));
    connect(ui->randomizeButton, SIGNAL(released()), this, SLOT(randomizeShapeButton()));
}

void RenderingWindow::randomizeShapeButton() {
    for(int i = 0; i < sliders.length(); ++i) {
        sliders[i]->setValue(rand() % (sliders[i]->maximum() - sliders[i]->minimum() + 1) + sliders[i]->minimum());
    }
}

void RenderingWindow::generateShapeButton() {
    generateShape(bigShapes, 70, amtOfBigShapes, wonkynessBig, spikeynessBig, complexityBig);
    generateShape(mediumShapes, 40, amtOfMediumShapes, wonkynessMedium, spikeynessMedium, complexityMedium);
    generateShape(smallShapes, 15, amtOfSmallShapes, wonkynessSmall, spikeynessSmall, complexitySmall);
}

void RenderingWindow::generateShape(GeneratedShape *shapeCollection, int size, int amtOfShapes, double wonkyness, double spikeyness, int complexity) {
    for(int i = 0; i < amtOfShapes; ++i) {
        shapeCollection[i].generate((rand() % 150) - 75, (rand() % 200) - 100, size, wonkyness, spikeyness, complexity);
        shapeCollection[i].setRotation(rand() % 360);
    }
}

void RenderingWindow::lineThickness(GeneratedShape *shapeCollection, int value, int amtOfShapes) {
    for(int i = 0; i < amtOfShapes; ++i) {
        shapeCollection[i].pen->setWidth(value);
        shapeCollection[i].update();
    }
}

void RenderingWindow::exportShapeButton() {
    QPixmap pixmap = ui->graphicsView->grab();
    pixmap.save("PixMap.png");
}

void RenderingWindow::on_LineThickSlider_valueChanged(int value) {
    lineThickness(bigShapes, value, amtOfBigShapes);
    lineThickness(mediumShapes, value, amtOfMediumShapes);
    lineThickness(smallShapes, value, amtOfSmallShapes);
}

void RenderingWindow::on_AggresivenessSmallSlider_valueChanged(int value) {
    spikeynessSmall = static_cast<double>(value * .005);
}

void RenderingWindow::on_ComplexitySmallSlider_valueChanged(int value) {
    complexitySmall = value;
}

void RenderingWindow::on_IrregularitySmallSlider_valueChanged(int value) {
    wonkynessSmall = static_cast<double>(value * .005);
}

void RenderingWindow::on_AggresivenessMediumSlider_valueChanged(int value) {
    spikeynessMedium = static_cast<double>(value * .005);
}

void RenderingWindow::on_ComplexityMediumSlider_valueChanged(int value) {
    complexityMedium = value;
}

void RenderingWindow::on_IrregularityMediumSlider_valueChanged(int value) {
    wonkynessMedium = static_cast<double>(value * .005);
}

void RenderingWindow::on_AggresivenessBigSlider_valueChanged(int value) {
    spikeynessBig = static_cast<double>(value * .005);
}

void RenderingWindow::on_ComplexityBigSlider_valueChanged(int value) {
    complexityBig = value;
}

void RenderingWindow::on_IrregularityBigSlider_valueChanged(int value) {
    wonkynessBig = static_cast<double>(value * .005);
}

RenderingWindow::~RenderingWindow() {
    delete ui;
    delete scene;
    delete bigShapes;
    delete mediumShapes;
    delete smallShapes;
}
