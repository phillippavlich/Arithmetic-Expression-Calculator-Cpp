//  Expression.cpp
/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: This is our base class that calls declares a virtual
 *function called evaluate.
 */

#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include "Division.h"
#include <string>

using namespace std;

class Expression{
    virtual string evaluate();

    virtual void print();

};
Expression::~Expression()
{
    //dtor
}
