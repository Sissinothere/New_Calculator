#include "nthRoot.h"
#include <stdlib.h>
nthRoot::nthRoot(string str)
{
	someroot = str;
	string s = "";
	string tempN = "";
	string tempNum = "";
	string tempScal = "";
	int i = 0;

	if(someroot.at(0) == '-' && someroot.find("rt") < 100)
	{
		i++;
		if(someroot.find("*") < 100)
		{
			for(i; str[i]!='*' && i <=str.length();i++)
			{
				tempScal += str[i];
			}
			strScal = tempScal;
			i++;
			for(i; str[i]!='r' && i <=str.length();i++)
			{
				s += str[i];
			}
			if(s == "sq")
				tempN = "2";
			else
				tempN = s;
			strN = tempN;
			i = i+3;

			for(i; i<str.length(); i++)
			{
				tempNum += str[i];
			}
			strNum = tempNum;
		
			scal = -atoi(tempScal.c_str());
			n = atoi(tempN.c_str());
			num = atoi(tempNum.c_str());
	
			this->scal = scal;
			this->n = n;
			this->num = num;

			simplify();
		}
		else
		{
			for(i; str[i]!='r' && i <=str.length();i++)
			{
				s += str[i];
			}
			if(s == "sq")
				tempN = "2";
			else
				tempN = s;
			strN = tempN;
			i = i+3;

			for(i; i<str.length(); i++)
			{
				tempNum += str[i];
			}
			strNum = tempNum;
		
			n = atoi(tempN.c_str());
			num = atoi(tempNum.c_str());
	
			scal = 1;
			this->n = n;
			this->num = num;

			simplify();
			isInt = false;
			isFrac = true;


		}
	}
	else if(someroot.find("rt") < 100)
	{
		if(someroot.find("*") < 100)
		{
			for(i; str[i]!='*' && i <=str.length();i++)
			{
				tempScal += str[i];
			}
			strScal = tempScal;
			i++;
			for(i; str[i]!='r' && i <=str.length();i++)
			{
				s += str[i];
			}
			if(s == "sq")
				tempN = "2";
			else
				tempN = s;
			strN = tempN;
			i = i+3;

			for(i; i<str.length(); i++)
			{
				tempNum += str[i];
			}
			strNum = tempNum;
		
			scal = atoi(tempScal.c_str());
			n = atoi(tempN.c_str());
			num = atoi(tempNum.c_str());
	
			this->scal = scal;
			this->n = n;
			this->num = num;

			simplify();
		}
		else
		{
			for(i; str[i]!='r' && i <=str.length();i++)
			{
				s += str[i];
			}
			if(s == "sq")
				tempN = "2";
			else
				tempN = s;
			strN = tempN;
			i = i+3;

			for(i; i<str.length(); i++)
			{
				tempNum += str[i];
			}
			strNum = tempNum;
		
			n = atoi(tempN.c_str());
			num = atoi(tempNum.c_str());
	
			scal = 1;
			this->n = n;
			this->num = num;

			simplify();
		}
	}
	else
	{
		for(i; i<str.length(); i++)
		{
			tempScal += str[i];
		}
		strScal = tempScal;

		scal = atoi(tempScal.c_str());
		n = 2;
		num = 1;
	
		this->scal = scal;
		this->n = n;
		this->num = num;

	}
}

void nthRoot::primeFactors(int num, std::vector<int>&  factors, int facVal = 2)
{	
		if (num % facVal == 0)
		{
			factors.push_back(facVal);
			primeFactors(num/facVal, factors, facVal);
		}
		else if (facVal <= num)
		{
			primeFactors(num, factors, facVal + 1);
		}
}

void nthRoot::simplify()
{
	
	if(num < 0 && (-num)%2 != 0)
	{
		std::vector<int> factors;
		primeFactors(-num, factors);
		int count = 1;
		int value = factors[0];
		for(int i = 1; i < factors.size(); i++)
		{
			if(value == factors[i])
			{
				count++;
				if(count == n)
				{
					num = num / power(value, n);
					scal = scal * value;
					count = 0;
				}
			}
			else
			{
				value = factors[i];
				count = 1;
			}
		}
	}
	else
	{
		std::vector<int> factors;
		primeFactors(num, factors);
		int count = 1;
		int value = factors[0];
		for(int i = 1; i < factors.size(); i++)
		{
			if(value == factors[i])
			{
				count++;
				if(count == n)
				{
					num = num / power(value, n);
					scal = scal * value;
					count = 0;
				}
			}
			else
			{
				value = factors[i];
				count = 1;
			}
		}
	}
	
	if(num == 1)
	{
		isInt = true;
	}
	else if(num == -1 && n%2 != 0)
	{
		isInt = true;
		scal = -scal;
		num = -num;
	}
	else if(num < -1 && n%2 != 0)
	{
		scal = -scal;
	}
	else if(num == -1 && n%2 == 0)
	{
		isInt = true;
	}
	else
	{
	}
}

int nthRoot::power(int base, int pow)
{
	int base2 = base;
	for(int i = 1; i < pow; i++)
		base2 = base2*base;
	return base2;
}


bool nthRoot::canSimplifytoInt()
{


	if(isInt == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool nthRoot::canSimpifytoFrac()
{
	if(isFrac == true)
		{
			return true;
		}
		else
		{
			return false;
		}
}
int nthRoot::getN()
{
	return n;
}

int nthRoot::getNum()
{
	return num;
}

int nthRoot::getScal()
{
	return scal;
}

string nthRoot::getSimp()
{
	if(isFrac == true)
	{
		formNewRoot();
		string tempAns;
		tempAns = someroot;
		someroot = "(1/(" + tempAns + "))";
		return someroot;
	}
	else
	{
		formNewRoot();
		return someroot;
	}
}

string nthRoot::getAns()
{
	return someroot;
}

void nthRoot::formNewRoot()
{
	string newRoot;
	ss<<scal;
	ss>>strScal;
	ss<<n;
	ss>>strN;
	ss.clear();
	ss<<num;
	ss>>strNum;
	ss.clear();
	
	if(strScal.find("-") < 100)
	{
		if(strScal == "1" || strScal == "-1")
		{
			if(strN == "2" && strNum != "1")
			{
				newRoot = "-sqrt:";
				newRoot += strNum;
				someroot=newRoot;
			}
			else if(strNum == "1")
			{
				newRoot = strScal;
				someroot = newRoot;
			}
		
			else
			{
				newRoot = "-" + strN + "rt:";
				newRoot += strNum;
				someroot=newRoot;
			}
		}
		else
		{
			if(strN == "2" && strNum != "1")
			{
				newRoot = strScal + "*sqrt:";
				newRoot += strNum;
				someroot=newRoot;
			}
			else if(strNum == "1")
			{
				newRoot = strScal;
				someroot = newRoot;
			}
		
			else
			{
				newRoot = strScal + "*";
				newRoot += strN + "rt:";
				newRoot += strNum;
				someroot=newRoot;
			}
		}
	}

	else if(strScal.find("-") > 100)
	{
		if(strScal == "1")
		{
			if(strN == "2" && strNum != "1")
			{
				newRoot = "sqrt:";
				newRoot += strNum;
				someroot=newRoot;
			}
			else if(strNum == "1")
			{
				newRoot = strScal;
				someroot = newRoot;
			}
		
			else
			{
				newRoot = strN + "rt:";
				newRoot += strNum;
				someroot=newRoot;
			}
		}
		else
		{
			if(strN == "2" && strNum != "1")
			{
				newRoot = strScal + "*sqrt:";
				newRoot += strNum;
				someroot=newRoot;
			}
			else if(strNum == "1")
			{
				newRoot = strScal;
				someroot = newRoot;
			}
		
			else
			{
				newRoot = strScal + "*";
				newRoot += strN + "rt:";
				newRoot += strNum;
				someroot=newRoot;
			}
		}
	}
	if(strScal == "0")
	{
		newRoot = "0";
		someroot = newRoot;
	}
}

void nthRoot::add(nthRoot& rt)
{
	if(num == rt.getNum() && n == rt.getN())
	{
		scal = scal + rt.getScal();
		formNewRoot();
	}
	else if(rt.someroot.find("-") < 100)
	{
		someroot = getSimp() + rt.getSimp();
	}
	else
	{
		someroot = getSimp() + "+" + rt.getSimp();
	}
}



void nthRoot::subtract(nthRoot& rt)
{
	if(num == rt.getNum() && n == rt.getN())
	{
		scal = scal - rt.getScal();
		formNewRoot();
	}
	else if(rt.getAns().at(0) == '-')
	{
		rt.scal = rt.scal*-1;
		someroot = getSimp() + "+" + rt.getSimp();
	}
	else
	{
		someroot = getSimp() + "-" + rt.getSimp();
	}
}

void nthRoot::multiply(nthRoot& rt)
{
	if(num == rt.getNum() && n == rt.getN())
	{
		scal = scal * rt.getScal() * num;
		formNewRoot();
		someroot = strScal;
	}
	else if(rt.getNum() == 1)
	{
		scal = scal * rt.getScal();
		formNewRoot();
	}
	
	else if(getNum() == 1)
	{
		rt.scal = scal * rt.getScal();
		cout << rt.scal << endl;
		rt.formNewRoot();
		someroot = rt.someroot;
	}
	else if(n == rt.getN())
	{
		scal = scal * rt.getScal();
		num = num * rt.getNum();
		simplify();
		someroot = getSimp();
	}
	else
		someroot = getSimp() + "*" + rt.getSimp();
}

void nthRoot::divide(nthRoot& rt)
{
	if(scal%rt.getScal() == 0)
	{
		
		if(num == rt.getNum() && n == rt.getN())
		{
			scal = scal / rt.getScal();
			formNewRoot();
			someroot = strScal;
		}
		else if(n == rt.getN() && num%rt.getNum() == 0)
		{
			scal = scal * rt.getScal();
			rt.scal = 1;
			num = num / rt.getNum();
			simplify();
			someroot = getSimp();
		}
		else
		{
			
			scal = scal / rt.getScal();
			rt.scal = 1;
			someroot = getSimp() + "/" + rt.getSimp();
		}
	}
	else 
	{
		if(scal%rt.getScal() != 0)
		{
			if(num == rt.getNum() && n == rt.getN())
			{
				someroot = strScal + "/" + rt.strScal;
			}
			else if(n == rt.getN() && num%rt.getNum() == 0)
			{
			
				int tempScalTop = scal;
				int tempScalBot = rt.getScal();
				string scalTop;
				string scalBot;
				ss << tempScalTop;
				ss >> scalTop;
				ss.clear();
				ss << tempScalBot;
				ss >> scalBot;
				strScal = "1";
				rt.strScal = "1";
				num = num / rt.getNum();
				simplify();
				someroot = scalTop + "/" + scalBot + "*" + getSimp();
		}	
		else
		{
			 
			someroot = getSimp() + "/" + rt.getSimp();
		}
	}
}


