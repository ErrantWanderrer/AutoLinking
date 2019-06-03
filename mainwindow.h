#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QXmlStreamReader>

#include <square.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;

    QGraphicsScene  *scene;

    Square        *square;
    Square        *square1;
    Square        *square2;

    Programm     *prog;
    Programm     *prog1;
    Programm     *prog2;
    Programm     *prog3;

    Connector *con;
    Connector *con1;
    Connector *con2;
    Connector *con3;

    struct squareCoord
    {
        int x;
        int y;
    };

    struct progCoord
    {
        int x;
        int y;
    };

    squareCoord squareOne; //относительные координаты для программ
    squareCoord squareTwo;

    progCoord progZero;   //относительные координаты для коннекторов
    progCoord progOne;
    progCoord progTwo;
    progCoord progThree;


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_rebuild_clicked();

private:

         // Объявляем графическую сцену


};

#endif // MAINWINDOW_H
