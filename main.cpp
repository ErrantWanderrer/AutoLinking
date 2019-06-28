#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    File wnd;
    wnd.show();

    return a.exec();
}
