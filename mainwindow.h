#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Counters;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Counters *m_counter;
};

#endif // MAINWINDOW_H
