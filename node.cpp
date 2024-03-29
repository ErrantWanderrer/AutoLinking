#include "node.h"

Node::Node() :
    QGraphicsItem()
{
    node_0 = {0, 0};
    node_1 = {-200, 200};
    node_2 = {-200, -200};
}

Node::~Node()
{

}

Programm::Programm() :
    QGraphicsItem()
{
    node = new Node;
    prog_0 = {-30, 0, node->node_0};
    prog_1 = {-20+node->node_1.x, 0+node->node_1.y, node->node_1};
    prog_2 = {30, 0, node->node_0};
    prog_3 = {20+node->node_2.x, -5+node->node_2.y, node->node_2};
}

Programm::~Programm()
{

}

Connector::Connector()
{
    prog = new Programm;
    con_0 = {-15+prog->prog_0.x, 0+prog->prog_0.y, prog->prog_0};
    con_1 = {-15+prog->prog_1.x, 0+prog->prog_1.y, prog->prog_1};
    con_2 = {15+prog->prog_3.x, 0+prog->prog_3.y, prog->prog_3};
    con_3 = {5+prog->prog_0.x, -15+prog->prog_0.y, prog->prog_0};
}

Connector::~Connector()
{

}

QRectF Node::boundingRect() const
{
    return QRectF(-600,-600,600,600);   // Ограничиваем область, в которой лежит прямоугольник
}

QRectF Programm::boundingRect() const
{
    return QRectF(-600,-600,600,600);   // Ограничиваем область, в которой лежит прямоугольник
}

QRectF Connector::boundingRect() const
{
    return QRectF(-600,-600,600,600);   // Ограничиваем область, в которой лежит прямоугольник
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;   // Создаем ссылку на объект класса QPoligon
        // Помещаем координаты точек в полигональную модель
        polygon << QPoint(60,-45) << QPoint(60,45) << QPoint(-60,45) << QPoint(-60,-45);
        painter->setBrush(Qt::gray);     // Устанавливаем кисть, которой будем отрисовывать объект
        painter->drawPolygon(polygon);  // Рисуем прямоугольник по полигональной модели
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Programm::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon polygon;   // Создаем ссылку на объект класса QPoligon
    // Помещаем координаты точек в полигональную модель
    polygon << QPoint(15,-15) << QPoint(15,15) << QPoint(-15,15) << QPoint(-15,-15);
    painter->setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);  // Рисуем прямоугольник по полигональной модели
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Connector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon polygon;   // Создаем ссылку на объект класса QPoligon
    // Помещаем координаты точек в полигональную модель
    polygon << QPoint(5,-5) << QPoint(5,5) << QPoint(-5,5) << QPoint(-5,-5);
    painter->setBrush(Qt::blue);     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);  // Рисуем прямоугольник по полигональной модели
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
