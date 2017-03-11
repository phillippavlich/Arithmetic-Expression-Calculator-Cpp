/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description:cpp file that takes strings and performs an addition
 */

#include "Addition.h"//including header file
#include <iostream>//include library
#include <string>//include library
#include <cstdlib>//include library
#include <sstream>//include library

using namespace std;// using namespace to access std
Addition::Addition(){//creating class
    string evaluate(string &a, string &b);//declaring method
    void print(string &c, string &d);//declaring method
};//closing class

string Addition::evaluate(string &a, string &b){//creating method

    float A=atof(a.c_str());//convert to float
    float B=atof(b.c_str());//convert to float
    float answer= A+B;//computing addition
    stringstream ss;//creating string stream variable
    ss << answer;//passing variable in string stream
    string myanswer=ss.str();//convert to string
    return myanswer;//returning string

}//closing method

void Addition::print(string &c, string &d){//creating method
    cout << c << "+" << d << endl;//printing computation
}//closing method
