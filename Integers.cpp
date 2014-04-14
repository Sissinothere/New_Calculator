
#include "Integers.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Integers::Integers(string sValue) {
	this->sValue = sValue; //String input stored
	iValue = atoi(sValue.c_str()); //String input converted to Int
}


int Integers::getValue()
{
	return iValue;
}

//Accepts an Integer object and performs multiplication
void Integers::Multiply(Integers& in)
	{
		int ans =  this->getValue() * in.getValue();

		//answer = result; //add number to the stream
		ostringstream convert;
		convert << ans;
		answer = convert.str();
	}

//Accepts an Integer object and performs division
void Integers::Divide(Integers& in)
{
	int numOne = this->getValue();
	int numTwo = in.getValue();
	ostringstream convert;
	ostringstream ss;

	int ans;

	if(numOne%numTwo == 0)
	{
		ans =  this->getValue()/in.getValue();
		convert << ans;
		answer = convert.str();
	}
	else
	{
		//ans = "/" + numTwo; //add number to the stream
		convert << numOne;
		answer = convert.str() + "/";
		cout<<"__________answer is "<< answer<<"numeber two is "<< numTwo<<endl;
		//convert.clear();
		ss << numTwo;
		answer += ss.str();
		cout<<"__________answer is "<< answer<<"numeber two is "<< numTwo<<endl;
		//void answer; //return a string with the contents of the stream
	}
}

//Accepts an Integer object and performs addition
void Integers::Add(Integers& in)
{

	int ans =  this->getValue() + in.getValue();
	cout<<"im in int add function ans is"<< ans<<endl;
	//answer = result; //add number to the stream
	ostringstream convert;
	convert << ans;
	answer = convert.str();
	//return answer; //return a string with the contents of the stream
	}

//Accepts an Integer object and performs subtraction
void Integers::Subtract(Integers& in)
	{

	int ans =  this->getValue() - in.getValue();
	cout<<"im in int subtract function ans is"<< ans<<endl;
	ostringstream convert;
	convert << ans;      // insert the textual representation of 'Number' in the characters in the stream
	answer = convert.str();
	}
//Returns current answer
string Integers::getAnswer()
{
	return answer;
}

