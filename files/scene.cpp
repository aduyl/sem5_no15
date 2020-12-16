#include "scene.h"

Scene::Scene()
{
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "Нажатия клавиш надо обрабатывать в Widget.cpp";
}
