#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QWidget, public QGraphicsScene
{
public:
    Scene(QWidget *parent = nullptr);

private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
