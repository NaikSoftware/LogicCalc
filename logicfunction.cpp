#include "logicfunction.h"

LogicFunction::LogicFunction(Expr *_rootExpr)
    : rootExpr(_rootExpr)
{}

QString LogicFunction::getText() {
    QString text;
    rootExpr->print(text);
    return text;
}

Expr::Expr()
{
    // Default constructor (needed for QVector)
    qDebug() << "Expr default constructor";
}

Expr::Expr(ExprType _type, bool _inverse, int _var)
{
    type = _type;
    inverse = _inverse;
    var = _var;
    //qDebug() << "Expr standart constructor type=" << type
    //         << " inverse=" << inverse << " var=" << var;
}

void Expr::print(QString &text)
{
    if (inverse) text += "!";
    if (type == ATOM) {
        text += QString::number(var);
    } else {
        if (type == SUMM) text += "(";
        QString op(type == SUMM ? " + " : "·");
        for (int i = 0, len = childs.size();i < len;i++) {
            childs[i].print(text);
            if (i < (len - 1)) text += op;
        }
        if (type == SUMM) text += ")";
    }
}

void Expr::addChild(Expr &expr)
{
    childs.append(expr);
}


