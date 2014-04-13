/*
 * NobracketString.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Sissi
 *
 */

#ifndef NOBRACKETSTRING_H_
#define NOBRACKETSTRING_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NobracketString {
	string expression;
	string FiAnswer; 					//final return answer, combine with vector somenumb and op;
	string opAnswer;						// store numb op numb return value;
	vector<string> somenumbs; 				//store value;
	vector<char> op; 						//store "+""-""*""/"
	//vector<int> mutiposition;
	vector<string> type; 					//store name of the type
	bool isReturnOneNumb;
	//int MutiPosition;						//the * index position

public:
	NobracketString(string expression);
	void separateString();
	void simplifynumbers();
	string getFinalAnswer();
//	bool checksametype(string strA, string strB);
//	int findOpMutiPosition();
	void add(string Anumb,string Atype,string Bnumb,string Btype);
	void substract(string Anumb, string Atype, string Bnumb, string Btype);
	void divide(string Anumb, string Atype, string Bnumb, string Btype);
	void Multip(string Anumb, string Atype, string Bnumb, string Btype);
	void Expon(string Anumb,string Atype, string Bnumb,string Btype);
	virtual ~NobracketString();
	void calculating();
	void formFinalAnser();
	bool ansIsComplex();

};

#endif /* NOBRACKETSTRING_H_ */
