/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: This is our header file for the Arithmetic expression class.
 *It allows the cpp file to be linked with other programs
 */

#ifndef ArithmeticExpression_h//if non existent define class
#define ArithmeticExpression_h//defines class

#include <string>//including string library
using namespace std;//allowing us to use std functions

class ArithmeticExpression{//creating Arithmetic Expression class
public://declaring public methods
    ArithmeticExpression();//construstor declared
    string evaluate(string &X);//declaring method
    void print(string &a);//declaring method
};//closing class


#endif /* ArithmeticExpression_h *///ending header file
