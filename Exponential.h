/*
* Exponential.h
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak
*/

#ifndef E_H_
#define E_H_


#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Exponential{
	double e_value;
	string sValue;
	string answer;

public:

	Exponential(string sValue);
	string getAnswer();

	void Multiply(Exponential& in);
	void Divide(Exponential& in);
	void Add(Exponential& in);
	void Subtract(Exponential& in);
};


#endif /* E_H_ */

