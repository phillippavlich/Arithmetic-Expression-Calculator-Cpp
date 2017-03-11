/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description:Creating a cpp file in order to compute a subtraction from strings
 */

#include "Subtraction.h"//including a header for linking purposes
#include <iostream>//including a library
#include <string>//including a library
#include <cstdlib>//including a library
#include <sstream>//including a library

using namespace std;//calling namespace std in order to use std calls
Subtraction::Subtraction(){//creating a constructor for Subtraction
    string evaluate(string &a, string &b);//declaring a method called evaluate
};//closing class

string Subtraction::evaluate(string &a, string &b){

    float A=atof(a.c_str());//converting to float
    float B=atof(b.c_str());//converting to float
    float answer= A-B;//computing the subtraction
    stringstream ss;//declaring stringstream for conversions to string
    ss << answer;// passing variable in stringstream
    string myanswer=ss.str();//converting to string
    return myanswer;//returning a string

}//closing method

void Subtraction::print(string &c, string &d){//creating a print method
    cout << c << "-" << d << endl;//printing out the computation
}//closing method
