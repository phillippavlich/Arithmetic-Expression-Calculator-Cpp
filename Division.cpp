/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description:cpp file that computes the division of two strings
 */

#include "Division.h"//include header file

#include <iostream>//include library
#include <string>//include library
#include <cstdlib>//include library
#include <sstream>//include library

using namespace std;//using namespace to access std
Division::Division(){//creating class called Division
    string evaluate(string &a, string &b);//declaring method called evaluate
    void print(string &c, string &d);//declaring method called print
};//closing class

string Division::evaluate(string &a, string &b){//creating method called evaluate

    float A=atof(a.c_str());//convert to float
    float B=atof(b.c_str());//convert to float
    float answer= A/B;//compute a division
    stringstream ss;//declaring a string stream for conversions
    ss << answer;//passing variable in stringstream
    string myanswer=ss.str();//convert to string
    return myanswer;//return string

}//closing method

void Division::print(string &c, string &d){//creating method called print
    cout << c << "/" << d << endl;//printing computation
}//closing method
