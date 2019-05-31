#include "_include/renderingwindow.h"
#include "_include/backend.h"
#include <QApplication>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RenderingWindow w;
    w.show();

    return a.exec();
}
