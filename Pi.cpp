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

Pi::Pi(string sValue)
{
        this->sValue = sValue; //String input stored
        this->Pi_value = 3.14;
        this->setCoefficient(); //Sets coefficient value to int
        this->powerCount = 1;
}

void Pi::setCoefficient()
{
        if (!atoi(this->sValue.c_str()))
        {
                this->coefficient = 1;
        }
        this->coefficient = atoi(this->sValue.c_str());
}

int Pi::getCoefficient()
{
        return this->coefficient;
}

string Pi::getAnswer()
{
        return answer;
}

void Pi::clearBuffer()
{
        this->coefficientHandle.str("");
        this->coefficientHandle.clear();
}

//Accepts an Pi object and performs multiplication
void Pi::Multiply(Pi& in)
{
        this->clearBuffer();

        int coefficientMultiplication = (this->getCoefficient() * in.getCoefficient());
        //this->powerCount += 1;
        //in.powerCount += 1;

        coefficientHandle << coefficientMultiplication;
        string CoefConvert = coefficientHandle.str();

        //coefficientHandle.str("");
        //coefficientHandle.clear();

        //coefficientHandle << this->powerCount;
        //string powerConvert = coefficientHandle.str();

        //answer = CoefConvert + "pi^" + powerConvert;
        answer = CoefConvert + "pi^2";
}

//Accepts an Pi object and performs division
void Pi::Divide(Pi& in)
{
        this->clearBuffer();

        int coefficientDivision = (this->getCoefficient() / in.getCoefficient());
        if (coefficientDivision == 1)
        {
                answer = "1";
        }

        else if (coefficientDivision % 2 == 0)
        {
                coefficientHandle << coefficientDivision;
                string convert = coefficientHandle.str();
                answer = convert;
        }
        else
        {
                coefficientHandle << this->getCoefficient();
                string thisCoef = coefficientHandle.str();

                coefficientHandle.str("");
                coefficientHandle.clear();

                coefficientHandle << in.getCoefficient();
                string inCoef = coefficientHandle.str();

                answer = "(" + thisCoef + "/" + inCoef + ")" + "pi";
        }
}

//Accepts an Pi object and performs addition
void Pi::Add(Pi& in)
{
        this->clearBuffer();

        int coefficientAddition = this->getCoefficient() + in.getCoefficient();
        if (coefficientAddition == 0)
        {
                answer = "0";
        }
        coefficientHandle << coefficientAddition;
        string convert = coefficientHandle.str();
        answer = convert + "pi";
}

//Accepts an Pi object and performs subtraction
void Pi::Subtract(Pi& in)
{
        this->clearBuffer();

        int coefficientSubtraction = this->getCoefficient() - in.getCoefficient();
        if (coefficientSubtraction == 0)
        {
                answer = "0";
        }
        coefficientHandle << coefficientSubtraction;
        string convert = coefficientHandle.str();
        answer = convert + "pi";
}
