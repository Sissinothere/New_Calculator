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



StringReader::StringReader(string input){
	this->input = input;
	complexC = 0;
}

void StringReader::Inject(){
	int tempL= input.length();
	for (int i = 0; i < input.length();i++){
		tempL= input.length();
		if (input.at(i)=='-'&&input.at(i-1)=='-'){
			////cout << "before erase "<<input<<endl;
			input.erase(i,1);
			input.erase(i-1,1);

			input.insert(i-1,1,'+');

		}
		if (tempL!=input.length()) i =0;
	}
	////cout << input<<endl;
	tempL= input.length();
	for (int i = 0; i < input.length();i++){
		tempL= input.length();

		if ((input.at(i)=='-'&&(int(input.at(i-1)) <= 57 && int(input.at(i-1)) >= 48))||(input.at(i)=='-'&&(int(input.at(i-1)) <= 105 && int(input.at(i-1)) >= 100))){



			input.insert(i,1,'+');

		}
		if (tempL!=input.length()) i =0;
	}
	////cout << input<<endl;
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

	if (!isParen()){
		return "no more parenthesis";
	}

	for (int i =0;i < input.length();i++){

		if (input.at(i)==')'){
			input.erase(i,1);

			i--;
			endPos = i-1;//sets start position for in paren calculations

			for(i; i >=0; i--){
				if(input.at(i) == '('){
					input.erase(i,1);

					startPos = i;

					for (startPos; startPos<=endPos;startPos++){
						result += input.at(startPos);
						input.erase(i,1);
						endPos--;
						startPos--;

					}




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


					////////////////////////////////////////////////////////////////
					//this does distribution below
					///////////////////////////////////////////////////////////
					/////////////////////////////////////////////////////////////

					int lengthy= input.length();
					if(lengthy >2){
						////cout << "this is the last thing of input hopefully : "<<input.at(lengthy-2)<<endl;
					}


					string ifComplex;
					if(lengthy >2){
						if ((nbr->ansIsComplex()&&input.at(lengthy-2)=='*'&&complexC <1)||(nbr->ansIsComplex()&&input.at(lengthy-2)=='/'&&complexC <1)){

							if(input.at(lengthy-2)=='/') {isDiv = true;}else{
								isDiv = false;
							}
							complexC++;
							string resulty = input;
							stringstream cp;
							cp << '[';
							cp << nbr->getFinalAnswer();
							cp << ']';


							input.insert(endPos+1,cp.str());

							ifComplex = input;

							ifComplex.erase(ifComplex.begin());
							ifComplex.erase(ifComplex.end()-1);

							//maybe look for only final pair of parenthesis before handling foiling


							stringstream comp;
							string dist;
							int tempsub =2;
							for(int k = 0; k < ifComplex.length();k++){

								if (ifComplex.at(k)=='['){
									ifComplex.erase(ifComplex.begin()+k);

									if (ifComplex.at(k-1)=='*'||ifComplex.at(k-1)=='/'){
										ifComplex.erase(ifComplex.begin()+k-1);


										comp << ifComplex.at(k-2);
										dist += ifComplex.at(k-2);
										ifComplex.erase(ifComplex.begin()+k-2);

										if(lengthy>6){
											if(ifComplex.at(k-3)!='+'){// add stuff for * maybe

												comp << ifComplex.at(k-3);
												dist +=ifComplex.at(k-3);
												tempsub+=1;
											}
										}

										if (isDiv){
											comp << '/';
										}else{
											comp << '*';
										}
										//cout << ifComplex<<endl;
										int erase = 0;
										for(int z = k-tempsub; z < ifComplex.length()&&ifComplex.at(z)!='+';z++){
											comp << ifComplex.at(z);
											erase++;
										}

										ifComplex.erase(ifComplex.begin()+k-tempsub,ifComplex.begin()+erase+lengthy-4);//has erase +2
										comp << ifComplex.at(k-tempsub);
										ifComplex.erase(ifComplex.begin()+k-tempsub);
										//cout << "this is k: "<<k<<"this is tempsub: "<<tempsub<<endl;

										int erase2;

										for (int v = k-tempsub; ifComplex.at(v)!= ']';v++){
											comp << ifComplex.at(v);
											erase2++;
										}

										if (isDiv){
											comp << '/';
										}else{
											comp << '*';
										}
										comp << dist;

										ifComplex.erase(ifComplex.begin()+k-tempsub,ifComplex.begin()+erase2+lengthy-3);//was +3

										string here = comp.str();
										ifComplex.insert(k-tempsub, here);
									}

								}
							}

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


					return Parenthesis();

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
