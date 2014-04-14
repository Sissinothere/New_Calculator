/*
 * StringReader.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef STRINGREADER_H_
#define STRINGREADER_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringReader {
	bool isDiv;
	int complexC;
	string input;
	string finalAnswer;

public:

	void Inject();
	string Parenthesis();
	bool isParen();
	StringReader(string input);
	//StringReader();
	//virtual ~StringReader();
	string getFinalAnswer();
};

#endif /* STRINGREADER_H_ */

