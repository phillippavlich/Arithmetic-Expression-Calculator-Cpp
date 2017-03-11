#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

class Expression
{
    public:
        Expression();
        virtual string evaluate();
        virtual void print();

        virtual ~Expression();
    protected:
    private:
};

#endif // EXPRESSION_H
