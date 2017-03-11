/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: This contains the main method, which takes in a string, and if he string is well formed, prints the expression and what the answer is.
 */
#include "ArithmeticExpression.h"   //including ArithmeticExpression header file
#include "Multiplication.h"         //including Multiplication header file
#include "Addition.h"               //including Addition header file
#include "Subtraction.h"            //including Subtraction header file
#include "Division.h"               //including Division header file
#include <iostream>                 //including iostream
#include <sstream>                  //including sstream
#include <cmath>                    //including cmath
#include <iomanip>                  //including iomapid
#include <cstdlib>                  //including cstdlib

using namespace std;                // using namespace std

string expressionToIncrement; //global string initilization
string addToNewString; //global string initialization
string tempString;  //global string initialization

/*
string increment(string theString){     //increment function, takes in a string and increments each number by 1

    int numCharacters = theString.size(); // setting numCharacters to the size of the string given
    int incrementedInteger; //initializing int
    string subString;       //initializign string
    int amtOfChar;          //initializing int


    for(int i=0; i<numCharacters; i++){  //for loop that runs numCharacters amount of times
        subString = theString.substr(i,1); // setting subString to the current character in the string

        if((subString=="(")||(subString==")")||(subString=="*")||(subString=="/")||(subString=="+")||(subString=="-")||(subString==" ")){ //if statement that runs if the substring is equal to any of these characters
            addToNewString += subString; //appending the character to addToNewString, which will in the end be the string with incremented values included
            amtOfChar++; // incrementing amtOfChar

        }//end if

        else{ //start else

            if(!(numCharacters==i+1)&&(!(theString.substr(i+1,1)=="(")&&!(theString.substr(i+1,1)==")")&&!(theString.substr(i+1,1)=="*")&&!(theString.substr(i+1,1)=="/")&&!(theString.substr(i+1,1)=="+")&&!(theString.substr(i+1,1)=="-")&&!(theString.substr(i+1,1)==" "))){ // if the next charcter is NOT equal to any of these characters, then that means the next character is a number, so we append it to tempString, which is used to hold the full number

                tempString += subString; // appending the character to tempString

            }//end if

            else{//start else, if next character isnt a number

                if((i>=2)&&(amtOfChar>=2)&&(theString.substr(i-tempString.size()-1, 1)=="-")&&(theString.substr(i-tempString.size()-2, 1)=="(")){ //if we're further on than the second character, and previous characters are equal to (-, follow through with code, this is exceuted if we're dealing with a negative number, ie. (-2) incremented goes to (-1)
                    tempString += subString; //append the character to tempString
                    stringstream(tempString) >> incrementedInteger; //converting string to an integer, storing it in incrementedInteger
                    incrementedInteger = abs((-1)*incrementedInteger+1); // incrementing a negative number integer

                    if(incrementedInteger==0){ // if the incremented integer is equal to 0
                        addToNewString.pop_back(); // get rid of the preceding negative sign so the answer isnt -0
                        addToNewString += to_string(incrementedInteger);//append this incremented integer to the addToNewString
                    }//end if
                    else{//if answer isnt equal to 0
                       addToNewString += to_string(incrementedInteger);//append stringed integer to addToNewString
                    }//end else


                }//end else

                else{//start else, runs if we're not dealign with a negative number
                    tempString += subString; //append the character
                    stringstream(tempString) >> incrementedInteger; //convert to integer
                    incrementedInteger = incrementedInteger+1; //increment integer
                    addToNewString += to_string(incrementedInteger); //revert to string and append
                }//end else

                tempString = "";//clear tempString




            }//end else
        }//end else

    }//end for loop

    expressionToIncrement = addToNewString; //expressionToIncrement is now equal to the new string with all numbers incremented
    addToNewString = "";//clear addToNewString
    amtOfChar = 0;//clear amount of character
    return expressionToIncrement;//return the incremented string
}//end of function

string removeSpaces(string input){ //function that takes in a string and removes the white spaces

    input.erase(remove(input.begin(),input.end(),' '),input.end());//erasign white spaces
    return input;//returns string with no white spaces
}//end of function
*/
int main() { //start of main where we take in the input and show the answer to the user

    string theExpression = ""; //initialize string
    string oldExpression;//initialize string
    string newIncrementedExpression;//initialize string
    string theirEquation;//initialize string
    string theirEquation1;//initialize string
    int counter = 0;//initialize int
    string errorChecker;//initialize string
    string subString1;//initialize string
    string errorNWF;//initialize string

    while(theirEquation!="#"){//while their expression is not equal to #

        cout << "Please enter an expression: ";//ask for input
        getline (cin,theExpression);//take in inpu regardless of if there

        //////////      CHECKING FOR THE ERROR WITH NUMBERS SEPERATED BY SPACES     //////////////////

        for(int it = 0; it<theExpression.size(); it++){//for loop that runs for the length of the string inputed

            errorChecker="keepGo";//setting the errorChecker to keepGo
            subString1 = theExpression.substr(it,1);//substrign is equal to the character we're at

            if(subString1=="1"||subString1=="2"||subString1=="3"||subString1=="4"||subString1=="5"||subString1=="6"||subString1=="7"||subString1=="8"||subString1=="9"||subString1=="0"){//if the substring is a number

                if(theExpression.substr(it+1,1)!=" "){//if the next character isnt a blank space there is no error

                    errorChecker = "noError";//set errorChecker to noError
                }//end if


                int subloc = it;//set subloc to the it we're at

                while((errorChecker=="keepGo")&&(subloc<=theExpression.size())){//while errorChecker is equal to keepGo and subloc is less than or equal to the length of the string



                    if (theExpression.substr(subloc+2, 1)==" "){//if the next character is a blank space we keep going
                        errorChecker = "keepGo";//set errorChecker to keepGo

                    }//end if

                    else if((theExpression.substr(subloc+2, 1)=="(")||(theExpression.substr(subloc+2, 1)=="+")||(theExpression.substr(subloc+2, 1)=="-")||(theExpression.substr(subloc+2, 1)=="*")||(theExpression.substr(subloc+2, 1)=="/")||(theExpression.substr(subloc+2, 1)==")")){ //else if the next expression is equal to an operator

                        errorChecker = "noError";//set errorChecker to noError and end while loop

                    }//end else if

                    else{//start else if the next character is a number after a bunch of spaces its an error
                        errorChecker = "errorFound";//set errorChecker to errorFound
                    }//end else

                    subloc++;//increment subloc
                }//end while

                if (errorChecker == "errorFound"){//if we found an error
                    break;//break
                }//end if


            }//end if

        }//end for loop



        ///// seeing if error with spaces between number is found ///////

        if(errorChecker=="errorFound"){//if an error was found
            errorNWF = "errorNWF";//set errorNWf to errorNWF -----> error not well formed
        }

        if(errorChecker!="errorfound"){//if no error is found
//            theExpression = removeSpaces(theExpression);//remove white spaces from the expression given

        }//end if

        theirEquation = theExpression;//set theirEquation to the expression without white spaces

        /////////// CHECKING FOR INVALID STARTING OR ENDING CHARACTER /////////////

        if((theirEquation.substr(0,1)==")")||(theirEquation.substr(0,1)=="+")||(theirEquation.substr(0,1)=="*")||(theirEquation.substr(0,1)=="-")||(theirEquation.substr(0,1)=="/")){//if the expression starts with an invalid operator
            errorNWF = "errorNWF";//set errorNWf to errorNWF
        }

        if((theirEquation.substr(theirEquation.size()-1,1)=="(")||(theirEquation.substr(theirEquation.size()-1,1)=="+")||(theirEquation.substr(theirEquation.size()-1,1)=="*")||(theirEquation.substr(theirEquation.size()-1,1)=="-")||(theirEquation.substr(theirEquation.size()-1,1)=="/")){
            errorNWF = "errorNWF";//set errorNWf to errorNWF
        }


        ////////// CHECKING FOR TWO OPERATORS BESIDE EACH OTHER AND EMPTY BRACKETS //////////

        for(int sign=0; sign<theirEquation.size()-1; sign++){//for looop that runs for the length of the expression given
            if((theirEquation.substr(sign,1)=="+")||(theirEquation.substr(sign,1)=="-")||(theirEquation.substr(sign,1)=="*")||(theirEquation.substr(sign,1)=="/")){//if substring is equal to an operation

                if((theirEquation.substr(sign+1,1)=="+")||(theirEquation.substr(sign+1,1)=="-")||(theirEquation.substr(sign+1,1)=="*")||(theirEquation.substr(sign+1,1)=="/")||(theirEquation.substr(sign+1,1)==")")){ //if the next character is equal to an operation

                    errorNWF = "errorNWF";//set errorNWf to errorNWF

                }//end if

            }//end if


            if(theirEquation.substr(sign,1)=="("){//if the character is equal to an open bracket
                if((theirEquation.substr(sign+1,1)==")")||(theirEquation.substr(sign+1,1)=="+")||(theirEquation.substr(sign+1,1)=="*")||(theirEquation.substr(sign+1,1)=="/")){//if the next character is one of these operation
                    errorNWF = "errorNWF";//set errorNWf to errorNWF
                }//end if

            }//end if

            if(theirEquation.substr(sign,1)==")"){//if the charcter is equal to a close bracket
                if((theirEquation.substr(sign+1,1)=="(")){//if the next bracket is equal to an open bracket
                    errorNWF = "errorNWF";//set errorNWf to errorNWF
                }//end if

            }//end if



        }//end for


        ////////    CHECKING FOR CORRECT AMOUNT OF BRACKETS     /////////

        int leftBrackets=0;//initalize amt of left brackets
        for(int i=0;i<theirEquation.size();i++){//runs for the length of the string
            if(theirEquation.substr(i,1)=="("){///if it encounters an open bracket
                leftBrackets++;//increment amt of left brackets
            }//end if
        }//end for


        int rightBrackets=0;//initialize right brackets
        for(int j=0;j<theirEquation.size();j++){//runs for length of the equation
            if(theirEquation.substr(j,1)==")"){//if it encounters a right bracket
                rightBrackets++;//increment right brackets
            }//end if
        }//end for

        if(leftBrackets!=rightBrackets){//if opening brackets aren't equal to closing brackets
            errorNWF = "errorNWF";//set errorNWf to errorNWF
        }//end if


        ///////// CHECKING FOR ANY OTHER INVALID INPUT ////////////

        string check;//initialize string
        if (theirEquation!="`@'"){//if expression given isnt equal to the increment characters
            for(int validity=0; validity<=theirEquation.size()-1; validity++){//rus for the size of the expression -1
                if((theirEquation.substr(validity,1)=="+")||(theirEquation.substr(validity,1)=="-")||(theirEquation.substr(validity,1)=="*")||(theirEquation.substr(validity,1)=="/")||(theirEquation.substr(validity,1)=="(")||(theirEquation.substr(validity,1)==")")||(theirEquation.substr(validity,1)=="0")||(theirEquation.substr(validity,1)=="1")||(theirEquation.substr(validity,1)=="2")||(theirEquation.substr(validity,1)=="3")||(theirEquation.substr(validity,1)=="4")||(theirEquation.substr(validity,1)=="5")||(theirEquation.substr(validity,1)=="6")||(theirEquation.substr(validity,1)=="7")||(theirEquation.substr(validity,1)=="8")||(theirEquation.substr(validity,1)=="9")||(theirEquation.substr(validity,1)==" ")){//checks for valid input

                    check = "okay";//we're okay

                }//end if

                if(check!="okay"){//of we're not okay, meaning invalid input was given

                    errorNWF = "errorNWF";//set errorNWf to errorNWF
                }//end if

                check = "";//clear check
            }//end for lloop
        }//end if

        if((errorNWF == "errorNWF")&&(theirEquation!="#")){//if there was any error
            cout << "\n" << "Expression is not well formed" << endl << endl; //print out error message
            counter = -1;//decrement the counter

        }//end if


        ///// checking for invalid calling on the incrementing function, ie nothing to increment //////

        if((counter==0)&&(theirEquation=="`@'")){//if the counter is equal to zero and their equation is the increment characters
            cout << "\n" << "Invalid Operator" << " `@' " << "as this expression! No vavlid previous expression to increment! " << endl << endl;//print out the error message that you cant increment
            counter = -1;//decremtn the counter

        }

        counter++; //incrementing counter


        if((errorNWF!= "errorNWF") && (theirEquation!="#") && (theirEquation!="`@'")){//if no error are found and not a special expression

            string *calculatedEquation;//initialize pointer
            calculatedEquation=&theExpression;//set pointer value
            ArithmeticExpression finalAnswer;//create an object of type ArithmeticExpression
            string preRoundedAnswer = finalAnswer.evaluate(*calculatedEquation);//evaluate the answer by calling upon evaluate
            float roundedAnswer= atof(preRoundedAnswer.c_str());//set answer to a float

            cout << "\n" << theirEquation << " = " << fixed << setprecision(2) << roundedAnswer << endl << endl;//print out the rounded answer
        }//end if
/*
        else if(!(counter==0)&&theirEquation=="`@'"){//if they want to increment and its valid to increment

            newIncrementedExpression = increment(oldExpression);//call on the function increment to increment the old expression
            theirEquation1 = newIncrementedExpression;//set their equation to the incremented expression

            string *calculatedEquation1;//initialize pointer
            calculatedEquation1=&newIncrementedExpression;//set pointer value
            ArithmeticExpression finalAnswer1;//create an object of ArithmeticExpression
            //string preRoundedAnswer1 = finalAnswer1.evaluate(*calculatedEquation1);//calculate the answer of the incremented expression
            float roundedAnswer1= atof(preRoundedAnswer1.c_str());//set answer to a float

            cout << "\n" << theirEquation1 << " = " << fixed << setprecision(2) << roundedAnswer1 << endl << endl;//round float to two decimal points

        }//end else if

        if(theirEquation!="`@'"){//if their equation isnt equa to the increment character expression
            oldExpression = theirEquation;//the old expression is the expression just used
        }//end if

        else if(!(counter==0)&&theirEquation=="`@'"){//else if the expression is the increment character expression and it was done validly
            oldExpression = expressionToIncrement;//the old expression is equal to the expression that was incremented
        }//end else if
*/
        errorNWF = "";//clear errors

    }//end while

    return 0;//return 0
}//end of main



