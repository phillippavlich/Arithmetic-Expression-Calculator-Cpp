/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: Allowing 2 strings to be multiplied together
 */

#include "Multiplication.h"//including header file

#include <iostream>//including library
#include <string>//including library
#include <cstdlib>//including library
#include <sstream>//including library

using namespace std;//declaring std for future use
Multiplication::Multiplication(){//creating class called Multiplication
    string evaluate(string &a, string &b);//declaring method evaluate

};//closing class

string Multiplication::evaluate(string &a, string &b){//initializing the method evaluate

    float A=atof(a.c_str());//converting string to float
    float B=atof(b.c_str());//converting string to float
    float answer= A*B;// computing multiplication
    stringstream ss;// creating a variable from string stream
    ss << answer;// passing it with the computed answer
    string myanswer=ss.str();//converting the float back to a string
    return myanswer;//returning a string

}//closing the method

void Multiplication::print(string &c, string &d){//initializing a print method
    cout << c << "*" << d << endl;//printing out the computation
}//closing method
