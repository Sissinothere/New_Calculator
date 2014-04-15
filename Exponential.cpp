/*
* Exponential.cpp
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak
*/

#include "Exponential.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Exponential::Exponential(string sValue)
{
//checks for a fraction
if (sValue.find('/') < 100)
{
int pos = sValue.find('/'); //ex "6e/3e"
this->numerator = sValue.substr(0, pos); //num = "6e"
this->denominator = sValue.substr(pos + 1, sValue.length()); //denom = "3e"
}
else //all other values
{
this->sValue = sValue; //otherwise sValue = (someCoef)e
} //String input stored

this->e_value = 2.72; //e constant
this->setCoefficient(); //Sets coefficient value to int
}

void Exponential::setCoefficient()
{
//checks for minus and no numbers, Coef == -1
if (this->sValue.find("-") < 100 && !atoi(this->sValue.c_str()))
{
this->coefficient = -1;
}
//checks for no numbers, Coef == 1
else if (!atoi(this->sValue.c_str()))
{
this->coefficient = 1;
}
//checks for minus, Coef == -1(someValue)
else if (this->sValue.find("-") < 100)
{
this->coefficient = atoi(this->sValue.c_str());
}
else //last case: extract numbers and set equal to Coef
this->coefficient = atoi(this->sValue.c_str());

//if there was a fraction do:
//numeratorCoef == topCoef
if (atoi(this->numerator.c_str()))
{
this->num1 = atoi(this->numerator.c_str());
}
//denominatorCoef == bottomCoef
if (atoi(this->denominator.c_str()))
{
this->den1 = atoi(this->denominator.c_str());
}
}

//get for Coef or NumeratorCoef
int Exponential::getCoefficient()
{
return this->coefficient;
}

//get for denominatorCoef
int Exponential::getdenomCoef()
{
return this->denomCoef;
}

//get finalAnswer
string Exponential::getAnswer()
{
return answer;
}

//clears stringstream buffer
void Exponential::clearBuffer()
{
this->coefficientHandle.str("");
this->coefficientHandle.clear();
}

//Simplifies fractions using an algorithm
void Exponential::Reduction(){
if (num1 < den1){

for (int i = num1; i >0; i--){

if (num1%i == 0 && den1%i == 0){
num1 = num1 / i;
den1 = den1 / i;
}
}
}
if (num1 > den1){
for (int i = den1; i >0; i--){
if (num1%i == 0 && den1%i == 0){
num1 = num1 / i;
den1 = den1 / i;
}
}
}
if (num1 == den1){
isInt = true;
answer = "1";
num1 = 1;
den1 = 1;

}
else{
stringstream ss;
ss << num1;
ss << "/";
ss << den1;
answer = ss.str();
if (isInt){
ss.str("");
ss << num1;
answer = ss.str();
}
}
if (num1 == 0){
answer = "0";
isInt = true;
}
cout << answer << endl;
}

//Accepts an e object and performs multiplication
void Exponential::Multiply(Exponential& in)
{
this->clearBuffer();

int coefficientMultiplication = (this->getCoefficient() * in.getCoefficient());

coefficientHandle << coefficientMultiplication; //stringstream used for converstion b/w string and int
string CoefConvert = coefficientHandle.str();

answer = CoefConvert + "e^2";
}

//Accepts an e object and performs division using Reduction algorithm
void Exponential::Divide(Exponential& in)
{
this->Reduction(); //call reduction algorithm
}

//Accepts an e object and performs addition (or subtraction)
void Exponential::Add(Exponential& in)
{
this->clearBuffer();

int coefficientAddition = this->getCoefficient() + in.getCoefficient();
if (coefficientAddition == 0)
{
answer = "0";
}
else if (coefficientAddition == 1)
{
answer = "1";
}
else if (coefficientAddition == -1)
{
answer = "-1";
}
else
{
coefficientHandle << coefficientAddition;
string convert = coefficientHandle.str();
answer = convert + "e";
}
}

//checks for integer answer
bool Exponential::canSimplifyToInt()
{
if (answer.find("e") < 100 || answer.find("E"))
{
return false;
}else{
return true;
}
}
