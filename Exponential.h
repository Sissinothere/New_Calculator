/*
* E.h
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak
*/

#ifndef Ex_H_
#define Ex_H_


#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Exponential
{
double e_value;
signed int coefficient, denomCoef;
int num1, den1;
bool isInt;
string sValue, denominator, numerator;
string answer;
stringstream coefficientHandle;

public:

Exponential(string sValue);
void setCoefficient();
int getCoefficient();
int getdenomCoef();
string getAnswer();

bool canSimplifyToInt();
void Reduction();
void clearBuffer();

void Multiply(Exponential& in);
void Divide(Exponential& in);
void Add(Exponential& in);
};

#endif /* Ex_H_ */
