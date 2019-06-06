#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QXmlStreamReader>

#include <node.h>

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

    struct nodeCoordinates   // структура с координатами узлов
    {
        int x;
        int y;
    };

    struct progCoordinates   // структура с координатами программ
    {
        int x;
        int y;
        nodeCoordinates parent;
    };

    struct connCoordinates   // структура с координатами коннектеров
    {
        int x;
        int y;
        progCoordinates parent;
    };

    /*Объявление объектов для присваивания координат*/
    nodeCoordinates node_0;
    nodeCoordinates node_1;
    nodeCoordinates node_2;

    progCoordinates prog_0;
    progCoordinates prog_1;
    progCoordinates prog_2;
    progCoordinates prog_3;

    connCoordinates con_0;
    connCoordinates con_1;
    connCoordinates con_2;
    connCoordinates con_3;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_rebuild_clicked();

private:

};

#endif // MAINWINDOW_H
