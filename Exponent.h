#include <strstream>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;


class Exponent
{
	strstream ss;
	string input;
	string strBase;
	string strPower;
	string answer;
	int base;
	int power;
	bool simpToInt;
	bool simpToFrac;
	bool baseIsFrac;
	bool baseIsInt;
	bool powerIsFrac;
	bool powerIsInt;
	string strExNumerBase;
	string strExDenomBase;
	string strExNumerPower;
	string strExDenomPower;
	int exNumerBase;
	int exDenomBase;
	int exNumerPower;
	int exDenomPower;

public:
	Exponent(string str);
	int powerFunc(int base, int pow);
	void separate(string str);
	void findBaseType();
	void findPowerType();
	bool CanSimplifyBasetoINt();
	bool CanSimplifyPowertoINt();
	bool canSimplifyToFrac();
	bool canSimplifyToInt();
	void simplify();
	string getBase();
	string getPower();
	string getAnswer();

	void add(Exponent& exp);
	void divide(Exponent& exp);
	void multiply(Exponent& exp);
	void subtract(Exponent& exp);
};
