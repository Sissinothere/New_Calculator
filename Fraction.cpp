#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <cmath>
#include <string>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(string sValue){
	isInt= false;
	input = sValue;
	checkValues();

	string temp;
	int i =0;

	cout << sValue.length()<<endl;
	while(sValue.at(i)!='/'&& !isInt){
		num += sValue.at(i);
		++i;
	}
	num1 = atoi(num.c_str());
	if(isInt)num1 = atoi(sValue.c_str());
	i++;
	while(i< sValue.length()){
			den += sValue.at(i);
			i++;
		}
		den1 = atoi(den.c_str());
		if(isInt)den1=1;
	Reduction();
	//checkValues();
	isInt=false;

}

void Fraction::checkValues(){

	string temp="";
	int i=0;
	isInt=true;
	for(i; i<input.length();i++){
		if(input[i]=='/'){
			isInt=false;
		}
	}
}
void Fraction::Reduction(){
	ostringstream convert;



	if (num1 < den1){
		for (int i = num1; i >0; i--){
			cout <<"in for 1 "<< endl;
			if (num1%i ==0 && den1%i==0){
				num1 = num1/i;
				den1 = den1/i;


			}
		}
	}

	if (num1 > den1){
		for(int i = den1; i >0; i--){
			if (num1%i ==0 && den1%i==0){
			num1 = num1/i;
			den1 = den1/i;

			}
		}
	}
	if(num1== den1){
		isInt = true;
		answer = "1";
		num1 = 1;
		den1 = 1;

	}else{

	stringstream ss;
		ss<< num1;
		ss<< "/";
		ss<< den1;
		answer = ss.str();
		if(isInt){
			ss.str("");
					ss<< num1;
					answer = ss.str();
		}

	}
	if(num1==0){
				answer="0";
				isInt=true;
			}
		cout << answer<<endl;
}

void Fraction::Addition(Fraction& frac){
	int gcd;
	int lcd;
	 if(den1 == 0 || frac.getDenominator() == 0)
	    {
	    }
	   for(int i=1;i<=den1 && i<=frac.getDenominator();i++){
	      if(den1%i == 0 && frac.getDenominator()%i ==0){
	    	  	  gcd=i;
	       }else{}//do nothing;
	   	}
	     lcd = (den1 * (frac.getDenominator())) / gcd;


	int frac1Mult = lcd/den1;
	int frac2Mult = lcd/frac.getDenominator();

	num1*=frac1Mult;
	int num2=frac2Mult*frac.getNumerator();

	num1= num1+num2;
	den1 = lcd;
	Reduction();


	stringstream ss;
	ss<< num1;
	ss<< "/";
	ss<< den1;
	answer = ss.str();
	if(isInt){
		ss.str("");
						ss<< num1;
						answer = ss.str();
			}


}
void Fraction::Multiplication(Fraction& frac){
	num1*=frac.getNumerator();
	den1*=frac.getDenominator();
	Reduction();
	stringstream ss;
		ss<< num1;
		ss<< "/";
		ss<< den1;
		answer = ss.str();
		if(isInt){
			ss.str("");
							ss<< num1;
							answer = ss.str();
				}
		cout << answer<<endl;
}
void Fraction::Division(Fraction& frac){
	num1*=frac.getDenominator();
	den1*=frac.getNumerator();
	Reduction();
	stringstream ss;
		ss<< num1;
		ss<< "/";
		ss<< den1;
		answer = ss.str();
		if(isInt){
			ss.str("");
							ss<< num1;
							answer = ss.str();
				}
}


int Fraction::getNumerator(){
	return num1;
}

int Fraction::getDenominator(){
    return den1;
}
string Fraction::getAnswer(){
    return answer;
}
bool Fraction::canSimplifytoInteger(){
	checkValues();
	Reduction();
	return isInt;
}
