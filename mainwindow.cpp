#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWheelEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    m_scrollTimer = new QTimer(this);
    connect(m_scrollTimer, &QTimer::timeout, this, &MainWindow::onScrollTimerTimeout);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::wheelEvent(QWheelEvent *event)
{

    // The 100ms timer helps to split up the output and show each scroll action individually
    // Start or restart the timer when a scroll event is received
    if (!m_scrollTimer->isActive()) {
        m_scrollTimer->start(100); // 100 ms timeout
    } else {
        m_scrollTimer->setInterval(100);
    }


    QPoint numDegrees = event->angleDelta() / 8;
    QPoint numSteps = numDegrees / 15;
    int scrollAmount = event->delta();

    qDebug() << "Wheel event: numDegrees=" << numDegrees.x() << "," << numDegrees.y()
             << " numSteps=" << numSteps.x() << "," << numSteps.y()
             << " scrollAmount=" << scrollAmount;
    // ...
}


void MainWindow::onScrollTimerTimeout()
{
    // The timer has expired, which means scrolling has stopped
    m_scrollTimer->stop();

    // Handle the end of scrolling
    qDebug() << "Scrolling has stopped";
}


