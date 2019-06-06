#include "node.h"

Node::Node() :
    QGraphicsItem()
{

}

Node::~Node()
{

}

Programm::Programm() :
    QGraphicsItem()
{

}

Programm::~Programm()
{

}

Connector::Connector()
{

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
