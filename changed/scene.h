#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
     Scene();

signals:
    void isMoved();

private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
