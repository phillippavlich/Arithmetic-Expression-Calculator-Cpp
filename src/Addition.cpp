#include "Addition.h"
#include "Expression.h"
#include "ArithmeticExpression.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;
class Addition : public ArithmeticExpression{
    string evaluate(Expression *left, Expression *right){
        float A=atof(*left.c_str());
        float B=atof(*right.c_str());
        float A=atof(a.c_str());
        float B=atof(b.c_str());
        float answer= A+B;
        stringstream ss;
        ss << answer;
        string myanswer=ss.str();
        return myanswer;
    }
};
Addition::~Addition()
{
    //dtor
}
