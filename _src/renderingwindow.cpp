#include "_include/renderingwindow.h"
#include "_include/ui_renderingwindow.h"

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
    setGlobalsToSliders();
}

void RenderingWindow::setGlobalsToSliders() {
    spikeynessSmall = static_cast<double>(ui->AggresivenessSmallSlider->value() * .005);
    complexitySmall = ui->ComplexitySmallSlider->value();
    spikeynessMedium = static_cast<double>(ui->AggresivenessMediumSlider->value() * .005);
    complexityMedium = ui->ComplexityMediumSlider->value();
    spikeynessBig = static_cast<double>(ui->AggresivenessBigSlider->value() * .005);
    complexityBig = ui->ComplexityBigSlider->value();
    margin = (99 - ui->OuterMarginSlider->value());
    pointOfBalance = ui->CenterOfBalanceSlider->value();
    curvynessSmall = ui->CurvynessSmallSlider->value();
    curvynessMedium = ui->CurvynessMediumlSlider->value();
    curvynessBig = ui->CurvynessBigSlider->value();
    radiusSmall = ui->RadiusSmallSlider->value();
    radiusMedium = ui->RadiusMediumSlider->value();
    radiusBig = ui->RadiusBigSlider->value();
    angularness = ui->VerticalDiagonalSlider->value();
}

void RenderingWindow::randomizeShapeButton() {
    for(int i = 0; i < sliders.length(); ++i) {
        sliders[i]->setValue(rand() % (sliders[i]->maximum() - sliders[i]->minimum() + 1) + sliders[i]->minimum());
    }
}

void RenderingWindow::generateShapeButton() {
    scene->update();
    shape->transform().reset();
    shape->setRotation(0);
    shape->generate();
}

void RenderingWindow::exportShapeButton() {
    QImage image(shape->boundingRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    QStyleOptionGraphicsItem opt;
    shape->paint(&painter, &opt);
    for(int x = 0; x < image.size().width(); ++x) {
        for(int y = 0; y < image.size().height(); ++y) {
            if(image.pixelColor(x, y) == Qt::white) {
                image.setPixelColor(x, y, Qt::transparent);
            }
        }
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                QDir::currentPath(),
                                tr("CloudPNG (*.png) ;; CloudJPG (*.jpg)"));
    image.save(fileName);
}


void RenderingWindow::on_presetDropdown_currentIndexChanged(int index) {
    if(index == 0) { //DEFAULT
        ui->RadiusSmallSlider->setValue(20);
        ui->AggresivenessSmallSlider->setValue(42);
        ui->CurvynessSmallSlider->setValue(5);
        ui->ComplexitySmallSlider->setValue(10);

        ui->RadiusMediumSlider->setValue(37);
        ui->AggresivenessMediumSlider->setValue(52);
        ui->CurvynessMediumlSlider->setValue(5);
        ui->ComplexityMediumSlider->setValue(16);

        ui->RadiusBigSlider->setValue(82);
        ui->AggresivenessBigSlider->setValue(57);
        ui->CurvynessBigSlider->setValue(5);
        ui->ComplexityBigSlider->setValue(16);

        ui->OuterMarginSlider->setValue(10);
        ui->CenterOfBalanceSlider->setValue(49);
        ui->VerticalDiagonalSlider->setValue(49);
        ui->LineThickSlider->setValue(8);

        setGlobalsToSliders();
    }
    else if (index == 1) { //STURDY AND STRONG
        ui->RadiusSmallSlider->setValue(19);
        ui->AggresivenessSmallSlider->setValue(42);
        ui->CurvynessSmallSlider->setValue(5);
        ui->ComplexitySmallSlider->setValue(7);

        ui->RadiusMediumSlider->setValue(75);
        ui->AggresivenessMediumSlider->setValue(52);
        ui->CurvynessMediumlSlider->setValue(10);
        ui->ComplexityMediumSlider->setValue(16);

        ui->RadiusBigSlider->setValue(165);
        ui->AggresivenessBigSlider->setValue(50);
        ui->CurvynessBigSlider->setValue(10);
        ui->ComplexityBigSlider->setValue(13);

        ui->OuterMarginSlider->setValue(10);
        ui->CenterOfBalanceSlider->setValue(10);
        ui->VerticalDiagonalSlider->setValue(0);
        ui->LineThickSlider->setValue(9);

        setGlobalsToSliders();
    }
    else if (index == 2) { //SMALL AND AGGRESSIVE
        ui->RadiusSmallSlider->setValue(18);
        ui->AggresivenessSmallSlider->setValue(55);
        ui->CurvynessSmallSlider->setValue(3);
        ui->ComplexitySmallSlider->setValue(10);

        ui->RadiusMediumSlider->setValue(33);
        ui->AggresivenessMediumSlider->setValue(60);
        ui->CurvynessMediumlSlider->setValue(1);
        ui->ComplexityMediumSlider->setValue(20);

        ui->RadiusBigSlider->setValue(72);
        ui->AggresivenessBigSlider->setValue(78);
        ui->CurvynessBigSlider->setValue(6);
        ui->ComplexityBigSlider->setValue(17);

        ui->OuterMarginSlider->setValue(0);
        ui->CenterOfBalanceSlider->setValue(99);
        ui->VerticalDiagonalSlider->setValue(99);
        ui->LineThickSlider->setValue(5);

        setGlobalsToSliders();
    }
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
}
void RenderingWindow::on_AmountOfMediumShapes_valueChanged(int arg1) {
    amtOfMediumPolygons = arg1;
}
void RenderingWindow::on_AmountOfBigShapes_valueChanged(int arg1) {
    amtOfBigPolygons = arg1;
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
