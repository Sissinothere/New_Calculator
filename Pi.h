/*
* Pi.h
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak
*/

#ifndef PI_H_
#define PI_H_


#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Pi
{
        double Pi_value;
        int coefficient;
        int powerCount;
        string sValue;
        string answer;
        stringstream coefficientHandle;

public:

        Pi(string sValue);
        void setCoefficient();
        int getCoefficient();
        string getAnswer();
        void clearBuffer();

        void Multiply(Pi& in);
        void Divide(Pi& in);
        void Add(Pi& in);
        void Subtract(Pi& in);
};


#endif /* PI_H_ */
