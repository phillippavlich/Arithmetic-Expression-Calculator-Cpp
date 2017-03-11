/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: Creating a class called ArithmeticExpression in order to compute an equation
 */



#include <iostream>//importing library
#include <string>//importing library
#include <cstdlib>//importing library
#include <sstream>//importing library
#include <iomanip>//importing library
#include "ArithmeticExpression.h"	//Includes a header file.
#include "Multiplication.h"	//Includes a header file.
#include "Addition.h"	//Includes a header file.
#include "Subtraction.h"	//Includes a header file.
#include "Division.h"	//Includes a header file.

using namespace std;	// Uses the std namespace.

ArithmeticExpression::ArithmeticExpression(){	// Creates the ArithmeticExpression class.
    string evaluate(string &X);	// Initializes the evaluate method.
    void print(string &X);	// Initializes the print method.
}	// Ends the ArithmeticExpression class.

void ArithmeticExpression::print(string &a){	// print method, displays the calculation.
    cout << a << endl;	//Prints a.
}	// End of calculation method.
string ArithmeticExpression::evaluate(string &X){	// evaluate method, takes in the user entered string and computes it using pointers.
    string *left;	// Creates the pointer for the left side.
    string *right;	// Creates the pointer for the right side.
    int brackets=0;	// Sets the value of the integer.
    for(int i=0;i<X.size();i++){	//Begin for loop block.
        if(X.substr(i,1)=="("){	// If condition block.
            brackets++;	// Increments the variable everytime a '(' symbol is found.
        }	// End of condition.
    }	// End for loop block.

    if(brackets!=0){	// If condition block.
        int brackets1=0;	// Sets the value of the integer.
        for(int j=0;j<X.size();j++){	//Begin for loop block.
            if(X.substr(j,1)=="("){	// If condition block.
                brackets1=j;	// Sets the index for where the symbol '(' is found.
            }	// End of condition.
        }	// End for loop block.
        int brackets2=0;	// Sets the value of the integer.
        bool first=true;	// Sets the value of the boolean variable.
        for(int f=brackets1;f<X.size();f++){	//Begin for loop block.
            if((X.substr(f,1)==")") && (first)){	// If condition block.
                brackets2=f;	// Sets the index for where the symbol ')' is found.
                first=false;	// Sets the value of the boolean variable.
            }	// End of condition.
        }	// End for loop block.
        int size2 = brackets2-(brackets1+1);	// Sets the value of the integer.
        string temp=X.substr(brackets1+1,size2);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.



        bool found=false;	// Initializes the boolean.
        while(!found){	// Begin while loop block.
            found=true;	// Sets the value of the boolean variable.
            int accum2=0;	// Sets the value of the integer.


            for(int r=0;r<temp.size();r++){	//Begin for loop block.
                if((((temp.substr(r,1)).compare("*")==0) || ((temp.substr(r,1)).compare("/")==0))&& found){	// If condition block.
                    accum2=r;	// Sets the index for where the symbol '*' or '/' is found.
                    found=false;	// Sets the value of the boolean variable.
                }	// End of condition.
            }	// End for loop block.


            if(found==false){	// If condition block.
                int accum3=0;	// Sets the value of the integer.
                int accum4=temp.size();	// Sets the value of the integer.

                for(int y=1;y<accum2;y++){	//Begin for loop block.
                    if(((temp.substr(y,1)).compare("+")==0) || ((temp.substr(y,1)).compare("-")==0) || ((temp.substr(y,1)).compare("*")==0) || ((temp.substr(y,1)).compare("/")==0)){	// If condition block.
                        accum3=y+1; // Sets the index for where the symbol '*' or '/' or '+' or '-' is found.
                    }	// End of condition.
                }	// End for loop block.
                int size1= accum2-accum3;	// Sets the value of the integer.
                string AA=temp.substr(accum3,size1);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

                left = &AA;	// Sets the pointer to an address of a variable.
                bool fix=true;	// Sets the value of the boolean variable.
                for(int z=accum2+2;z<temp.size();z++){	//Begin for loop block.
                    if((((temp.substr(z,1)).compare("+")==0) || ((temp.substr(z,1)).compare("-")==0) || ((temp.substr(z,1)).compare("*")==0) || ((temp.substr(z,1)).compare("/")==0))&&fix){	// If condition block.
                        accum4=z;	// Sets the index for where the symbol '+' or '-' or '*' or '/' is found.
                        fix=false;	// Sets the value of the boolean variable.
                    }	// End of condition.
                }	// End for loop block.

                int size= accum4-(accum2+1);	// Sets the value of the integer.

                string AB=temp.substr(accum2+1,size);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.


                right= &AB;	// Sets the pointer to an address of a variable.

                if(((temp.substr(accum2,1)).compare("*")==0)){	// If condition block.


                    Multiplication myMultiplication;
                    string newvalue = myMultiplication.evaluate(*left, *right);

                    int Length10= temp.size()-accum4;	// Sets the value of the integer.
                    int Length9=accum3-0;	// Sets the value of the integer.
                    temp=temp.substr(0,Length9)+newvalue+temp.substr(accum4,Length10);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

                }	// End of condition.

                else if(((temp.substr(accum2,1)).compare("/")==0)){	// Else if condition.
                    Division myDivision;
                    string newvalue = myDivision.evaluate(*left, *right);
                    int Length10= temp.size()-accum4;	// Sets the value of the integer.
                    int Length9=accum3-0;	// Sets the value of the integer.
                    temp=temp.substr(0,Length9)+newvalue+temp.substr(accum4,Length10);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

                }	// End of condition.


            }	// End of condition.
        }	// End while loop block.
        //down here dealing with adding/sub

        bool found1=false;	// Sets the value of the boolean variable.
        while(!found1){	// Begin while loop block.
            found1=true;	// Sets the value of the boolean variable.
            int Accum2=0;	// Sets the value of the integer.
            if (temp.size()>1){//checking if size is greater than 1
                for (int h=0; h<(temp.size()-1);h++){//initialize for loop
                    if (temp.substr(h,2)=="--"){//checking for double negative signs
                        temp=temp.substr(0,h)+"+"+temp.substr(h+2, temp.size()-(h+2));//fixing double negative to +
                    }//closing if statement
                }//closing for loop
            }//closing if statement

            for(int r=1;r<temp.size();r++){	//Begin for loop block.
                if((((temp.substr(r,1)).compare("+")==0) || ((temp.substr(r,1)).compare("-")==0)) && found1){	// If condition block.
                    Accum2=r;	// Sets the index for where the symbol '+' or '-' is found.
                    found1=false;	// Sets the value of the boolean variable.
                }	// End of condition.
            }	// End for loop block.
            if(found1==false){	// If condition block.
                int Accum3=0;	// Sets the value of the integer.
                int Accum4=temp.size();	// Sets the value of the integer.


                for(int y=1;y<Accum2;y++){	//Begin for loop block.
                    if(((temp.substr(y,1)).compare("+")==0) || ((temp.substr(y,1)).compare("-")==0) || ((temp.substr(y,1)).compare("*")==0) || ((temp.substr(y,1)).compare("/")==0)){	// If condition block.
                        Accum3=y+1;	// Sets the index for where the symbol '+' or '-' or '*' or '/' is found.
                    }	// End of condition.
                }	// End for loop block.

                int Length6=Accum2-Accum3;	// Sets the value of the integer.
                string AC=temp.substr(Accum3,Length6);

                left=&AC;
                bool fix1=true;	// Sets the value of the boolean variable.
                for(int z=Accum2+1;z<temp.size();z++){	//Begin for loop block.
                    if((temp.substr(z,1)=="+" || temp.substr(z,1)=="-" || temp.substr(z,1)=="*" || temp.substr(z,1)=="/")&&fix1){	// If condition block.
                        Accum4=z;	// Sets the index for where the symbol '+' or '-' or '*' or '/' is found.
                        fix1=false;	// Sets the value of the boolean variable.
                    }	// End of condition.
                }	// End for loop block.


                int Length5=Accum4-(Accum2+1);	// Sets the value of the integer.
                string AD=temp.substr(Accum2+1,Length5);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

                right=&AD;	// Sets the pointer to an address of a variable.

                if(temp.substr(Accum2,1)=="+"){	// If condition block.
                    Addition myAddition;//creating an object
                    string newvalue1 = myAddition.evaluate(*left, *right);//calling a method with pointers
                    int Length3= Accum3-0;	// Sets the value of the integer.
                    int Length4=temp.size()-Accum4;	// Sets the value of the integer.
                    temp=temp.substr(0,Length3)+newvalue1+temp.substr(Accum4,Length4);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

                }	// End of condition.

                else if(temp.substr(Accum2,1)=="-"){// checking for a subtraction
                    Subtraction mySubtraction;//creating an object
                    string newvalue1 = mySubtraction.evaluate(*left, *right);//calling a method with pointers
                    int Length3= Accum3-0;	// Sets the value of the integer.
                    int Length4=temp.size()-Accum4;	// Sets the value of the integer.
                    temp=temp.substr(0,Length3)+newvalue1+temp.substr(Accum4,Length4);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

                }	// End of condition.

            }	// End of condition.

        }	// End while loop block.
        /////addd temp back to X create new x
        int Length1= brackets1-0;	// Sets the value of the integer.
        int Length2=X.size()-(brackets2+1);	// Sets the value of the integer.
        X=X.substr(0,Length1)+temp+X.substr(brackets2+1,Length2);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

    }	// End of condition.

    else{	// Else if condition for if there are no more brackets.
        bool Found=false;	// Sets the value of the boolean variable.
        while(!Found){	// Begin while loop block.
            Found=true;	// Sets the value of the boolean variable.
            int accume2=0;	// Sets the value of the integer.
            for(int r=0;r<X.size();r++){	//Begin for loop block.
                if((X.substr(r,1)=="*" || X.substr(r,1)=="/") && Found){	// If condition block.
                    accume2=r;	// Sets the index for where the symbol '*' or '/' is found.
                    Found=false;	// Sets the value of the boolean variable.
                }	// End of condition.
            }	// End for loop block.
            if(Found==false){	// If condition block.
                int accume3=0;	// Sets the value of the integer.
                int accume4=X.size();	// Sets the value of the integer.

                for(int y=1;y<accume2;y++){	//Begin for loop block.
                    if(X.substr(y,1)=="+" || X.substr(y,1)=="-" || X.substr(y,1)=="*" || X.substr(y,1)=="/"){//checking for an operation
                        accume3=y+1;	// Sets the index for where the symbol '+' or '-' or '*' or '/' is found.
                    }	// End of condition.
                }	// End for loop block.
                int len8=accume2-accume3;	// Sets the value of the integer.

                string AE=X.substr(accume3,len8);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.
                left=&AE;	// Sets the pointer to an address of a variable.

                bool fix2=true;	// Sets the value of the boolean variable.
                for(int z=accume2+2;z<X.size();z++){	//Begin for loop block.
                    if((X.substr(z,1)=="+" || X.substr(z,1)=="-" || X.substr(z,1)=="*" || X.substr(z,1)=="/")&&fix2){	// If condition block.
                        accume4=z;	// Sets the index for where the symbol '+' or '-' or '*' or '/' is found.
                        fix2=false;	// Sets the value of the boolean variable.
                    }	// End of condition.
                }	// End for loop block.
                int len7=accume4-(accume2+1);	// Sets the value of the integer.

                string AF=X.substr(accume2+1,len7);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.
                right = &AF;	// Sets the pointer to an address of a variable.

                if(X.substr(accume2,1)=="*"){	// If condition block.
                    Multiplication myMultiplication;//creating an object
                    string Newvalue = myMultiplication.evaluate(*left, *right);//calling a method with pointers

                    int len5=accume3-0;	// Sets the value of the integer.
                    int len6=X.size()-accume4;	// Sets the value of the integer.
                    X=X.substr(0,len5)+Newvalue+X.substr(accume4,len6);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.
                }	// End of condition.

                else if(X.substr(accume2,1)=="/"){	// Else if condition block.
                    Division myDivision;//creating an object
                    string Newvalue = myDivision.evaluate(*left, *right);//calling a method with pointers

                    int len5=accume3-0;	// Sets the value of the integer.
                    int len6=X.size()-accume4;	// Sets the value of the integer.
                    X=X.substr(0,len5)+Newvalue+X.substr(accume4,len6);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.
                }	// End of condition.


            }	// End of condition.
        }	// End while loop block.
        //down here dealing with adding/sub

        bool Found1=false;	// Sets the value of the boolean variable.
        while(!Found1){	// Begin while loop block.
            Found1=true;	// Sets the value of the boolean variable.
            int Accume2=0;	// Sets the value of the integer.
            if (X.size()>1){//checking is size is greater than 1
                for (int h=0; h<(X.size()-1);h++){//for loop to iterate through our temp
                    if (X.substr(h,2)=="--"){//checking for double negative signs
                        X=X.substr(0,h)+"+"+X.substr(h+2,X.size()-(h+2));//changing the double negative to a + sign
                    }//closing if statement
                }//closing for loop
            }//closing if statement

            for(int r=1;r<X.size();r++){	//Begin for loop block.
                if((X.substr(r,1)=="+" || X.substr(r,1)=="-") && Found1){	// If condition block.
                    Accume2=r;	// Sets the index for where the symbol '+' or '-' is found.
                    Found1=false;	// Sets the value of the boolean variable.
                }	// End of condition.
            }	// End for loop block.

            if(Found1==false){	// If condition block.
                int Accume3=0;	// Sets the value of the integer.
                int Accume4=X.size();	// Sets the value of the integer.


                for(int y=1;y<Accume2;y++){	//Begin for loop block.
                    if(X.substr(y,1)=="+" || X.substr(y,1)=="-" || X.substr(y,1)=="*" || X.substr(y,1)=="/"){	// If condition block.
                        Accume3=y+1;	// Sets the index for where the symbol '+' or '-' or '*' or '/' is found.
                    }	// End of condition.
                }	// End for loop block.

                int len4=Accume2-Accume3;	// Sets the value of the integer.
                string AG=X.substr(Accume3,len4);

                left=&AG;	// Sets the pointer to an address of a variable.

                bool fix3=true;// declaring boolean
                for(int z=Accume2+1;z<X.size();z++){	//Begin for loop block.
                    if((X.substr(z,1)=="+" || X.substr(z,1)=="-" || X.substr(z,1)=="*" || X.substr(z,1)=="/")&& fix3){	// If condition block.
                        Accume4=z;	// Sets the index for where the symbol '+' or '-' or '*' or '/' is found.
                        fix3=false;	// Sets the value of the boolean variable.
                    }	// End of condition.
                }	// End for loop block.
                int len3=Accume4-(Accume2+1);	// Sets the value of the integer.
                string AH=X.substr(Accume2+1,len3);//assigning a value for a string
                right =&AH;	// Sets the pointer to an address of a variable.

                if(X.substr(Accume2,1)=="+"){	// If condition block.
                    Addition myAddition1;//creating an object
                    string Newvalue1 = myAddition1.evaluate(*left, *right);//calling a method with pointers

                    int len1=Accume3-0;	// Sets the value of the integer.
                    int len2=X.size()-Accume4;	// Sets the value of the integer.
                    X=X.substr(0,len1)+Newvalue1+X.substr(Accume4,len2);//reassigning value of X

                }	// End of condition.

                else if(X.substr(Accume2,1)=="-"){	// Else if condition.
                    Subtraction mySubtraction1;//creating an object
                    string Newvalue1 = mySubtraction1.evaluate(*left, *right);// calling a method with pointers

                    int len1=Accume3-0;	// Sets the value of the integer.
                    int len2=X.size()-Accume4;	// Sets the value of the integer.
                    X=X.substr(0,len1)+Newvalue1+X.substr(Accume4,len2);	// Creates the changed substring and stores it in a temporary, to later replace the substring from the original string.

                }	// End of condition.


            }	// End of condition.
        }	// End while loop block.

    }	// End of condition.

    for(int j=1; j<X.size();j++){	//Begin for loop block.
        if ((X.substr(j,1)=="+") || (X.substr(j,1)=="-") || (X.substr(j,1)=="*") || (X.substr(j,1)=="/") || (X.substr(j,1)==")")){	// If condition block.
            string *equation1;	// Creates a pointer.
            equation1=&X;	// Sets the pointer to an address of a variable.
            ArithmeticExpression test1;//creating an object
            test1.evaluate(*equation1);//calling a method of the object with a pointer
        }	//End of if condition.
        else{	//Else condition.
            if((X.substr(0,2)=="-0") && (X.size()==2)){	// If condition block.
                X="0";	//Changes all places where '-0' to be '0'.
            }	//End of if condition.
        }	//End of else condition.

    }	// End for loop block.

    return X;	// Returns the new substring.
}	// End of evaluate method.





