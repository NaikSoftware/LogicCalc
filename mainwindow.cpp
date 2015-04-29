#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tableSize(0)
{
    ui->setupUi(this);
    update_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPlus_clicked()
{
    if (tableSize < 6) {
        update_table(tableSize + 1);
    }
}

void MainWindow::on_btnMinus_clicked()
{
    if (tableSize > 2) {
        update_table(tableSize - 1);
    }
}

void MainWindow::update_table(int size) {
    ui->labelSize->setText(QString::number(size));
    tableSize = size;
}
