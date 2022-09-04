
#include "mainwindow.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QColor>

#define SMOOTH 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->setScene(&scene);
    QImage inputImg(":/MainWindow/test.jpg");
#if SMOOTH
    float coef[5][5] =
        {
              { 0.002, 0.036, 0.048, 0.036,  0.002}
            , { 0.036, 0.057, 0.057, 0.057,  0.036}
            , { 0.048, 0.057, 0.057, 0.057,  0.048}
            , { 0.036, 0.057, 0.057, 0.057,  0.036}
            , { 0.002, 0.036, 0.048, 0.036,  0.002}
        };
#else
    float coef[5][5] =
        {
              { 0,  0,  0,  0,  0}
            , { 0, -1, -1, -1,  0}
            , { 0, -1,  8, -1,  0}
            , { 0, -1, -1, -1,  0}
            , { 0,  0,  0,  0,  0}
        };
#endif
    QImage rtnImg = this->convolution5x5(inputImg, coef);
    QGraphicsPixmapItem *image_item = new QGraphicsPixmapItem(QPixmap::fromImage(rtnImg));
    scene.addItem(image_item);
    ui.graphicsView->setScene(&scene);
}

void MainWindow::closeEvent(QCloseEvent* e)
{
}

void MainWindow::paintEvent(QPaintEvent *e)
{
}

QImage MainWindow::convolution5x5(QImage inputImg, float coef[5][5])
{
    QImage rtnImg(inputImg.width(), inputImg.height(), inputImg.format());

    for (int i = 0; i < inputImg.height(); i++)
    {
        for (int j = 0; j < inputImg.width(); j++)
        {
            float sumR = 0.0f;
            float sumG = 0.0f;
            float sumB = 0.0f;
            for (int m = -2; m < 2; m++)
            {
                for (int n = -2; n < 2; n++)
                {
                    if ((i + m >= 0) && (i + m <= inputImg.height() - 1)
                        && (j + n >= 0) && (j + n <= inputImg.width() - 1))
                    {
                        sumR += inputImg.pixelColor(j + n, i + m).red()   * coef[2 + m][2 + n];
                        sumG += inputImg.pixelColor(j + n, i + m).green() * coef[2 + m][2 + n];
                        sumB += inputImg.pixelColor(j + n, i + m).blue()  * coef[2 + m][2 + n];
                    }
                }
            }
            // red
            if (sumR < 0)
            {
                sumR = 0;
            }
            else if (sumR > 255)
            {
                sumR = 255;
            }
            // green
            if (sumG < 0)
            {
                sumG = 0;
            }
            else if (sumG > 255)
            {
                sumG = 255;
            }
            // blue
            if (sumB < 0)
            {
                sumB = 0;
            }
            else if (sumB > 255)
            {
                sumB = 255;
            }
            rtnImg.setPixel(j, i, qRgb(sumR, sumG, sumB));
        }
    }

    return rtnImg;
}

