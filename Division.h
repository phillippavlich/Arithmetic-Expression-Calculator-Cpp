/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: A header file in order to link the division class
 */

#ifndef Division_h// if divison is not defined
#define Division_h// define division

#include <string>//include string library
using namespace std;//using namespace in order to access std

class Division{//creating class called Division
public://declaring public methods
    Division();//creating constructor
    string evaluate(string &X, string &G);//declaring method
    void print(string &c, string &d);//declaring method
};//closing class

#endif /* Division_h *///closing header file

