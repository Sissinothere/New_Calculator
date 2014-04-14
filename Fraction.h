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
	//int
//	int intValue;
	string num;
	string den;
//	string intvalue;
    string input;
	bool isInt;
    string answer;
    bool cansimptoInt=false;

public:

    Fraction(string sValue);

	void checkValues();
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

};
