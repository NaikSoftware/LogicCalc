#include "dialogshowfunc.h"
#include "ui_dialogshowfunc.h"

DialogShowFunc::DialogShowFunc(QString title, LogicFunction func, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowFunc)
{
    ui->setupUi(this);
    ui->labelTitle->setText(title);
}

DialogShowFunc::~DialogShowFunc()
{
    delete ui;
}

void DialogShowFunc::on_btnThanks_clicked()
{
    close();
}
