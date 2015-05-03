#ifndef LOGICFUNCTION_H
#define LOGICFUNCTION_H

#include <QVector>
#include <QString>
#include <QDebug>

using std::ostream;

enum ExprType {
    MULT, SUMM, ATOM
};

class Expr
{
public:
    Expr();
    Expr(ExprType type, bool inverse = false, int var = 0);
    void print(QString &text);
    void addChild(Expr &expr);

private:
    ExprType type;
    QVector<Expr> childs;
    bool inverse;
    int var; // For ATOM type
};

class LogicFunction
{
public:
    LogicFunction(Expr *rootExpr);

    QString getText();

private:
    Expr *rootExpr;
};

#endif // LOGICFUNCTION_H
