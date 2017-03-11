#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H
#include <string>

class ArithmeticExpression
{
    public:
        ArithmeticExpression();
        string evaluate(string &X);

        virtual ~ArithmeticExpression();
    protected:
    private:
};

#endif // ARITHMETICEXPRESSION_H
