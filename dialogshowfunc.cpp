#include "dialogshowfunc.h"
#include "ui_dialogshowfunc.h"
#include <QDebug>

DialogShowFunc::DialogShowFunc(QString &title, Expr *_rootExpr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowFunc),
    rootExpr(_rootExpr)
{
    ui->setupUi(this);
    ui->labelTitle->setText(title);
    QString text;
    rootExpr->print(text);
    ui->textBrowser->setText(text);
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
    delete rootExpr;
}
