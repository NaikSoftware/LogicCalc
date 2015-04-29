#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void update_table(int size = 3);

private slots:
    void on_btnPlus_clicked();

    void on_btnMinus_clicked();

private:
    Ui::MainWindow *ui;
    int tableSize;
};

#endif // MAINWINDOW_H
