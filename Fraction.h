
#ifndef FRACTION_H
#define	FRACTION_H
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

class Fraction{

private:
    int num1;
    int den1;
    
    int lcd;
    int gcd;
//    int reduced_num;
//    int reduced_den;
//    int new_num1;
//    int new_num2;
    int a;

    int new_fraction;
    int final_num;
    int final_den;
    
    int iValue;
    string sValue;
    string answer;
    bool cansimptoInt=false;
    
public:
    
    Fraction(string sValue);
    
    int getFraction();
    int getNumerator();
    int getDenominator();
    string getAnswer();
    void Reduction();
    bool canSimplifytoInteger();
    void Addition(Fraction& frac);
    void Subtraction(Fraction& frac);
    void Multiplication(Fraction& frac);
    void Division(Fraction& frac);



#endif	/* FRACTION_H */

};



