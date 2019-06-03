#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsItem>
#include <QPainter>

class Square : public QGraphicsItem
{
public:
    Square();
    ~Square();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится прямоугольник
                                     * */
    /* Определяем метод для отрисовки прямоугольника
     * */
};

class Programm : public QGraphicsItem
{
public:
    Programm();
    ~Programm();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QRectF boundingRect() const;
};

class Connector : public QGraphicsItem
{
public:
    Connector();
    ~Connector();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int id;

protected:
    QRectF boundingRect() const;
};

#endif // SQUARE_H
