#include "jumppole.h"

JumpPole::JumpPole(QWidget *parent):
    QWidget(parent), QGraphicsItem()
{
    this->setMouseTracking(true);
}

JumpPole::~JumpPole()
{

}

void JumpPole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(42, 94, 111));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            painter->drawRect(i * squareSize, j * squareSize, squareSize, squareSize);
        }
    }

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF JumpPole::boundingRect() const
{
    return QRectF(0, 0, 1000, 1000);
}

void JumpPole::reseveWidthAndHeith(int mParametr, int nParametr)
{
    m = mParametr;
    n = nParametr;
    squareSize = 800 / m;
}

//void JumpPole::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//        qDebug() << event->pos();
//}

//void JumpPole::mouseMoveEvent(QMouseEvent *event)
//{
//    qDebug() << 1;
//}

