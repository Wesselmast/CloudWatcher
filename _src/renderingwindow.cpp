#include "_include/renderingwindow.h"
#include "ui_renderingwindow.h"

RenderingWindow::RenderingWindow(QWidget *parent) : QWidget(parent) {
    qmlView = new QQuickWidget();
    qmlRegisterSingletonType<BackEnd>("cloudwatching.backend", 1, 0, "BackEnd", &BackEnd::create);
    qmlView->setSource(QUrl(QStringLiteral("qrc:/main.qml")));

    graphicsView = new QGraphicsView();
    scene = new QGraphicsScene(this);
    graphicsView->setScene(scene);
    graphicsView->setSceneRect(0,0,width,height);
    graphicsView->setMinimumSize(static_cast<int>(width), static_cast<int>(height));
    graphicsView->setMaximumSize(static_cast<int>(width), static_cast<int>(height));
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    shape = new GeneratedShape();
    scene->addItem(shape);

    QHBoxLayout* layout = new QHBoxLayout(this);
    this->setStyleSheet("background-color: #292929;");
    graphicsView->setStyleSheet("background-color: white;");
    qmlView->setMinimumSize(225, 1280);
    graphicsView->setAlignment(Qt::AlignCenter);

    layout->addWidget(qmlView);
    layout->addStretch();
    layout->addWidget(graphicsView);
    layout->addStretch();

    this->showMaximized();
    seed = rand();

    connect(&BackEnd::instance(), SIGNAL(generate_shape()), this, SLOT(generateShapeButton()));
    connect(&BackEnd::instance(), SIGNAL(export_shape()), this, SLOT(exportShapeButton()));
    generateShapeButton();
}

void RenderingWindow::keyPressEvent(QKeyEvent *key) {
    switch (key->key()) {
        case(Qt::Key::Key_Less): shape->doHorizontalFlip(); break;
        case(Qt::Key::Key_Greater): shape->doVerticalFlip(); break;
        case(Qt::Key::Key_Comma): shape->rotateShape(-90); break;
        case(Qt::Key::Key_Period): shape->rotateShape(90); break;
        case(Qt::Key::Key_Space): generateShapeButton(); break;
        case(Qt::Key::Key_R): /* TODO: Callback to QML to randomize */break;
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
    QImage image = graphicsView->grab().toImage();
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

RenderingWindow::~RenderingWindow() {
    delete shape;
    delete scene;
}
