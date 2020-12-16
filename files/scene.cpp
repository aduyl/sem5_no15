#include "scene.h"


Scene::Scene(QWidget *parent)
    : QWidget(parent)
{

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event->pos();
}
