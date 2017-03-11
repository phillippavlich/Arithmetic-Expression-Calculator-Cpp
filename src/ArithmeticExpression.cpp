//  ArithmeticExpression.cpp
/*
 * Name: Matthew Shortt, Phillip Pavlich, Ivan Bauer
 * MacID: shorttmk, pavlicpm, bauerim
 * Student Number: 1417616, 1414960, 1418765
 * Description: This is ArithmeticExpression class that extends off of
 * Expression in order to choose how to evaluate a given expression.
 */

#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include "Division.h"
#include <string>
#include <sstream>

using namespace std;

class ArithmeticExpression : public Expression{
    Expression *left;
    Expression *right;
    string evaluate(string &X){
        int brackets=0;
        for(int i=0;i<X.size();i++){
            if(X.at(i)=="("){
                brackets++;
            }
        }
        if(brackets!=0){
            int brackets1=0;
            for(int j=0;j<X.size();j++){
                if(X.at(j)=="("){
                    brackets1=j;
                }
            }
            int brackets2=0;
            bool first=true;
            for(int f=brackets1;f<X.size();f++){
                if((X.at(f)==")") && (first)){
                    brackets2=f;
                    first=false;
                }
            }
            int size2 = brackets2-(brackets1+1);
            string temp=X.substr(brackets1+1,size2);

            bool found=false;
            while(!found){
                found==true;
                int accum2=0;
                for(int r=0;r<temp.size();r++){
                    if((temp.at(r)=="*" || temp.at(r)=="/") && found){
                        accum2=r;
                        found=false;
                    }
                }
                if(found==false){
                    int accum3=0;
                    int accum4=temp.size();

                    for(int y=0;y<accum2;y++){
                        if(temp.at(y)=="+" || temp.at(y)=="-" || temp.at(y)=="*" || temp.at(y)=="/"){
                            accum3=y+1;
                        }
                    }
                    int size1= accum2-accum3;
                    string AA=temp.substr(accum3,size1);
                    *left= &AA;

                    for(int z=accum2+1;z<temp.size();z++){
                        if(temp.at(z)=="+" || temp.at(z)=="-" || temp.at(z)=="*" || temp.at(z)=="/"){
                            accum4=z;
                        }
                    }
                    int size= accum4-(accum2+1);

                    string AB=temp.substr(accum2+1,size);
                    *right= &AB;

                    if(temp.at(accum2)=="*"){
                        //string newvalue=Multiplication(*left,*right);
                        int Length10= temp.size()-accum4;
                        int Length9=accum3-0;
                        temp=temp.substr(0,Length9)+newvalue+temp.substr(accum4,Length10);
                    }

                    if(temp.at(accum2)=="/"){
                        //string newvalue=Division(*left,*right);
                        int Length10= temp.size()-accum4;
                        int Length9=accum3-0;
                        temp=temp.substr(0,Length9)+newvalue+temp.substr(accum4,Length10);
                    }


                }
            }
            //down here dealing with adding/sub

            bool found1=false;
            while(!found1){
                found1==true;
                int Accum2=0;
                for(int r=0;r<temp.size();r++){
                    if((temp.at(r)=="+" || temp.at(r)=="-") && found1){
                        Accum2=r;
                        found1=false;
                    }
                }
                if(found1==false){
                    int Accum3=0;
                    int Accum4=temp.size();

                    for(int y=0;y<Accum2;y++){
                        if(temp.at(y)=="+" || temp.at(y)=="-" || temp.at(y)=="*" || temp.at(y)=="/"){
                            Accum3=y+1;
                        }
                    }

                    int Length6=Accum2-Accum3;
                    string AC=temp.substr(Accum3,Length6);
                    *left=&AC;

                    for(int z=Accum2+1;z<temp.size();z++){
                        if(temp.at(z)=="+" || temp.at(z)=="-" || temp.at(z)=="*" || temp.at(z)=="/"){
                            Accum4=z;
                        }
                    }

                    int Length5=Accum4-(Accum2+1);
                    string AD=temp.substr(Accum2+1,Length5);
                    *right=&AD;

                    if(temp.at(Accum2)=="+"){
                        string newvalue1= Addition(*left,*right);
                        int Length3= Accum3-0;
                        int Length4=temp.size()-Accum4;
                        temp=temp.substr(0,Length3)+newvalue1+temp.substr(Accum4,Length4);
                    }

                    if(temp.at(Accum2)=="-"){
                        string newvalue1=Subtraction(*left,*right);
                        int Length3= Accum3-0;
                        int Length4=temp.size()-Accum4;
                        temp=temp.substr(0,Length3)+newvalue1+temp.substr(Accum4,Length4);
                    }


                }
            }
            /////addd temp back to X create new x
            int Length1= brackets1-0;
            int Length2=X.size()-(brackets2+1);
            X=X.substr(0,Length1)+temp+X.substr(brackets2+1,Length2);
        }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else{//if there is no more brackets
            bool Found=false;
            while(!Found){
                Found==true;
                int accume2=0;
                for(int r=0;r<X.size();r++){
                    if((X.at(r)=="*" || X.at(r)=="/") && Found){
                        accume2=r;
                        Found=false;
                    }
                }
                if(Found==false){
                    int accume3=0;
                    int accume4=X.size();

                    for(int y=0;y<accume2;y++){
                        if(X.at(y)=="+" || X.at(y)=="-" || X.at(y)=="*" || X.at(y)=="/"){
                            accume3=y+1;
                        }
                    }
                    int len8=accume2-accume3;

                    string AE=X.substr(accume3,len8);
                    *left=&AE;

                    for(int z=accume2+1;z<X.size();z++){
                        if(X.substr(z)=="+" || X.substr(z)=="-" || X.substr(z)=="*" || X.substr(z)=="/"){
                            accume4=z;
                        }
                    }
                    int len7=accume4-(accume2+1);

                    string AF=X.substr(accume2+1,len7);
                    *right = &AF;

                    if(X.at(accume2)=="*"){
                        string Newvalue=Multiplication(*left,*right);
                        int len5=accume3-0;
                        int len6=X.size()-accume4;
                        X=X.substr(0,len5)+Newvalue+X.substr(accume4,len6);
                    }

                    if(X.at(accume2)=="/"){
                        string Newvalue=Division(*left,*right);
                        int len5=accume3-0;
                        int len6=X.size()-accume4;
                        X=X.substr(0,len5)+Newvalue+X.substr(accume4,len6);
                    }


                }
            }
            //down here dealing with adding/sub

            bool Found1=false;
            while(!Found1){
                Found1==true;
                int Accume2=0;
                for(int r=0;r<X.size();r++){
                    if((X.at(r)=="+" || X.at(r)=="-") && Found1){
                        Accume2=r;
                        Found1=false;
                    }
                }
                if(Found1==false){
                    int Accume3=0;
                    int Accume4=X.size();

                    for(int y=0;y<Accume2;y++){
                        if(X.at(y)=="+" || X.at(y)=="-" || X.at(y)=="*" || X.at(y)=="/"){
                            Accume3=y+1;
                        }
                    }

                    int len4=Accume3-Accume2;
                    string AG=X.substr(Accume3,len4);
                    *left=&AG;

                    for(int z=Accume2+1;z<X.size();z++){
                        if(X.at(z)=="+" || X.at(z)=="-" || X.at(z)=="*" || X.at(z)=="/"){
                            Accume4=z;
                        }
                    }
                    int len3=Accume4-(Accume2+1);
                    string AH=X.substr(Accume2+1,len3);
                    *right =&AH;

                    if(X.at(Accume2)=="+"){
                        string Newvalue1=Addition(*left,*right);
                        int len1=Accume3-0;
                        int len2=X.size()-Accume4;
                        X=X.substr(0,len1)+Newvalue1+X.substr(Accume4,len2);
                    }

                    if(X.at(Accume2)=="-"){
                        string Newvalue1=Subtraction(*left,*right);
                        int len1=Accume3-0;
                        int len2=X.size()-Accume4;
                        X=X.substr(0,len1)+Newvalue1+X.substr(Accume4,len2);
                    }


                }
            }
        }
        for(int j=0; j<X.size();j++){
                if ((X.at(j)=="+") || (X.at(j)=="-") || (X.at(j)=="*") || (X.at(j)=="/")){
                    evaluate(string &X);
                }
                else{
                        return X;
                }
        }

    }


};



ArithmeticExpression::~ArithmeticExpression()
{
    //dtor
}
