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

//E constructor accepts string parameter
Exponential::Exponential(string sValue)
{
	this->sValue = sValue; //String input stored
	this->e_value = 2.72;
}


string Exponential::getAnswer()
{
	return answer;
}

//Accepts an Pi object and performs multiplication
void Exponential::Multiply(Exponential& in)
{
	answer = "e^2";
}

//Accepts an Pi object and performs division
void Exponential::Divide(Exponential& in)
{
	answer = "1";
}

//Accepts an Pi object and performs addition
void Exponential::Add(Exponential& in)
{
	answer = "2*e";
}

//Accepts an Pi object and performs subtraction
void Exponential::Subtract(Exponential& in)
{
	answer = "0";
}

