#ifndef JUMPPOLE_H
#define JUMPPOLE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QKeyEvent>

class JumpPole: public QWidget, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit JumpPole(QWidget *parent = nullptr);
    ~JumpPole();

    int m = 0;
    int n = 0;
    int squareSize = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



public slots:
    QRectF boundingRect() const;
    void reseveWidthAndHeith(int mParametr, int nParametr);



};

#endif // JUMPPOLE_H
