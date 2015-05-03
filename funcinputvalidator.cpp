#include "funcinputvalidator.h"
#include "logicfunction.h"

FuncInputValidator::FuncInputValidator(QObject *parent) :
    QValidator(parent)
{
}

QValidator::State FuncInputValidator::validate(QString &input, int &pos) const {
    if (pos > 0 && input[pos - 1] == '*') {
        input.remove(pos - 1, 1);
        input.insert(pos - 1, STR_MULT);
    }
    return State::Acceptable;
}

void FuncInputValidator::fixup(QString & input) const {
}

