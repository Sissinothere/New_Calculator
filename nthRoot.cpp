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

	if(someroot.at(0) == '-')
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
		
			//scal = atoi(tempScal.c_str());
			n = atoi(tempN.c_str());
			num = atoi(tempNum.c_str());
	
			scal = -1;
			this->n = n;
			this->num = num;

			simplify();
		}
	}

	else
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
		
			//scal = atoi(tempScal.c_str());
			n = atoi(tempN.c_str());
			num = atoi(tempNum.c_str());
	
			scal = 1;
			this->n = n;
			this->num = num;

			simplify();
		}
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
		cout << scal << endl;
	}
	else if(num == -1 && n%2 != 0)
	{
		isInt = true;
		scal = -scal;
		num = -num;
		cout << scal << endl;
	}
	else if(num < -1 && n%2 != 0)
	{
		scal = -scal;
		if(scal == 1)
		{
			if(n == 2)
				cout << "sqrt:" << num << endl;
			else
				cout << n << "rt:" << num << endl;
		}
		else if(scal == -1)
		{
			if(n == 2)
				cout << "-sqrt:" << num << endl;
			else
				cout <<"-" << n << "rt:" << num << endl;
		}
		else if(n == 2)
			cout << scal << "*sqrt:" << num << endl;
		else
			cout << scal << "*" << n << "rt:" << num << endl;
	}
	else if(num == -1 && n%2 == 0)
	{
		isInt = true;
		cout << scal << endl;
	}
	else if(scal == 1)
	{
		if(n == 2)
			cout << "sqrt:" << num << endl;
		else
			cout << n << "rt:" << num << endl;
	}
	else if(scal == -1)
	{
		if(n == 2)
			cout << "-sqrt:" << num << endl;
		else
			cout <<"-" << n << "rt:" << num << endl;
	}
	else if(n == 2)
		cout << scal << "*sqrt:" << num << endl;
	else
		cout << scal << "*" << n << "rt:" << num << endl;

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

	//isInt = false;
	//simplify();
	if(isInt == true)
	{
		cout << "Yes, it can be simplified into an integer." << endl;
		return true;
	}
	else
	{
		cout << "Cannot be simplified into integer." << endl;
		return false;
	}
	cout<<"------------"<<endl;
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
	formNewRoot();
	return someroot;
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
	/*
	cout << rt.getAns()<<endl;
	if(rt.getAns().at(0)=='-'){
		this->subtract(rt);
	}
	*/
	if(num == rt.getNum() && n == rt.getN())
	{
		scal = scal + rt.getScal();
		//cout << scal << endl;
		formNewRoot();
		//cout << someroot << endl;
	}
	else if(rt.someroot.find("-") < 100)
	{
		someroot = getSimp() + rt.getSimp();
	}
	else
	{
		someroot = getSimp() + "+" + rt.getSimp();
		//cout << someroot << endl;
	}
}



void nthRoot::subtract(nthRoot& rt)
{
	if(num == rt.getNum() && n == rt.getN())
	{
		scal = scal - rt.getScal();
		//cout << scal << endl;
		formNewRoot();
		//cout << someroot << endl;
	}
	else if(rt.getAns().at(0) == '-')
	{
		rt.scal = rt.scal*-1;
		someroot = getSimp() + "+" + rt.getSimp();
	}
	else
	{
		someroot = getSimp() + "-" + rt.getSimp();
		//cout << someroot << endl;
	}
}

void nthRoot::multiply(nthRoot& rt)
{
	if(num == rt.getNum() && n == rt.getN())
	{
		scal = scal * rt.getScal() * num;
		//cout << scal << endl;
		formNewRoot();
		someroot = strScal;
		//cout << someroot << endl;
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
		//formNewRoot();
		someroot = getSimp();  // + "*" + rt.getSimp();
		//cout << someroot << endl;
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
			//cout << scal << endl;
			formNewRoot();
			someroot = strScal;
			//cout << someroot << endl;
		}
		else if(n == rt.getN() && num%rt.getNum() == 0)
		{
			scal = scal * rt.getScal();
			rt.scal = 1;
			num = num / rt.getNum();
			simplify();
			//formNewRoot();
			someroot = getSimp();  // + "*" + rt.getSimp();
			//cout << someroot << endl;
		}
		else
		{
			
			scal = scal / rt.getScal();
			rt.scal = 1;
			someroot = getSimp() + "/" + rt.getSimp();
			//cout << someroot << endl;
		}
	}
	else 
	{
		if(scal%rt.getScal() != 0)
		{
			if(num == rt.getNum() && n == rt.getN())
			{
				
				//scal = scal / rt.getScal();
				//cout << scal << endl;
				//formNewRoot();
				someroot = strScal + "/" + rt.strScal;
				//cout << someroot << endl;
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
				someroot = scalTop + "/" + scalBot + "*" + getSimp();  // + "*" + rt.getSimp();
				//cout << someroot << endl;
			}
		}	
		else
		{
			 
			someroot = getSimp() + "/" + rt.getSimp();
		}
	}
}


/*
int main()
{

	string a = "4rt:8"; //change values here in order to test various cases. sqrt: works the same as 2rt:...I think
	string b = "2rt:18";  //

	nthRoot* test1 = new nthRoot(a);
	nthRoot* test2 = new nthRoot(b);
	test1->multiply(*test2);				//uncomment the operators based on which one you want to do.
	//test1->subtract(*test2);
	//test1->multiply(*test2);
	//test1->divide(*test2);
	//cout << test2->getSimp() << endl;
	cout << test1->getAns() << endl;
	//cout<<test1->getScal()<<endl;
	//cout<<test1->getN()<<endl;
	//cout<<test1->getNum()<<endl;
	//cout<<test1->getSimp()<<endl;
	//cout<<test2->getScal()<<endl;
	//cout<<test2->getN()<<endl;
	//cout<<test2->getNum()<<endl;
	//cout<<test2->getSimp()<<endl;

	return 0;
}
*/
