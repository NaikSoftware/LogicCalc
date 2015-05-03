#include "expr.h"

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
}

void Expr::print(QString &text)
{
    if (inverse) text += "!";
    if (type == ATOM) {
        text += QString::number(var);
    } else {
        if (type == SUMM) text += STR_BRACKET_START;
        QString op(type == SUMM ? QString(" ") + STR_SUMM + " " : STR_MULT);
        for (int i = 0, len = childs.size();i < len;i++) {
            childs[i]->print(text);
            if (i < (len - 1)) text += op;
        }
        if (type == SUMM) text += STR_BRACKET_END;
    }
}

void Expr::addChild(Expr *expr)
{
    childs.append(expr);
}

Expr::~Expr()
{
    for (Expr *e : childs) delete e;
}


