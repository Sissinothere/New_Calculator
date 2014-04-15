
#ifndef NTHROOT_H_
#define NTHROOT_H_
#include <strstream>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;

class nthRoot
{
	strstream ss;
	string someroot;
	string strN;
	string strNum;
	string strScal;
	int n;
	int num;
	int scal;
	bool isInt;
	bool isFrac;

	public:
		nthRoot(string str);
		~nthRoot();
		bool canSimpifytoFrac();
		bool canSimplifytoInt();
		void add(nthRoot& rt);
		void subtract(nthRoot& rt);
		void multiply(nthRoot& rt);
		void divide(nthRoot& rt);
		void primeFactors(int num, std::vector<int>&  factors, int div);
		void simplify();
		int power(int base, int pow);
		int getN();
		int getNum();
		int getScal();
		string getSimp();
		string getAns();
		void formNewRoot();

};
#endif
