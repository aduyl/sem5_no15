#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QKeyEvent>

#include "square.h"
#include "scene.h"
#include "jumppole.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Square *item= new Square;
    JumpPole *pole;

    bool isInt;
    bool isIntSecond;

    bool isIntSide = false;
    bool isIntBottom = false;

    bool isPushed = false;

    bool isEnterPressed = false;

    int squareSize = 0;

    int m = -1;
    int n = -1;
    int counter = 0;

private slots:
    /* Слот для обработки сигнала из точки */
    void slotFromScene();

    void on_mEdit_textChanged();

    void on_nEdit_textChanged();

    void on_drawButton_clicked();

    void on_reButton_clicked();
public slots:
    void keyPressEvent( QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::Widget *ui;
    Scene *scene;
};
#endif // WIDGET_H
