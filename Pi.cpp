
#include "Pi.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Pi::Pi(string sValue)
{
//checks for a fraction
if (sValue.find('/') < 100)
{
int pos = sValue.find('/'); //ex "6pi/3pi"
this->numerator = sValue.substr(0, pos); //num = "6pi"
this->denominator = sValue.substr(pos + 1, sValue.length()); //denom = "3pi"
}
else
{
this->sValue = sValue;
} //String input stored

this->Pi_value = 3.14; //pi constant
this->setCoefficient(); //Sets coefficient value to int
}

void Pi::setCoefficient()
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
int Pi::getCoefficient()
{
return this->coefficient;
}

//get for denominatorCoef
int Pi::getdenomCoef()
{
return this->denomCoef;
}

//get finalAnswer
string Pi::getAnswer()
{
return answer;
}

//clears stringstream buffer
void Pi::clearBuffer()
{
this->coefficientHandle.str("");
this->coefficientHandle.clear();
}

//Simplifies fractions using an algorithm
void Pi::Reduction(){
if (num1 < den1){
for (int i = num1; i >0; i--){
if (num1%i == 0 && den1%i == 0){
num1 = num1 / i;
den1 = den1 / i;
}
}
}
cout << " after if num <" << endl;
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

}

//Accepts an Pi object and performs multiplication
void Pi::Multiply(Pi& in)
{
this->clearBuffer();

int coefficientMultiplication = (this->getCoefficient() * in.getCoefficient());

coefficientHandle << coefficientMultiplication; //stringstream used for converstion b/w string and int
string CoefConvert = coefficientHandle.str();

answer = CoefConvert + "pi^2";

}

//Accepts an Pi object and performs division using Reduction algorithm
void Pi::Divide(Pi& in)
{
this->Reduction(); //call reduction algorithm
}

//Accepts an Pi object and performs addition (or subtraction)
void Pi::Add(Pi& in)
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
answer = convert + "pi";
cout << "add: " << answer << endl;
}
}

//checks for integer answer
bool Pi::canSimplifyToInt()
{
if (answer.find("p") < 100 || answer.find("P") < 100)
{
return false;
}
return true;
}
