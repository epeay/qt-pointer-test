#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* m_scrollTimer; // Declare the timer as a pointer

private slots:
    void onScrollTimerTimeout();

protected:
    void wheelEvent(QWheelEvent *event) override;
};
#endif // MAINWINDOW_H
