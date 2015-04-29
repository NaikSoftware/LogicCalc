#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define INIT_TABLE_SIZE 2

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

    void update_table(int size = INIT_TABLE_SIZE);

private slots:
    void on_btnPlus_clicked();

    void on_btnMinus_clicked();

private:
    Ui::MainWindow *ui;
    int tableSize;
};

#endif // MAINWINDOW_H
