#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "spinboxdelegate.h"
#include "logicfunction.h"

#define MAX_TABLE_SIZE 6
#define MIN_TABLE_SIZE 2

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void update_table(int size = MIN_TABLE_SIZE);

private slots:
    void on_btnPlus_clicked();

    void on_btnMinus_clicked();

    void on_radioButton_table_toggled(bool checked);

    void on_btn_DDNF_clicked();

    Expr getFuncFromTable(int type = 0);

    void on_btn_DKNF_clicked();

private:
    Ui::MainWindow *ui;
    int table_size;
    int table_rows;
    int func_count;
    QTableWidget *table;
    SpinBoxDelegate *spinBoxDelegate;
};

#endif // MAINWINDOW_H
