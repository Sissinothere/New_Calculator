/*
* Pi.cpp
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak

*/

#include "Pi.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Pi constructor accepts char* parameter
Pi::Pi(char* sValue)
{
	this->sValue = sValue; //String input stored
	this->Pi_value = 3.14;
	this->setCoefficient(); //Sets coefficient value to int
}

void Pi::setCoefficient()
{
	this->coefficient = atoi(this->sValue);
}

int Pi::getCoefficient()
{
	return this->coefficient;
}

string Pi::getAnswer()
{
	return answer;
}

//Accepts an Pi object and performs multiplication
void Pi::Multiply(Pi& in)
{
	int coefficientMultiplication = (this->coefficient * in.coefficient);
	coefficient << coefficientMultiplication;
	string convert = coefficientHandle.str();
	answer = convert + "pi^2";
}

//Accepts an Pi object and performs division
void Pi::Divide(Pi& in)
{
	int coefficientDivision = (this->getCoefficient() / in.getCoefficient());
	if (coefficientDivision != 1)
	{
		return;
	}

	coefficient << coefficientDivision;
	string convert = coefficientHandle.str();
	answer = convert;
	//answer = "(" + (this->sCoefficient) + "/" + (in.sCoefficient) + ")" +
}

//Accepts an Pi object and performs addition
void Pi::Add(Pi& in)
{
	int coefficientAddition = this->getCoefficient() + in.getCoefficient();
	coefficientHandle << coefficientAddition;
	string convert = coefficientHandle.str();
	answer = convert + "pi";
}

//Accepts an Pi object and performs subtraction
void Pi::Subtract(Pi& in)
{
	int coefficientSubtraction = this->getCoefficient() - in.getCoefficient();
	coefficientHandle << coefficientSubtraction;
	string convert = coefficientHandle.str();
	answer = convert + "pi";
}
