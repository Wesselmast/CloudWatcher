#include "renderingwindow.h"
#include "ui_renderingwindow.h"

RenderingWindow::RenderingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderingWindow)
{
    srand(time_t(NULL));
    ui->setupUi(this);
    spikeyness = 0;

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    for(int i = 0; i < 10; ++i) {
        GeneratedShape* shape = new GeneratedShape();
        shapes.push_back(shape);
        scene->addItem(shape);
    }

    connect(ui->generateButton, SIGNAL(released()), this, SLOT(generateShapeButton()));
}

void RenderingWindow::generateShapeButton() {
    for(int i = 0; i < shapes.length(); ++i) {
        shapes[i]->generate((rand() % 200) - 100, (rand() % 200) - 100, 55, .5, spikeyness, 25);
        shapes[i]->setRotation(rand() % 360);
    }
}

RenderingWindow::~RenderingWindow() {
    delete ui;
}

void RenderingWindow::on_verticalSlider_valueChanged(int value) {
    spikeyness = static_cast<double>(value * .005);
}
