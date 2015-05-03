#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <math.h>
#include "spinboxdelegate.h"
#include "dialogshowfunc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    table_size(0),
    func_count(1)
{
    ui->setupUi(this);
    table = ui->tableWidget;
    //table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    spinBoxDelegate = new SpinBoxDelegate(0, 1);
    table->setItemDelegate(spinBoxDelegate);
    on_radioButton_table_toggled(true);
    update_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPlus_clicked()
{
    if (table_size < MAX_TABLE_SIZE) {
        update_table(table_size + 1);
    }
}

void MainWindow::on_btnMinus_clicked()
{
    if (table_size > MIN_TABLE_SIZE) {
        update_table(table_size - 1);
    }
}

void MainWindow::update_table(int size) {

    int rows = pow(2, size);
    ui->labelSize->setText(QString::number(size));
    QStringList header;
    table->setColumnCount(size + func_count);
    table->setRowCount(rows);

    int n, m;
    for (int i = 1;i <= size;i++) {
        header << ("X" + QString::number(i));
        n = pow(2, (size - i));
        for (int j = 0;j < rows;j++) {
            m = j / n;
            QTableWidgetItem *item = new QTableWidgetItem(m%2?"1":"0");
            table->setItem(j, i - 1, item);
            table->removeCellWidget(j, i - 1);
        }
    }

    for (int i = 0;i < rows;i++) {
        QTableWidgetItem *item = new QTableWidgetItem("0");
        table->setItem(i, size, item);
    }

    header << "f()";
    table->setHorizontalHeaderLabels(header);
    spinBoxDelegate->setEditColsAfter(size);
    table_size = size;
    table_rows = rows;
}

void MainWindow::on_radioButton_table_toggled(bool checked)
{
    ui->btn_BlakePor->setEnabled(!checked);
    ui->btn_DDNF->setEnabled(checked);
    ui->btn_DKNF->setEnabled(checked);

    /* Nelson available on table mode and input func mode.
     * In table mode - calc DDNF and use Nelson method */
}

// Диз’юнктивна довершена нормальна форма
void MainWindow::on_btn_DDNF_clicked()
{
    Expr rootExpr(SUMM);

    for (int i = 0;i < table_rows;i++) {
        if (table->item(i, table_size)->text().toInt() == 0) continue;
        Expr expr(MULT);
        for (int j = 0;j < table_size;j++) {
            Expr atomExpr(ATOM, table->item(i, j)->text().toInt() ? false : true, j + 1);
            expr.addChild(atomExpr);
        }
        rootExpr.addChild(expr);
    }

    LogicFunction func(&rootExpr);
    QString title = QString(tr("ДДНФ"));
    DialogShowFunc *dial = new DialogShowFunc(title, &func, this);
    dial->show();
}
