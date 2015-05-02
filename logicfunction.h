#ifndef LOGICFUNCTION_H
#define LOGICFUNCTION_H

#include <QVector>
#include <iostream>

using std::ostream;

class LogicFunction
{
public:
    LogicFunction();

    friend ostream& operator << (ostream &out, LogicFunction lfunc) {
        out << " test ";
        return out;
    }

private:
    QVector <int>vec;
};

#endif // LOGICFUNCTION_H
