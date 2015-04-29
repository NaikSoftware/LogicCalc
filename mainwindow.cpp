#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QPushButton>
#include <QStringList>
#include <math.h>

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
    int len = pow(2, size);
    ui->labelSize->setText(QString::number(size));

    QStringList header;
    QTableWidget *table = ui->tableWidget;

    table->setRowCount(len);
    table->setColumnCount(size + 1);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    int n, m;
    for (int i = 1;i <= size;i++) {
        header << ("X" + QString::number(i));
        n = pow(2, (size - i));
        for (int j = 0;j < len;j++) {
            m = j / n;
            QTableWidgetItem *item = new QTableWidgetItem(m%2?"1":"0");
            table->setItem(j, i - 1, item);
        }
    }

    for (int i = 0;i < len;i++) {
        QTableWidgetItem *item = new QTableWidgetItem("0");
        table->setItem(i, size, item);
    }

    header << "f()";
    table->setHorizontalHeaderLabels(header);
    tableSize = size;
}
