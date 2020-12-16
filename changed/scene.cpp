#include "scene.h"


Scene::Scene()
{

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    isMoved();
    QGraphicsScene::mousePressEvent(event);

    //qDebug() << "Нажатия клавиш надо обрабатывать в Widget.cpp";
}
