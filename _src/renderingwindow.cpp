#include "_include/renderingwindow.h"
#include "ui_renderingwindow.h"

RenderingWindow::RenderingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderingWindow)
{
        seed = rand() % SHRT_MAX;

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,750,750);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    sliders = RenderingWindow::findChildren<QSlider*>();

    shape = new GeneratedShape();
    scene->addItem(shape);
    connect(ui->generateButton, SIGNAL(released()), this, SLOT(generateShapeButton()));
    connect(ui->exportButton, SIGNAL(released()), this, SLOT(exportShapeButton()));
    connect(ui->randomizeButton, SIGNAL(released()), this, SLOT(randomizeShapeButton()));
    setGlobalsToSliders();
}

void RenderingWindow::setGlobalsToSliders() {
    on_primaryComplexitySlider_valueChanged(ui->primaryComplexitySlider->value());
    on_secondaryComplexitySlider_valueChanged(ui->secondaryComplexitySlider->value());
    on_negativeComplexitySlider_valueChanged(ui->negativeComplexitySlider->value());
    on_primaryRadiusSlider_valueChanged(ui->primaryRadiusSlider->value());
    on_secondaryRadiusSlider_valueChanged(ui->secondaryRadiusSlider->value());
    on_negativeRadiusSlider_valueChanged(ui->negativeRadiusSlider->value());
    on_secondaryEdgeSlider_valueChanged(ui->primaryEdgeSlider->value());
    on_secondaryEdgeSlider_valueChanged(ui->secondaryEdgeSlider->value());
    on_negativeEdgeSlider_valueChanged(ui->negativeEdgeSlider->value());
}

void RenderingWindow::keyPressEvent(QKeyEvent *key) {
    if(key->key() == Qt::Key::Key_Less) {
        shape->doHorizontalFlip();
    }
    else if(key->key() == Qt::Key::Key_Greater) {
        shape->doVerticalFlip();
    }
    else if(key->key() == Qt::Key::Key_Comma) {
        shape->rotateShape(-90);
    }
    else if(key->key() == Qt::Key::Key_Period) {
        shape->rotateShape(90);
    }
}

void RenderingWindow::randomizeShapeButton() {
    for(int i = 0; i < sliders.length(); ++i) {
        sliders[i]->setValue(rand() % (sliders[i]->maximum() - sliders[i]->minimum() + 1) + sliders[i]->minimum());
    }
}

void RenderingWindow::generateShapeButton() {
    seed = rand() % SHRT_MAX;
    scene->update();
    shape->transform().reset();
    shape->setRotation(0);
    shape->generate();
}

void RenderingWindow::exportShapeButton() {
    QImage image = ui->graphicsView->grab().toImage();
    image.fill(Qt::transparent);
    for(int x = 0; x < image.width(); ++x) {
        for(int y = 0; y < image.height(); ++y) {
            if(image.pixelColor(x,y) != Qt::white) continue;
            image.setPixelColor(x, y, Qt::transparent);
        }
    }
    QPainter painter(&image);
    QStyleOptionGraphicsItem opt;
    shape->paint(&painter, &opt);
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                QDir::currentPath(),
                                                tr("CloudPNG (*.png) ;; CloudJPG (*.jpg)"));
    if(path.isNull()) return;
    image.save(path);
}

void RenderingWindow::on_presetDropdown_currentIndexChanged(int index) {
    Q_UNUSED(index);
    /*
    if(index == 0) { //DEFAULT
        ui->SmallShapeComplexitySlider->setValue(50);
        ui->MediumShapeComplexitySlider->setValue(50);
        ui->BigShapeComplexitySlider->setValue(50);
        ui->ThicknessSlider->setValue(50);
        ui->VerticalDiagonalSlider->setValue(50);
        ui->CenterOfBalanceSlider->setValue(50);
        ui->SpacingSlider->setValue(50);
        setGlobalsToSliders();
    }
    else if (index == 1) { //STURDY AND STRONG
        ui->SpacingSlider->setValue(45);
        ui->CenterOfBalanceSlider->setValue(30);
        ui->VerticalDiagonalSlider->setValue(0);
        ui->ThicknessSlider->setValue(85);
        ui->BigShapeComplexitySlider->setValue(46);
        ui->MediumShapeComplexitySlider->setValue(48);
        ui->SmallShapeComplexitySlider->setValue(47);
        setGlobalsToSliders();
    }
    else if (index == 2) { //FAST AND AGGRESSIVE
        ui->SpacingSlider->setValue(55);
        ui->CenterOfBalanceSlider->setValue(95);
        ui->VerticalDiagonalSlider->setValue(93);
        ui->ThicknessSlider->setValue(15);
        ui->BigShapeComplexitySlider->setValue(80);
        ui->MediumShapeComplexitySlider->setValue(70);
        ui->SmallShapeComplexitySlider->setValue(75);
        setGlobalsToSliders();
    }
    */
}

RenderingWindow::~RenderingWindow() {
    delete ui;
    delete shape;
    delete scene;
}

void RenderingWindow::on_primaryComplexitySlider_valueChanged(int value) {
    primaryComplexity = qFloor(map(value, 0, 99, 7, 15));
    primarySpikeyness = map(value, 0, 99, 50, 80) * .006;
    generateShapeButton();
}

void RenderingWindow::on_primaryEdgeSlider_valueChanged(int value) {
    primaryCurvyness = qFloor(map(value, 0, 99, 1, 10));
    generateShapeButton();
}

void RenderingWindow::on_primaryRadiusSlider_valueChanged(int value) {
    primaryRadius = qFloor(map(value, 0, 99, 50, 100));
    generateShapeButton();
}

void RenderingWindow::on_secondaryComplexitySlider_valueChanged(int value) {
    secondaryComplexity = qFloor(map(value, 0, 99, 7, 15));
    secondarySpikeyness = map(value, 0, 99, 50, 80) * .006;
    generateShapeButton();
}

void RenderingWindow::on_secondaryEdgeSlider_valueChanged(int value) {
    secondaryCurvyness = qFloor(map(value, 0, 99, 1, 10));
    generateShapeButton();
}

void RenderingWindow::on_secondaryRadiusSlider_valueChanged(int value) {
    secondaryRadius = qFloor(map(value, 0, 99, 50, 100));
    generateShapeButton();
}

void RenderingWindow::on_negativeComplexitySlider_valueChanged(int value) {
    negativeComplexity = qFloor(map(value, 0, 99, 7, 15));
    negativeSpikeyness = map(value, 0, 99, 50, 80) * .006;
    generateShapeButton();
}

void RenderingWindow::on_negativeEdgeSlider_valueChanged(int value) {
    negativeCurvyness = qFloor(map(value, 0, 99, 1, 10));
    generateShapeButton();
}

void RenderingWindow::on_negativeRadiusSlider_valueChanged(int value) {
    negativeRadius = qFloor(map(value, 0, 99, 30, 70));
    generateShapeButton();
}
