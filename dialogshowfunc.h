#ifndef DIALOGSHOWFUNC_H
#define DIALOGSHOWFUNC_H

#include <QDialog>
#include "logicfunction.h"

namespace Ui {
class DialogShowFunc;
}

class DialogShowFunc : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowFunc(QString title, LogicFunction func, QWidget *parent = 0);
    ~DialogShowFunc();

private slots:
    void on_btnThanks_clicked();

private:
    Ui::DialogShowFunc *ui;
};

#endif // DIALOGSHOWFUNC_H
