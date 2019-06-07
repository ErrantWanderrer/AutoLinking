#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    /*определение координат объектов*/
    node_0 = {0, 0};
    node_1 = {-200, 200};
    node_2 = {-200, -200};

    prog_0 = {-30, 0, node_0};
    prog_1 = {-20+node_1.x, 0+node_1.y, node_1};
    prog_2 = {30, 0, node_0};
    prog_3 = {20+node_2.x, -5+node_2.y, node_2};

    con_0 = {-15+prog_0.x, 0+prog_0.y, prog_0};
    con_1 = {-15+prog_1.x, 0+prog_1.y, prog_1};
    con_2 = {15+prog_3.x, 0+prog_3.y, prog_3};
    con_3 = {5+prog_0.x, -15+prog_0.y, prog_0};


    /* Инициализация самих объектов */

    /* Узлы */
    node = new Node();
    scene->addItem(node);
    node->setPos(node_0.x, node_0.y);

    node1 = new Node();
    scene->addItem(node1);
    node1->setPos(node_1.x, node_1.y);

    node2 = new Node();
    scene->addItem(node2);
    node2->setPos(node_2.x, node_2.y);

    /* Программы */
    prog = new Programm();
    scene->addItem(prog);
    prog->setPos(prog_0.x, prog_0.y);

    prog1 = new Programm();
    scene->addItem(prog1);
    prog1->setPos(prog_1.x, prog_1.y);

    prog2 = new Programm();
    scene->addItem(prog2);
    prog2->setPos(prog_2.x, prog_2.y);

    prog3 = new Programm();
    scene->addItem(prog3);
    prog3->setPos(prog_3.x, prog_3.y);

    /* Коннекторы */
    con = new Connector();
    scene->addItem(con);
    con->setPos(con_0.x, con_0.y);
    con->id=10;

    con1 = new Connector();
    scene->addItem(con1);
    con1->setPos(con_1.x, con_1.y);
    con1->id=10;

    con2 = new Connector();
    scene->addItem(con2);
    con2->setPos(con_2.x, con_2.y);
    con2->id=5;

    con3 = new Connector();
    scene->addItem(con3);
    con3->setPos(con_3.x, con_3.y);
    con3->id=5;


    /* Ребра между коннекторами */

    if(con->id == con1->id){
        scene->addLine(con_0.x, con_0.y, con_1.x, con_1.y,QPen(Qt::blue));
    }
    if(con2->id == con3->id){
        scene->addLine(con_2.x, con_2.y, con_3.x, con_3.y,QPen(Qt::blue));
    }


    scene->addLine(-1000,0,1000,0,QPen(Qt::black));
    scene->addLine(0,-1000,0,1000,QPen(Qt::black));
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    //this->resize(600,600);          // Задаем размеры виджета, то есть окна
    //this->setFixedSize(800,800);    // Фиксируем размеры виджета
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали
    //scene->setSceneRect(-300,-300,600,600); // Устанавливаем область графической сцены
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rebuild_clicked(){
    prog1->setPos(prog_1.x, -prog_1.y);
    con1->setPos(con_1.x, -con_1.y);

    prog3->setPos(prog_3.x, -prog_3.y);
    con2->setPos(con_2.x, -con_2.y);

    if(con->id == con1->id){
        scene->addLine(con_0.x, con_0.y, con_1.x, -con_1.y,QPen(Qt::blue));
    }

    if(con2->id == con3->id){
        scene->addLine(con_2.x, -con_2.y,con_3.x, con_3.y,QPen(Qt::blue));
    }

    scene->addLine(-45,0,-235,200,QPen(Qt::white));
    scene->addLine(-25,-15,-165,-205,QPen(Qt::white));
}
