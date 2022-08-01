
#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QtWidgets/QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindowClass ui;
    QGraphicsScene scene;

    QImage convolution5x5(QImage inputImg, float coef[5][5]);

protected:
    void closeEvent(QCloseEvent *e);
    void paintEvent(QPaintEvent *e);

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

};

#endif // MAIN_WINDOW_H_
