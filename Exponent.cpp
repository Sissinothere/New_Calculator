#include "Exponent.h"
#include <stdlib.h>

Exponent::Exponent(string str)
{
	baseIsFrac = false;
	baseIsInt = false;
	powerIsFrac = false;
	powerIsInt = false;

	separate(str);
	findPowerType();
	findBaseType();
	simplify();
	canSimplifyToFrac();
	canSimplifyToInt();
}

void Exponent::separate(string str)
{
	input = str;
	string s = "";
	string tempBase = "";
	string tempPower = "";
	int i = 0;

	if(input.find("^") < 100)
	{
		for(i; str[i]!= '^' && i <= str.length(); i++)
		{
			tempBase += str[i];
		}
		strBase = tempBase;
		i++;
		for(i; i<str.length(); i++)
		{
			tempPower += str[i];
		}
		strPower = tempPower;
	}
}

void Exponent::findPowerType()
{
	 if(strPower.find("/")<100)
	{
		powerIsFrac = true;
	}
	else if(strPower.find("log")<100 || strPower.find("e")<100|| strPower.find("rt")<100|| strPower.find("pi")<100)
	{
		powerIsFrac = false;
		powerIsInt = false;
		if(strPower.find("-") < 100)
		{
			int i = 1;
			string tempPow;
			for(i; i<strPower.length(); i++)
			{
				tempPow += strPower[i];
			}
			if(strBase != "1")
			{
				answer = "1/" + strBase + "^" + tempPow;
			}
			else if(strBase == "1")
			{
				baseIsInt = true;
				answer = "1";
			}
		}
		else
		{
			answer = input;
		}
	}
	else
	{
		powerIsInt = true;
	}
}

void Exponent::findBaseType()
{
	if(strBase.find("log")<100 || strBase.find("e")<100|| strBase.find("rt")<100|| strBase.find("pi")<100)
	{
		power = atoi(strPower.c_str());
		findPowerType();
		if(power < 0 && powerIsInt == true)
		{
			string tempStrPower;
			power = -power;
			ss << power;
			ss >> tempStrPower;
			if(power != 1)
			{
				answer = "1/" + strBase + "^" + tempStrPower;
			}
			else if(power == 1)
			{
				answer = "1/" + strBase;
			}
		}
		else if(power == 1 && powerIsInt == true)
		{
			answer = strBase;
		}
		else if(power == 0 && powerIsInt == true)
		{
			simpToInt = true;
			answer = "1";
		}
		else
		{
			if(strPower.find("-") < 100)
			{
				int i = 1;
				string tempPow;
				for(i; i<strPower.length(); i++)
				{
					tempPow += strPower[i];
				}
				answer = "1/" + strBase + "^" + tempPow;
			}
			else
			{
				answer = input;
			}
		}
	}

	else if(strBase.find("/")<100)
	{
		baseIsFrac = true;
	}
	else
	{
		baseIsInt = true;
	}
}



void Exponent::simplify()
{
	string temp = "";
	int i = 0;
	int j = 0;
	string tempNumerBase = "";
	string tempDenomBase = "";
	string tempNumerPower = "";
	string tempDenomPower = "";
	simpToInt = false;
	simpToFrac = false;

	if(baseIsFrac==true && powerIsFrac==true)
	{

		for(i; strPower[i]!= '/' && i <= strPower.length(); i++)
		{
			tempNumerPower += strPower[i];
		}
		i++;
		strExNumerPower = tempNumerPower;
		
		for(i; i<strPower.length(); i++)
		{
			tempDenomPower += strPower[i];
		}
		strExDenomPower = tempDenomPower;
	
		exNumerPower = atoi(strExNumerPower.c_str());
		exDenomPower = atoi(strExDenomPower.c_str());

		for(j; strBase[j]!= '/' && j <= strBase.length(); j++)
		{
			tempNumerBase += strBase[j];
		}
		j++;
		strExNumerBase = tempNumerBase;
		for(j; j<strBase.length(); j++)
		{
			tempDenomBase += strBase[j];
		}
		strExDenomBase = tempDenomBase;

		exNumerBase = atoi(strExNumerBase.c_str());
		exDenomBase = atoi(strExDenomBase.c_str());

		if(exNumerPower > 0)
		{
			string n;
			string strNumTop;
			string strNumBot;
			int numTop = powerFunc(exNumerBase, exNumerPower);
			int numBot = powerFunc(exDenomBase, exNumerPower);
			ss << numTop;
			ss >> strNumTop;
			ss.clear();
			ss << numBot;
			ss >> strNumBot;
			ss.clear();
			ss << exDenomPower;
			ss >> n;

			if(strNumTop == "1")
			{
				if(n != "2")
					answer = "1/" + n + "rt:" + strNumBot;
				else
					answer = "1/sqrt:" + strNumBot;
			}
			else if(strNumBot == "1")
			{
				if(n != "2")
					answer = n + "rt:" + strNumTop;
				else
					answer = "sqrt:" + strNumTop;
			}
			else
			{
				if(n != "2")
				answer = n + "rt:" + strNumTop + "/" + n + "rt:" + strNumBot;
			else
				answer = "sqrt:" + strNumTop + "/sqrt:" + strNumBot;
			}
		}
		else
		{
			string n;
			string strNumTop;
			string strNumBot;
			int numTop = powerFunc(exNumerBase, -exNumerPower);
			int numBot = powerFunc(exDenomBase, -exNumerPower);
			ss << numTop;
			ss >> strNumTop;
			ss.clear();
			ss << numBot;
			ss >> strNumBot;
			ss.clear();
			ss << exDenomPower;
			ss >> n;

			
			if(1 == 1)
			{
				if(strNumBot == "1")
			{
				if(n != "2")
					answer = "1/" + n + "rt:" + strNumTop;
				else
					answer = "1/sqrt:" + strNumTop;
			}
			else if(strNumTop == "1")
			{
				if(n != "2")
					answer = n + "rt:" + strNumBot;
				else
					answer = "sqrt:" + strNumBot;
			}
			}
			else
			{
				if(n != "2")
					answer = n + "rt:" + strNumBot + "/" + n + "rt:" + strNumTop;
				else
					answer = "sqrt:" + strNumBot + "/sqrt:" + strNumTop;
			}
		}
	}
	else if(baseIsInt == true && powerIsFrac == true)
	{
		base = atoi(strBase.c_str());
		for(i; strPower[i]!= '/' && i <= strPower.length(); i++)
		{
			tempNumerPower += strPower[i];
		}
		i++;
		strExNumerPower = tempNumerPower;
		for(i; i<strPower.length(); i++)
		{
			tempDenomPower += strPower[i];
		}
		strExDenomPower = tempDenomPower;
	
		exNumerPower = atoi(strExNumerPower.c_str());
		exDenomPower = atoi(strExDenomPower.c_str());
		if(exNumerPower > 0)
		{
			string n;
			string strNum;
			int num = powerFunc(base, exNumerPower);
			ss << num;
			ss >> strNum;
			ss.clear();
			ss << exDenomPower;
			ss >> n;

			if(n != "2")
				answer = n + "rt:" + strNum;
			else
				answer = "sqrt:" + strNum;
		}
		else
		{
			string n;
			string strNum;
			int num = powerFunc(base, -exNumerPower);
			ss << num;
			ss >> strNum;
			ss.clear();
			ss << exDenomPower;
			ss >> n;

			if(n != "2")
				answer = "1/" + n + "rt:" + strNum;
			else
				answer = "1/sqrt:" + strNum;
		}

	}
	else if(baseIsInt == true && powerIsInt == true)
	{
		if(power == 1)
		{
			simpToInt = true;
			answer = strBase;
		}
		else if(atoi(strPower.c_str()) == 0)
		{
			simpToInt = true;
			answer = "1";
		}

		else if(atoi(strPower.c_str()) < 0)
		{
			base = atoi(strBase.c_str());
			power = atoi(strPower.c_str());
			simpToFrac = true;
			ss << powerFunc(base, -power);
			ss >> strExDenomBase;
			answer = "1/" + strExDenomBase;
			//ss >> answer;
		}
		else
		{
			base = atoi(strBase.c_str());
			power = atoi(strPower.c_str());
			simpToInt = true;
			ss << powerFunc(base, power);
			ss >> answer;
		}
		if(strBase == "1")
		{
			simpToInt = true;
			answer = "1";
		}
	}
	else if(baseIsFrac == true && powerIsInt == true)
	{
		for(i; strBase[i]!= '/' && i <= strBase.length(); i++)
		{
			tempNumerBase += strBase[i];
		}
		i++;
		strExNumerBase = tempNumerBase;
		for(i; i<strBase.length(); i++)
		{
			tempDenomBase += strBase[i];
		}
		strExDenomBase = tempDenomBase;

		exNumerBase = atoi(strExNumerBase.c_str());
		exDenomBase = atoi(strExDenomBase.c_str());
		power = atoi(strPower.c_str());
		
		if(power < 0)
		{
			exNumerBase = powerFunc(exNumerBase, -power);
			exDenomBase = powerFunc(exDenomBase, -power);
		}
		else
		{
			exNumerBase = powerFunc(exNumerBase, power);
			exDenomBase = powerFunc(exDenomBase, power);
		}
		
		if(power == 1)
		{
			simpToFrac = true;
			answer = strBase;
		}
		else if(power == 0)
		{
			simpToInt = true;
			answer = "1";
		}
		else if(exNumerBase%exDenomBase == 0 && power > 0)
		{ 
			simpToInt = true;
			int tempAnswer = exNumerBase/exDenomBase;
			ss << tempAnswer;
			ss >> answer;
		}
		else if(power < 0)
		{
			ss << exNumerBase;
			ss >> strExNumerBase;
			ss.clear();
			ss << exDenomBase;
			ss >> strExDenomBase;
			
			if(strExNumerBase != "1")
			{
				simpToFrac = true;
				answer = strExDenomBase + "/" + strExNumerBase;
			}
			else
			{
				simpToInt = true;
				answer = strExDenomBase;
			}
		}
		else
		{
			simpToFrac = true;
			ss << exNumerBase;
			ss >> strExNumerBase;
			ss.clear();
			ss << exDenomBase;
			ss >> strExDenomBase;

			answer = strExNumerBase + "/" + strExDenomBase;
		}
	}
	if(strBase == "1")
	{
		simpToInt = true;
		answer = "1";
	}
	else
	{
	}
}

bool Exponent::canSimplifyToFrac()
{
	if(simpToFrac == true)
		return true;
	else
		return false;
}

bool Exponent::canSimplifyToInt()
{
	if(simpToInt == true)
		return true;
	else
		return false;
}

string Exponent::getBase()
{
	return strBase;
}

string Exponent::getPower()
{
	return strPower;
}

string Exponent::getAnswer()
{
	cout << "This is nrt answer:" << answer << endl;
	return answer;
}

int Exponent::powerFunc(int base, int pow)
{
	int base2 = base;
	for(int i = 1; i < pow; i++)
		base2 = base2*base;
	return base2;
}

void Exponent::add(Exponent& exp)
{
	if(strBase == exp.strBase && strPower == exp.strPower)
		answer = "2*" + answer;
	else
		answer = answer + "+" + exp.getAnswer();
}

void Exponent::subtract(Exponent& exp)
{
	if(strBase == exp.strBase && strPower == exp.strPower)
		answer = "0";
	else
		answer = answer + "-" + exp.getAnswer();
}

void Exponent::multiply(Exponent& exp)
{
	if(strBase == exp.strBase && strPower == exp.strPower)
		answer = answer + "*" + answer;
	else
		answer = answer + "*" + exp.getAnswer();
}

void Exponent::divide(Exponent& exp)
{
	if(strBase == exp.strBase && strPower == exp.strPower)
		answer = "1";
	else
		answer = answer + "/" + exp.getAnswer();
}

