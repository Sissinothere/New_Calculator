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
        signed int coefficient, denomCoef;

        string sValue, denominator, numerator;
        string answer;
        stringstream coefficientHandle;

public:

        Pi(string sValue);
        void setCoefficient();
        int getCoefficient();
        int getdenomCoef();
        string getAnswer();

        //bool canSimplifyToInt;
        //bool canSimplifyToFrac;
        void clearBuffer();

        void Multiply(Pi& in);
        void Divide(Pi& in);
        void Add(Pi& in);
};

#endif /* PI_H_ */
