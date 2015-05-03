#ifndef EXPR_H
#define EXPR_H

#include <QVector>
#include <QString>
#include <QDebug>

#define STR_MULT "·"
#define STR_SUMM "+"
#define STR_BRACKET_START "("
#define STR_BRACKET_END ")"

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
    void addChild(Expr *expr);
    ~Expr();

private:
    ExprType type;
    QVector<Expr*> childs;
    bool inverse;
    int var; // For ATOM type
};

#endif // EXPR_H
