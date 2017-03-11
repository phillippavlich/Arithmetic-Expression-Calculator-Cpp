/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description:Creating a header file to link the subtraction class to the rest.
 */

#ifndef Subtraction_h// if subtraction is not defined
#define Subtraction_h//define subtraction

#include <string>//including string library
using namespace std;//calling namespace std in order to used std in our coding

class Subtraction{//creating a class called Subtraction
public://declaring public methods
    Subtraction();//creating a constructor
    string evaluate(string &X, string &G);//declaring a method
    void print(string &c, string &d);//declaring a method

};//closig class

#endif /* Subtraction_h */// ending header file
