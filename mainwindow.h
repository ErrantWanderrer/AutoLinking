#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QXmlStreamReader>

#include "node.h"
#include "file.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;

    QGraphicsScene  *scene;

    Node        *node;
    Node        *node1;
    Node        *node2;

    Programm     *prog;
    Programm     *prog1;
    Programm     *prog2;
    Programm     *prog3;

    Connector *con;
    Connector *con1;
    Connector *con2;
    Connector *con3;

    File *file;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_rebuild_clicked();

private:

};

#endif // MAINWINDOW_H

