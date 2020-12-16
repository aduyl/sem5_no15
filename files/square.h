#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QKeyEvent>

class Square: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Square(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    ~Square();
    int squareSize = 0;
    int squarePositionX = 0;
    int squarePositionY = 0;


    bool isShift = false;

    int m = 0;
    int n = 0;



public slots:
    QRectF boundingRect() const;
    void reseveWidthAndHeith(int mParametr);


};

#endif // SQUARE_H
