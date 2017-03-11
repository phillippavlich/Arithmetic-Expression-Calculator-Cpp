#include "Division.h"
#include "Expression.h"
#include "ArithmeticExpression.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;
class Division : public ArithmeticExpression{
    string evaluate(Expression *left ,Expression *right){
        float A=atof(*left.c_str());
        float B=atof(*right.c_str());
        float answer= A/B;
        stringstream ss;
        ss << answer;
        string myanswer=ss.str();
        return myanswer;
    }
};
Division::~Division()
{
    //dtor
}
