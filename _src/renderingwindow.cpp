#include "_include/renderingwindow.h"
#include "ui_renderingwindow.h"

RenderingWindow::RenderingWindow(QWidget *parent) : QWidget(parent) {
    qmlRegisterSingletonType<BackEnd>("cloudwatching.backend", 1, 0, "BackEnd", &BackEnd::create);
    exportDir = QDir(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/CloudWatcher");

    qmlView = new QQuickWidget();
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



    QRegExp regex("Silhouette_\\d+");

    qDebug() << regex.exactMatch("Silhouette_17");

    QQuickWidget* shortcuts = new QQuickWidget();
    shortcuts->setSource(QUrl(QStringLiteral("qrc:/shortcuts.qml")));
    shortcuts->setMinimumSize(225, 1080);

    QHBoxLayout* layout = new QHBoxLayout(this);
    this->setStyleSheet("background-color: #292929;");
    graphicsView->setStyleSheet("background-color: white; border: transparent;");
    qmlView->setMinimumSize(225, 1080);
    graphicsView->setAlignment(Qt::AlignCenter);

    layout->addWidget(qmlView);
    layout->addStretch();
    layout->addWidget(graphicsView);
    layout->addStretch();
    layout->addWidget(shortcuts);

    this->showMaximized();

    connect(&BackEnd::instance(), SIGNAL(generate_shape()), this, SLOT(generateShapeButton()));
    connect(&BackEnd::instance(), &BackEnd::export_shape, this, [=]() { exportShape(); });
    generateShapeButton();
}

void RenderingWindow::keyPressEvent(QKeyEvent *key) {
    switch (key->key()) {
        case(Qt::Key::Key_Less): shape->doHorizontalFlip(); break;
        case(Qt::Key::Key_Greater): shape->doVerticalFlip(); break;
        case(Qt::Key::Key_Comma): shape->rotateShape(-90); break;
        case(Qt::Key::Key_Period): shape->rotateShape(90); break;
        case(Qt::Key::Key_Space): generateShapeButton(); break;
        case(Qt::Key::Key_R): {
            QQmlComponent component(qmlView->engine(), qmlView->source());
            QObject *qmlObj = component.create();
            QMetaObject::invokeMethod(qmlObj, "randomize");
            delete qmlObj;
            break;
        }
    }
    if(key->modifiers() & Qt::ControlModifier) {
        if(key->key() == Qt::Key::Key_S) {
            exportShape(true);
        }
    }
}

void RenderingWindow::generateShapeButton() {
    scene->update();
    shape->transform().reset();
    shape->setRotation(0);
    shape->generate();
}

void RenderingWindow::exportShape(bool doQuickExport) {
    QImage image = graphicsView->grab().toImage();
    QPainter painter(&image);
    QStyleOptionGraphicsItem opt;
    shape->paint(&painter, &opt);

    for(int x = 0; x < image.width(); ++x) {
        for(int y = 0; y < image.height(); ++y) {
            if(image.pixelColor(x,y) != Qt::white) continue;
            image.setPixelColor(x, y, Qt::transparent);
        }
    }

    if(!exportDir.exists()){
        exportDir.mkpath(".");
    }

    QString path;
    if(doQuickExport) {
        QStringList images = exportDir.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.png" << "*.PNG", QDir::Files);

        QString exportName = "Silhouette_";
        QRegExp regex("Silhouette_\\d+");

        for(auto &img : images) {
            if(regex.exactMatch(img.left(img.length()-4))) continue;
            images.removeOne(img);
        }

        QCollator collator;
        collator.setNumericMode(true);

        std::sort(images.begin(), images.end(),[&collator](const QString &img1, const QString &img2) {
            return collator.compare(img1, img2) < 0;
        });

        path = exportDir.path() + "/" + exportName + QString::number(images.length() + 1) + ".png";

        for(int i = 0; i < images.length(); ++i) {
            QString n1 = images[i].mid(exportName.length());
            n1 = n1.left(n1.length()-4);

            if(n1.toInt() == i+1) continue;
            path = exportDir.path() + "/" + exportName + QString::number(i+1) + ".png";
            break;
        }
    }
    else {
        path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                            exportDir.path(),
                                            tr("CloudPNG (*.png) ;; CloudJPG (*.jpg)"));
        if(path.isNull()) return;
    }
    image.save(path);
}

RenderingWindow::~RenderingWindow() {
    if(exportDir.isEmpty()) {
        exportDir.removeRecursively();
    }
    delete graphicsView;
    delete qmlView;
    delete shape;
    delete scene;
}
