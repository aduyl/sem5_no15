#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
public:
    Scene();

private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
