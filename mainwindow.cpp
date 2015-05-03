#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <math.h>
#include "spinboxdelegate.h"
#include "dialogshowfunc.h"
#include "funcinputvalidator.h"

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
    ui->lineEdit->setValidator(new FuncInputValidator());
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
    Expr *rootExpr = getFuncFromTable();
    QString title = QString(tr("ДДНФ"));
    DialogShowFunc *dial = new DialogShowFunc(title, rootExpr, this);
    dial->show();
}

// Кон’юнктивна довершена нормальна форма
void MainWindow::on_btn_DKNF_clicked()
{
    Expr *rootExpr = getFuncFromTable(1);
    QString title = QString(tr("ДКНФ"));
    DialogShowFunc *dial = new DialogShowFunc(title, rootExpr, this);
    dial->show();
}

/**
 * @brief MainWindow::getFuncFromTable
 * @param type 0 - DDNF, 1 - DKNF, default 0
 * @return logic function expression
 */
Expr *MainWindow::getFuncFromTable(int type)
{
    Expr *rootExpr = new Expr(type?MULT:SUMM);

    int v;
    for (int i = 0;i < table_rows;i++) {
        v = table->item(i, table_size)->text().toInt();
        if (v == 0 && type == 0) continue;
        else if (v == 1 && type == 1) continue;
        Expr *expr = new Expr(type?SUMM:MULT);
        for (int j = 0;j < table_size;j++) {
            v = table->item(i, j)->text().toInt();
            Expr *atomExpr = new Expr(ATOM, v ? (type?true:false) : (type?false:true), j + 1);
            expr->addChild(atomExpr);
        }
        rootExpr->addChild(expr);
    }

    return rootExpr;
}

/**
 * @brief MainWindow::getFuncFromText
 * @return parsed logic function expression with root expr type SUMM
 */
Expr *MainWindow::getFuncFromText()
{
    Expr *rootExpr = new Expr(SUMM);
    return rootExpr;
}

void MainWindow::on_btn_Nelson_clicked()
{
    Expr *rootExpr  = ui->radioButton_table->isChecked() ? getFuncFromTable() : getFuncFromText();
    QString title = QString(tr("СкДНФ з ДНФ"));
    DialogShowFunc *dial = new DialogShowFunc(title, rootExpr, this);
    dial->show();
}
