/*
 * Integers.h
 *
 *  Created on: Apr 6, 2014
 *      Author: Administrator
 */

#ifndef INTEGERS_H_
#define INTEGERS_H_


#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Integers{
	int iValue;
	string sValue;
	string answer;

public:
	Integers(string sValue);

	int getValue();
	string getAnswer();
	void Multiply(Integers& in);
	void Divide(Integers& in);
	void Add(Integers& in);
	void Subtract(Integers& in);
};


#endif /* INTEGERS_H_ */
