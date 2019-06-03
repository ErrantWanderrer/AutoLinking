#include "mainwindow.h"
#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //QString filename = QFileDialog::getOpenFileName(&w, "Choose file", ".", "*.xml");

    return a.exec();
}
