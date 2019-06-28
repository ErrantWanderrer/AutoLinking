#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    file = new File();

    /* Инициализация объектов */

    /* Узлы */

    node = new Node;
    if (file->check[0]==1){
        scene->addItem(node);
        node->setPos(node->node_0.x, node->node_0.y);
    }

    node1 = new Node();
    if (file->check[5]==1){
        scene->addItem(node1);
        node1->setPos(node->node_1.x, node->node_1.y);
    }

    node2 = new Node();
    if (file->check[8]==1){
        scene->addItem(node2);
        node2->setPos(node->node_2.x, node->node_2.y);
    }

    /* Программы */

    prog = new Programm();
    if ((file->check[1]==1)&&(file->check[0]==1)){
        scene->addItem(prog);
        prog->setPos(prog->prog_0.x, prog->prog_0.y);
    }

    prog1 = new Programm();
    if ((file->check[6]==1)&&(file->check[5]==1)){
        scene->addItem(prog1);
        prog1->setPos(prog->prog_1.x, prog->prog_1.y);
    }

    prog2 = new Programm();
    if ((file->check[4]==1)&&(file->check[0]==1)){
        scene->addItem(prog2);
        prog2->setPos(prog->prog_2.x, prog->prog_2.y);
    }

    prog3 = new Programm();
    if ((file->check[9]==1)&&(file->check[8]==1)){
        scene->addItem(prog3);
        prog3->setPos(prog->prog_3.x, prog->prog_3.y);
    }


    /* Коннекторы */

    con = new Connector();
    if ((file->check[2]==1)&&(file->check[1]==1)&&(file->check[0]==1)){
        scene->addItem(con);
        con->setPos(con->con_0.x, con->con_0.y);
    }
    con->id=10;

    con1 = new Connector();
    if ((file->check[7]==1)&&(file->check[6]==1)&&(file->check[5]==1)){
        scene->addItem(con1);
        con1->setPos(con->con_1.x, con->con_1.y);
    }
    con1->id=10;

    con2 = new Connector();
    if ((file->check[10]==1)&&(file->check[9]==1)&&(file->check[8]==1)){
        scene->addItem(con2);
        con2->setPos(con->con_2.x, con->con_2.y);
    }
    con2->id=5;

    con3 = new Connector();
    if ((file->check[3]==1)&&(file->check[1]==1)&&(file->check[0]==1)){
        scene->addItem(con3);
        con3->setPos(con->con_3.x, con->con_3.y);
    }
    con3->id=5;


    /* Связи между коннекторами */

    if((con->id == con1->id)&&(file->check[2]==1)&&(file->check[1]==1)&&(file->check[0]==1)&&(file->check[7]==1)&&(file->check[6]==1)&&(file->check[5]==1)){
        scene->addLine(con->con_0.x, con->con_0.y, con->con_1.x, con->con_1.y,QPen(Qt::blue));
    }
    if((con2->id == con3->id)&&(file->check[10]==1)&&(file->check[9]==1)&&(file->check[8]==1)&&(file->check[3]==1)&&(file->check[1]==1)&&(file->check[0]==1)){
        scene->addLine(con->con_2.x, con->con_2.y, con->con_3.x, con->con_3.y,QPen(Qt::blue));
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
    prog1->setPos(prog->prog_1.x, -prog->prog_1.y);
    con1->setPos(con->con_1.x, -con->con_1.y);

    prog3->setPos(prog->prog_3.x, -prog->prog_3.y);
    con2->setPos(con->con_2.x, -con->con_2.y);

    if((con->id == con1->id)&&(file->check[2]==1)&&(file->check[1]==1)&&(file->check[0]==1)&&(file->check[7]==1)&&(file->check[6]==1)&&(file->check[5]==1)){
        scene->addLine(con->con_0.x, con->con_0.y, con->con_1.x, -con->con_1.y,QPen(Qt::blue));
    }

    if((con2->id == con3->id)&&(file->check[10]==1)&&(file->check[9]==1)&&(file->check[8]==1)&&(file->check[3]==1)&&(file->check[1]==1)&&(file->check[0]==1)){
        scene->addLine(con->con_2.x, -con->con_2.y,con->con_3.x, con->con_3.y,QPen(Qt::blue));
    }

    scene->addLine(-45,0,-235,200,QPen(Qt::white));
    scene->addLine(-25,-15,-165,-205,QPen(Qt::white));
}
