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
}

void RenderingWindow::generateShapeButton() {
    shape->generate(wonkynessSmall, spikeynessSmall, complexitySmall,
                    wonkynessMedium, spikeynessMedium, complexityMedium,
                    wonkynessBig, spikeynessBig, complexityBig);
}

void RenderingWindow::exportShapeButton() {
    QImage image(shape->boundingRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(qRgba(255,255,255,0));
    QPainter painter(&image);
    QStyleOptionGraphicsItem opt;
    shape->paint(&painter, &opt);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                QDir::currentPath(),
                                tr("All File (*.*) ;; CloudPNG (*.png) ;; CloudJPG (*.jpg)"));
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
    delete shape;
}
