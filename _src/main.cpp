#include "_include/renderingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RenderingWindow w;
    w.show();

    return a.exec();
}
