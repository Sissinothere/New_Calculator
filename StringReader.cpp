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
	complexC = 0;
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
cout<< "this is right before distribute: "<< endl;
cout <<"this is input currently : "<<input<<endl;

////////////////////////////////////////////////////////////////
//this does distribution below
	///////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////

int lengthy= input.length();
if(lengthy >2){
cout << "this is the last thing of input hopefully : "<<input.at(lengthy-2)<<endl;}
//int lengthy= input.length();
cout << "lol"<<endl;
					string ifComplex;
					if(lengthy >2){
					if ((nbr->ansIsComplex()&&input.at(lengthy-2)=='*'&&complexC <1)||(nbr->ansIsComplex()&&input.at(lengthy-2)=='/'&&complexC <1)){
						cout <<"in the complex dist "<<endl;
						if(input.at(lengthy-2)=='/') {isDiv = true;}else{
							isDiv = false;
						}
						complexC++;
						string resulty = input;
						stringstream cp;
						cp << '[';
						cp << nbr->getFinalAnswer();
						cp << ']';

						cout <<"this is cp str "<< cp.str()<<endl;
						cout <<"input pre insert"<< input<< endl;
						input.insert(endPos+1,cp.str());

						ifComplex = input;
						cout << "this is ifComplex "<< ifComplex<<endl;
						ifComplex.erase(ifComplex.begin());
						ifComplex.erase(ifComplex.end()-1);
						//ifComplex.erase(ifComplex.begin)
					//maybe look for only final pair of parenthesis before handling foiling


						stringstream comp;
					string dist;
					int tempsub =2;
					for(int k = 0; k < ifComplex.length();k++){
						cout <<ifComplex<<endl;
						if (ifComplex.at(k)=='['){
							ifComplex.erase(ifComplex.begin()+k);
							cout << ifComplex<<endl;
							cout << ifComplex.at(k-1)<<endl;
							if (ifComplex.at(k-1)=='*'||ifComplex.at(k-1)=='/'){
								ifComplex.erase(ifComplex.begin()+k-1);
								cout << ifComplex <<endl;
								//comp << '(';
								comp << ifComplex.at(k-2);
								dist += ifComplex.at(k-2);
								ifComplex.erase(ifComplex.begin()+k-2);
								cout << "right after deleting dist " << endl;
								cout << "this is lengthy " <<lengthy<< endl;
								if(lengthy>6){
								if(ifComplex.at(k-3)!='+'){// add stuff for * maybe

									comp << ifComplex.at(k-3);
									dist +=ifComplex.at(k-3);
									tempsub+=1;
								}
							}
								cout <<"after where i thought the problem was "<<endl;
								if (isDiv){
									comp << '/';
								}else{
								comp << '*';
								}
								cout << ifComplex<<endl;
								int erase = 0;
								for(int z = k-tempsub; z < ifComplex.length()&&ifComplex.at(z)!='+';z++){
									comp << ifComplex.at(z);
									erase++;
								}
								cout <<"after this for loop this is value fo erase"<< erase<<  endl;
								ifComplex.erase(ifComplex.begin()+k-tempsub,ifComplex.begin()+erase+lengthy-4);//has erase +2
								cout <<"after this line check erases "<< lengthy-4<<endl;
								cout << ifComplex<<endl;
								comp << ifComplex.at(k-tempsub);
								cout <<"after this line2 "<< endl;
								ifComplex.erase(ifComplex.begin()+k-tempsub);
								cout <<"after this line3 "<< endl;
								cout << "this is k: "<<k<<"this is tempsub: "<<tempsub<<endl;
								//cout << "this is the number "<< ifComplex.at(k-tempsub)<<endl;
								int erase2;
								cout <<" after problem line "<<ifComplex<<endl;
								for (int v = k-tempsub; ifComplex.at(v)!= ']';v++){
									comp << ifComplex.at(v);
									erase2++;
								}
								cout <<"if complex again "<<ifComplex<<endl;
								cout << "after problem loop "<<endl;
								if (isDiv){
									comp << '/';
								}else{
								comp << '*';
								}
								comp << dist;
								//comp << '*';
								ifComplex.erase(ifComplex.begin()+k-tempsub,ifComplex.begin()+erase2+lengthy-3);//was +3
								//comp << ifComplex.at(k);
								//cout << comp.str();
								string here = comp.str();
								ifComplex.insert(k-tempsub, here);
							}

						}
					}
					string cat ="ewhat tjhe hell";
					cat.insert(6,"lol");
					cout <<"this is cat "<< cat<< endl;

					cout << "this is dist "<<dist << endl;
					cout <<"this is end comp "<< comp.str() << endl;
					cout <<"this is the inital input str "<< ifComplex<<endl;

					resulty.insert(endPos+1,ifComplex);
					stringstream theEnd;
					theEnd << '(';
					theEnd << ifComplex;
					theEnd << ')';
					input = theEnd.str();
					//add parens to input
					return Parenthesis();
					}
					}
					cout << "lol1"<<endl;
					////////////////////////////////////////////////////////////
					//end of distribution handling
					/////////////////////////////////////////////
					////////////////////////

					if (complexC==1){
						complexC++;
						stringstream adp;
						adp <<'(';
						adp << nbr->getFinalAnswer();
						adp<<')';
						input = adp.str();
						return Parenthesis();
					}
					input.insert(endPos+1,nbr->getFinalAnswer());

					cout << "this is input right before parenthesis" <<input << endl;
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
