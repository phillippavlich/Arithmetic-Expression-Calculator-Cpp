/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: Creating a header class for multiplication to link it to other files
 */

#ifndef Multiplication_h//if not defined, define it
#define Multiplication_h//defining Multiplication

#include <string>//include string library
using namespace std;//declaring usage of std library

class Multiplication{//initializing the class
public://declaring public methods
    Multiplication();//declaring constructor
    string evaluate(string &X, string &G);//declaring method
    void print(string &c, string &d);//declaring method
};//closing class

#endif /* Multiplication_h *///ending header file

