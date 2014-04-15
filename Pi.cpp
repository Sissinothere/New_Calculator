#include "Pi.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Pi::Pi(string sValue)
{
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

        this->Pi_value = 3.14;
        this->setCoefficient(); //Sets coefficient value to int
}

void Pi::setCoefficient()
{
        if (this->sValue.find("-") < 100 && !atoi(this->sValue.c_str()))
        {
                this->coefficient = -1;
        }
        else if (!atoi(this->sValue.c_str()))
        {
                this->coefficient = 1;
        }

        else if (this->sValue.find("-") < 100)
        {
                this->coefficient = atoi(this->sValue.c_str());
        }
        else
                this->coefficient = atoi(this->sValue.c_str());

        if (atoi(this->numerator.c_str()))
        {
                this->coefficient = atoi(this->numerator.c_str());
        }
        else if (atoi(this->denominator.c_str()))
        {
                this->denomCoef = atoi(this->denominator.c_str());
        }

}

int Pi::getCoefficient()
{
        return this->coefficient;
}

int Pi::getdenomCoef()
{
        return this->denomCoef;
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

        coefficientHandle << coefficientMultiplication;
        string CoefConvert = coefficientHandle.str();

        answer = CoefConvert + "pi^2";
        cout << "mult: " << answer << endl;
}

//Accepts an Pi object and performs division
//Checks for evenness and oddness
void Pi::Divide(Pi& in)
{
        this->clearBuffer();

        cout << this->getCoefficient() << endl;
        cout << this->getdenomCoef() << endl;

        int coefficientDivision = (this->getCoefficient() / this->getdenomCoef());

        if (this->getCoefficient() % this->getdenomCoef() == 0)
        {
                coefficientHandle << coefficientDivision;
                string convert = coefficientHandle.str();
                answer = convert;
                cout << answer << endl;
        }
        else if (coefficientDivision == 1)
        {
                answer = "1";
        }
        else if (this->getCoefficient() % 2 == 0 && this->getdenomCoef() % 2 == 0)
        {
                if (this->getCoefficient() > this->getdenomCoef())
                {
                        coefficientHandle << coefficientDivision;
                        string convert = coefficientHandle.str();
                        answer = convert;
                        cout << answer << endl;
                }
                if (this->getCoefficient() < this->getdenomCoef())
                {
                        coefficientHandle << this->getCoefficient();
                        string thisCoef = coefficientHandle.str();

                        coefficientHandle.str("");
                        coefficientHandle.clear();

                        coefficientHandle << this->getdenomCoef();
                        string inCoef = coefficientHandle.str();

                        answer = "(" + thisCoef + "/" + inCoef + ")" + "pi";
                        cout << answer << endl;
                }
        }
        else if (!this->getCoefficient() % 2 == 0 && this->getdenomCoef() % 2 == 0)
        {
                coefficientHandle << this->getCoefficient();
                string thisCoef = coefficientHandle.str();

                coefficientHandle.str("");
                coefficientHandle.clear();

                coefficientHandle << this->getdenomCoef();
                string inCoef = coefficientHandle.str();

                answer = "(" + thisCoef + "/" + inCoef + ")" + "pi";
                cout << answer << endl;
        }
        else if (this->getCoefficient() % 2 == 0 && !this->getdenomCoef() % 2 == 0)
        {
                coefficientHandle << this->getCoefficient();
                string thisCoef = coefficientHandle.str();

                coefficientHandle.str("");
                coefficientHandle.clear();

                coefficientHandle << this->getdenomCoef();
                string inCoef = coefficientHandle.str();

                answer = "(" + thisCoef + "/" + inCoef + ")" + "pi";
                cout << answer << endl;
        }
        else if (this->getCoefficient() < this->getdenomCoef())
        {
                coefficientHandle << coefficientDivision;
                string convert = coefficientHandle.str();
                answer = convert;
                cout << answer << endl;
                //this->canSimplifyToInt = true;
        }
        else
        {
                coefficientHandle << this->getCoefficient();
                string thisCoef = coefficientHandle.str();

                coefficientHandle.str("");
                coefficientHandle.clear();

                coefficientHandle << this->getdenomCoef();
                string inCoef = coefficientHandle.str();

                answer = "(" + thisCoef + "/" + inCoef + ")" + "pi";
                cout << answer << endl;
        }
}

//Accepts an Pi object and performs addition (or subtraction)
void Pi::Add(Pi& in)
{
        this->clearBuffer();

        int coefficientAddition = this->getCoefficient() + in.getCoefficient();
        if (coefficientAddition == 0)
        {
                answer = "0";
                cout << "when ans = " << answer << endl;
        }
        else if (coefficientAddition == 1)
        {
                answer = "1";
                cout << "when ans =  " << answer << endl;
        }
        else if (coefficientAddition == -1)
        {
                answer = "-1";
                cout << "when ans = " << answer << endl;
        }
        else
        {
                coefficientHandle << coefficientAddition;
                string convert = coefficientHandle.str();
                answer = convert + "pi";
                cout << "add: " << answer << endl;
        }
}
