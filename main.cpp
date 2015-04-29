#include "mainwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <ui_mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*QTextEdit *textEdit = new QTextEdit("Text");
    QPushButton *btn = new QPushButton("Quit");
    QObject::connect(btn, SIGNAL(clicked()), qApp, SLOT(quit()));
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(textEdit);
    vbox->addWidget(btn);

    QWidget window;
    window.setLayout(vbox);

    window.show();*/

    return a.exec();
}
