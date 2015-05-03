#ifndef FUNCINPUTVALIDATOR_H
#define FUNCINPUTVALIDATOR_H

#include <QObject>
#include <QValidator>

class FuncInputValidator : public QValidator
{
    Q_OBJECT
public:
    FuncInputValidator(QObject *parent = 0);
    QValidator::State validate(QString &input, int &pos) const;

    void fixup(QString & input) const;
};

#endif // FUNCINPUTVALIDATOR_H
