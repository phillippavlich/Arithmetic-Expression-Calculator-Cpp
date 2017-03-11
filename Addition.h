/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description:A header file in order to link the Addition class
 */

#ifndef Addition_h// if Addition is not defined
#define Addition_h//define Addition

#include <string>//include string library
using namespace std;//using namespace to access std

class Addition{//creating class Addition
public://declaring public methods
    Addition();//creating constructor
    string evaluate(string &X, string &G);//declaring evaluate method
    void print(string &c, string &d);//declaring method

};//closing class

#endif /* Addition_h *///closing header file

