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

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    sliders = RenderingWindow::findChildren<QSlider*>();
    spinBoxes = RenderingWindow::findChildren<QSpinBox*>();

    shape = new GeneratedShape();
    scene->addItem(shape);
    connect(ui->generateButton, SIGNAL(released()), this, SLOT(generateShapeButton()));
    connect(ui->exportButton, SIGNAL(released()), this, SLOT(exportShapeButton()));
    connect(ui->randomizeButton, SIGNAL(released()), this, SLOT(randomizeShapeButton()));
}

void RenderingWindow::randomizeShapeButton() {
    for(int i = 0; i < sliders.length(); ++i) {
        sliders[i]->setValue(rand() % (sliders[i]->maximum() - sliders[i]->minimum() + 1) + sliders[i]->minimum());
    }
    for(int i = 0; i < spinBoxes.length(); ++i) {
        spinBoxes[i]->setValue(rand() % (spinBoxes[i]->maximum() - spinBoxes[i]->minimum() + 1) + spinBoxes[i]->minimum());
    }
}

void RenderingWindow::generateShapeButton() {
    scene->update();
    shape->generate();
}

void RenderingWindow::exportShapeButton() {
    QPixmap image(shape->boundingRect().size().toSize());
    image.fill(qRgba(255,255,255,0));
    QPainter painter(&image);
    QStyleOptionGraphicsItem opt;
    shape->paint(&painter, &opt);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                QDir::currentPath(),
                                tr("CloudPNG (*.png) ;; CloudJPG (*.jpg)"));
    image.save(fileName);
}

void RenderingWindow::on_LineThickSlider_valueChanged(int value) {
    shape->pen->setWidth(value);
    shape->update();
}
void RenderingWindow::on_AggresivenessSmallSlider_valueChanged(int value) {
    spikeynessSmall = static_cast<double>(value * .005);
}
void RenderingWindow::on_ComplexitySmallSlider_valueChanged(int value) {
    complexitySmall = value;
}
void RenderingWindow::on_AggresivenessMediumSlider_valueChanged(int value) {
    spikeynessMedium = static_cast<double>(value * .005);
}
void RenderingWindow::on_ComplexityMediumSlider_valueChanged(int value) {
    complexityMedium = value;
}
void RenderingWindow::on_AggresivenessBigSlider_valueChanged(int value) {
    spikeynessBig = static_cast<double>(value * .005);
}
void RenderingWindow::on_ComplexityBigSlider_valueChanged(int value) {
    complexityBig = value;
}
void RenderingWindow::on_CurvynessSmallSlider_valueChanged(int value) {
    curvynessSmall = value;
}
void RenderingWindow::on_CurvynessMediumlSlider_valueChanged(int value) {
    curvynessMedium = value;
}
void RenderingWindow::on_CurvynessBigSlider_valueChanged(int value) {
    curvynessBig = value;
}
void RenderingWindow::on_OuterMarginSlider_valueChanged(int value) {
    margin = 99-value;
}
void RenderingWindow::on_CenterOfBalanceSlider_valueChanged(int value) {
    pointOfBalance = value;
}
void RenderingWindow::on_AmountOfSmallShapes_valueChanged(int arg1) {
    amtOfSmallPolygons = arg1;
    shape->initPolygons();
}
void RenderingWindow::on_AmountOfMediumShapes_valueChanged(int arg1) {
    amtOfMediumPolygons = arg1;
    shape->initPolygons();
}
void RenderingWindow::on_AmountOfBigShapes_valueChanged(int arg1) {
    amtOfBigPolygons = arg1;
    shape->initPolygons();
}
void RenderingWindow::on_RadiusSmallSlider_valueChanged(int value) {
    radiusSmall = value;
}
void RenderingWindow::on_RadiusMediumSlider_valueChanged(int value) {
    radiusMedium = value;
}
void RenderingWindow::on_RadiusBigSlider_valueChanged(int value) {
    radiusBig = value;
}
void RenderingWindow::on_VerticalDiagonalSlider_valueChanged(int value) {
    angularness = value;
}

RenderingWindow::~RenderingWindow() {
    delete ui;
    delete shape;
}
