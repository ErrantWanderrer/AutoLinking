#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPainter>

class Node : public QGraphicsItem
{
public:
    Node();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    struct nodeCoordinates   // структура с координатами узлов
    {
        int x;
        int y;
    };
    nodeCoordinates node_0;
    nodeCoordinates node_1;
    nodeCoordinates node_2;
    ~Node();

protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                       который возвращает область, в которой
                                       находится прямоугольник*/

};

class Programm : public QGraphicsItem
{
public:
    Programm();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    struct progCoordinates   // структура с координатами программ
    {
        int x;
        int y;
        Node::nodeCoordinates parent;
    };
    progCoordinates prog_0;
    progCoordinates prog_1;
    progCoordinates prog_2;
    progCoordinates prog_3;
    Node *node;
    ~Programm();

protected:
    QRectF boundingRect() const;
};

class Connector : public QGraphicsItem
{
public:
    Connector();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    struct connCoordinates   // структура с координатами коннектеров
    {
        int x;
        int y;
        Programm::progCoordinates parent;
    };
    connCoordinates con_0;
    connCoordinates con_1;
    connCoordinates con_2;
    connCoordinates con_3;
    int id;
    Programm *prog;
    ~Connector();

protected:
    QRectF boundingRect() const;
};

#endif // NODE_H
