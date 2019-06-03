#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    squareOne.x = -200;
    squareOne.y = 200;

    squareTwo.x = -200;
    squareTwo.y = -200;


    progZero.x = -30;
    progZero.y = 0;

    progOne.x=30;
    progOne.y=0;

    progTwo.x=-220;
    progTwo.y=200;

    progThree.x=-180;
    progThree.y=-205;


    ui->setupUi(this);
    //this->resize(600,600);          // Задаем размеры виджета, то есть окна
    //this->setFixedSize(800,800);    // Фиксируем размеры виджета

    scene = new QGraphicsScene();   // Инициализируем графическую сцену

    square = new Square();        //инициализируем прямоугольник
    scene->addItem(square);   // Добавляем на сцену прямоугольник
    square->setPos(0,0);

    square1 = new Square();
    scene->addItem(square1);
    square1->setPos(-200,200);

    square2 = new Square();
    scene->addItem(square2);
    square2->setPos(-200,-200);

    prog = new Programm();  //нахождение: первый узел
    scene->addItem(prog);
    prog->setPos(-30, 0);

    prog1 = new Programm();  //нахождение: второй узел
    scene->addItem(prog1);
    prog1->setPos(-20+squareOne.x, squareOne.y);

    prog2 = new Programm();  //нахождение: первый узел
    scene->addItem(prog2);
    prog2->setPos(30, 0);

    prog3 = new Programm();   //нахождение: третий узел
    scene->addItem(prog3);
    prog3->setPos(20+squareTwo.x, -5+squareTwo.y);

    con = new Connector();   //нахождение: первая программа
    scene->addItem(con);
    con->setPos(-15+progZero.x, 0+progZero.y);
    con->id=10;

    con1 = new Connector();  //нахождение: третья программа
    scene->addItem(con1);
    con1->setPos(-15+progTwo.x, progTwo.y);
    con1->id=10;

    con2 = new Connector(); //нахождение: четвертая программа
    scene->addItem(con2);
    con2->setPos(15+progThree.x, 0+progThree.y);
    con2->id=5;

    con3 = new Connector();  //нахождение: первая программа
    scene->addItem(con3);
    con3->setPos(5+progZero.x,-15+progZero.y);
    con3->id=5;



    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    //scene->setSceneRect(-300,-300,600,600); // Устанавливаем область графической сцены


    if(con->id == con1->id){
        scene->addLine(-45,0,-235,200,QPen(Qt::blue));
    }

    if(con2->id == con3->id){
        scene->addLine(-25,-15,-165,-205,QPen(Qt::blue));
    }

    scene->addLine(-1000,0,1000,0,QPen(Qt::black));
    scene->addLine(0,-1000,0,1000,QPen(Qt::black));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rebuild_clicked(){
    squareOne.x = -200;
    squareOne.y = 200;
    squareTwo.x = -200;
    squareTwo.y = -200;
    progTwo.x=-220;
    progTwo.y=200;
    progThree.x=-180;
    progThree.y=-205;

    prog1->setPos(20+squareOne.x, squareOne.y);
    con1->setPos(55+progTwo.x, progTwo.y);

    prog3->setPos(-20+squareTwo.x, -5+squareTwo.y);
    con2->setPos(-55+progThree.x, progThree.y);

    if(con->id == con1->id){
        scene->addLine(-45,0,-235,-200,QPen(Qt::blue));
    }

    if(con2->id == con3->id){
        scene->addLine(-25,-15,-165,205,QPen(Qt::blue));
    }

    scene->addLine(-45,0,-235,200,QPen(Qt::white));
    scene->addLine(-25,-15,-165,-205,QPen(Qt::white));
}


