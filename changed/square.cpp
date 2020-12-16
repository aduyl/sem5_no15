#include "square.h"

Square::Square(QObject *parent):
    QObject(parent), QGraphicsItem()
{

}


Square::~Square()
{

}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);

    int R_gb = qrand() % (255 + 1);
    int r_G_b = qrand() % (255 + 1);
    int rg_B = qrand() % (255 + 1);

    painter->setBrush(QColor(R_gb,r_G_b,rg_B));
    painter->drawRect(0,0, squareSize, squareSize);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
QRectF Square::boundingRect() const
{
    return QRectF(0, 0, squareSize, squareSize);
}

void Square::reseveWidthAndHeith(int mParametr)
{
    squareSize = 800 / mParametr;
}




