#include "dialogshowfunc.h"
#include "ui_dialogshowfunc.h"
#include <QDebug>

DialogShowFunc::DialogShowFunc(QString &title, LogicFunction *func, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowFunc)
{
    ui->setupUi(this);
    ui->labelTitle->setText(title);
    ui->textBrowser->setText(func->getText());
    logicFunc = func;
}

DialogShowFunc::~DialogShowFunc()
{
    delete ui;
}

void DialogShowFunc::on_btnThanks_clicked()
{
    close();
}

void DialogShowFunc::on_DialogShowFunc_finished(int result)
{
    delete logicFunc;
}
