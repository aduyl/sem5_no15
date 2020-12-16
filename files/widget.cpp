#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Косметическая подготовка приложения
    this->resize(1040,940);          // Устанавливаем размеры окна приложения
    this->setFixedSize(1040,940);


    pole = new JumpPole(this);
    scene = new Scene();   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов


    ui->graphicsView->resize(1040,940);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView


    // Включение обрабоки сигналов от мыши для graphicsView
    ui->graphicsView->setMouseTracking(true);



    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    scene->setSceneRect(0,0,1040,940); // Устанавливаем размер сцены

    pole->boundingRect();
    scene->addItem(pole);

    connect(pole, &JumpPole::isMoved, this, &Widget::slotFromScene);
}

Widget::~Widget()
{
    delete scene;
    delete ui;
}

void Widget::slotFromScene()
{
    qDebug() << "i'm here";
    if(isEnterPressed){
        counter++;
        item->setPos((counter) % m * squareSize, (((counter) / m) % n * squareSize));

    }

}

void Widget::on_mEdit_textChanged()
{
    QString from_inbox = ui->mEdit->text();

    if (from_inbox != ""){
        m = from_inbox.toInt(&isInt,10);
    }

    if (isInt && m > 0) {
        isIntSide = true;
    }else{
        isIntSide = false;
    }


    if (isIntSide && isIntBottom){
        ui->drawButton->setEnabled(true);

    } else {
        isIntBottom = false;
        ui->drawButton->setEnabled(false);
    }
}

void Widget::on_nEdit_textChanged()
{
    QString from_inbox = ui->nEdit->text();

    if (from_inbox != ""){
        n = from_inbox.toInt(&isIntSecond,10);
    }

    if (isIntSecond && n > 0) {
        isIntBottom = true;
    }else{
        isIntBottom = false;
    }


    if (isIntSide && isIntBottom){
        ui->drawButton->setEnabled(true);

    } else {
        isIntSide = false;
        ui->drawButton->setEnabled(false);
    }
}

void Widget::on_drawButton_clicked()
{
    squareSize = 800 / m;
    item->boundingRect();
    item->reseveWidthAndHeith(m);
    item->setPos((-1) * squareSize, ((-1)  * squareSize));

    pole->reseveWidthAndHeith(m, n);
//    scene->update();
    scene->addItem(pole);
    scene->addItem(item);
}

void Widget::on_reButton_clicked()
{
    ui->drawButton->setEnabled(false);
    scene->removeItem(pole);
    scene->removeItem(item);
    delete scene;
    scene = new Scene();
    ui->graphicsView->setScene(scene);

    ui->mEdit->clear();
    ui->nEdit->clear();
    counter = 0;
    m = -1;
    n = -1;


}


void Widget::keyPressEvent(QKeyEvent *event)
{

    if( event->key() == Qt::Key_Shift )
        {
            isEnterPressed = true;
        }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Shift ){
        isEnterPressed = false;
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(isEnterPressed){
        item->setPos((counter) % m * squareSize, (((counter) / m) % n * squareSize));
        counter++;
    }
    Q_UNUSED(event)
}
