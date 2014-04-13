//============================================================================
// Name        : StringReader.cpp
// Author      : John Harrison
// Version     :
// Copyright   : Do not distribute
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "StringReader.h"
#include "NobracketString.h"
#include <iostream>
#include <vector>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include <stdlib.h>

using namespace std;

//pass a string to nobracketstring without parenthesis
//replace result and get rid of parenthesis and get next set of parens.
//look to deal with 2(x+y-log)

//check for number next to logs or sqrts eg. 2log, 2srt


StringReader::StringReader(string input){
	this->input = input;

}

void StringReader::Inject(){
	int tempL= input.length();
	for (int i = 0; i < input.length();i++){
		tempL= input.length();
		if (input.at(i)=='-'&&input.at(i-1)=='-'){
			cout << "before erase "<<input<<endl;
			input.erase(i,1);
			input.erase(i-1,1);
			cout <<"afetr erase "<< input << endl;
			input.insert(i-1,1,'+');
			cout << "after inject "<<input<<endl;
		}
		if (tempL!=input.length()) i =0;
	}
	cout << input<<endl;
	 tempL= input.length();
		for (int i = 0; i < input.length();i++){
			tempL= input.length();
			// cout << "right before if statement"<<endl;
			if ((input.at(i)=='-'&&(int(input.at(i-1)) <= 57 && int(input.at(i-1)) >= 48))||(input.at(i)=='-'&&(int(input.at(i-1)) <= 105 && int(input.at(i-1)) >= 100))){
				cout << "before erase "<<input<<endl;
				//input.erase(i,1);
				//input.erase(i-1,1);
				cout <<"afetr erase "<< input << endl;
				input.insert(i,1,'+');
				cout << "after inject "<<input<<endl;
			}
			if (tempL!=input.length()) i =0;
		}
		cout << input<<endl;
}

bool StringReader::isParen(){
	for(int i= 0; i < input.length(); i++){
				if(input.at(i) == '('){
					return true;
				}
	}
	return false;
}
string StringReader::Parenthesis(){

	int startPos;
	int endPos;
	string result = "";
	if (!isParen()){
		return "no more parenthesis";
	}
	//cout <<"beginning of function"<< endl;
	cout << input<<endl;
	//cout << input.length()<<endl;
if (!isParen()){
	return "no more parenthesis";
}

for (int i =0;i < input.length();i++){

	if (input.at(i)==')'){
		input.erase(i,1);
		//cout << input<< endl;
		i--;
		endPos = i-1;//sets start position for in paren calculations
		//cout <<"endpos"<< endPos<<endl;
		//cout << "i is " << i<< endl;
		for(i; i >=0; i--){
			if(input.at(i) == '('){
				input.erase(i,1);
				//cout << input << endl;
				//i++;
				startPos = i;
				//cout <<"starpos"<< startPos<< endl;
				for (startPos; startPos<=endPos;startPos++){
					result += input.at(startPos);
					input.erase(i,1);
					endPos--;
					startPos--;

				}
				//cout << result<<endl;
				//cout << input << endl;
				//cout << endPos<< endl;
				cout << "This is whats passed to NobracketString: "<<result <<endl;

				//here put the function to find pi's and e's here

				NobracketString* nbr = new NobracketString(result);
				stringstream fa;
				fa<<result << " = "<< nbr->getFinalAnswer();
				finalAnswer = fa.str();
				nbr->ansIsComplex();
				cout<<"============================================="<<endl;
				cout<<"the answer is:"<<endl;
				cout<<result + " = "<< nbr->getFinalAnswer()<<endl;
				cout<<"============================================="<<endl;

				//test if there is anything except 0-9, if there is, add square brackets
				//if there is sqaure brackets you test if there is anything to distribute
/*
				if (nbr->ansIsComplex()){
					stringstream cp;
					cp << '[';
					cp << nbr->getFinalAnswer();
					cp << ']';
				}
				//maybe look for only final pair of parenthesis before handling foiling
				for(int k = 0; k < nbr->getFinalAnswer().length();k++){
					if (nbr->getFinalAnswer().at(i)=='['){
						//if (nbr->)
					}
				}


*/
				input.insert(endPos+1,nbr->getFinalAnswer());


				return Parenthesis();
				return result;
			}

		}
	}
}
//make revcursive base cases
return "";
}

string StringReader::getFinalAnswer(){
	return finalAnswer;
}

