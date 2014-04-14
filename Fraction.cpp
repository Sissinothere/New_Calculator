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
	cout << "this is the constructor"<< endl;
	input = sValue;
	checkValues();
	cout << "post check values"<<endl;
	string temp;
	int i =0;

	cout << sValue.length()<<endl;
	while(sValue.at(i)!='/'&& !isInt){
		num += sValue.at(i);
		cout << "in loop"<<endl;
		++i;
	}
	cout << "this is the string"<< num << endl;
	num1 = atoi(num.c_str());
	if(isInt)num1 = atoi(sValue.c_str());
	cout <<"this is num1 "<< num1<<endl;
	i++;
	while(i< sValue.length()){
			den += sValue.at(i);
			i++;
		}
		den1 = atoi(den.c_str());
		if(isInt)den1=1;
		cout <<"this is den "<< den1<<endl;
cout << "right before reduction" <<endl;
	Reduction();
	checkValues();
	isInt=false;
cout <<"end of constructor "<< endl;
}

void Fraction::checkValues(){
	cout << "in check value"<<endl;
	cout << "this is the string"<< num << endl;
	string temp="";
	int i=0;
	isInt=true;
	for(int i; i<input.length();i++){
		if(input[i]=='/'){
			isInt=false;
			cout << "this is false"<<endl;
		}
	}
}
void Fraction::Reduction(){
	ostringstream convert;
	/*if(den1==0){
		cout<<"cannot solve equation!!!!"<<endl;
	}
	for(int i; i<=num1&&i<=den1;i++){
		if(num1%i==0 && den1%i ==0){

		}
	}*/
cout << "in reduction"<< endl;
cout <<"num1 in reducation"<<num1<< endl;
cout <<"den1 in reduction" << den1<<endl;
	if (num1 < den1){
		cout << "in if 1"<< endl;
		for (int i = num1; i >0; i--){
			cout <<"in for 1 "<< endl;
			if (num1%i ==0 && den1%i==0){
				num1 = num1/i;
				den1 = den1/i;
				cout << num1;
				cout << "/";
				cout << den1;

			}
		}
	}
	cout <<" after if num <"<< endl;
	if (num1 > den1){
		for(int i = den1; i >0; i--){
			if (num1%i ==0 && den1%i==0){
			num1 = num1/i;
			den1 = den1/i;
			cout << num1;
			cout <<"/"<<den1;
			}
		}
	}
	if(num1== den1){
		cout << "1";
		isInt = true;
		answer = 1;
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
		cout << answer<<endl;
}

void Fraction::Addition(Fraction& frac){
	int gcd;
	int lcd;
	 if(den1 == 0 || frac.getDenominator() == 0)
	    {
	        cout << "Cannot solve equation!!!!" << endl; //use throw catch

	    }
	   for(int i=1;i<=den1 && i<=frac.getDenominator();i++){
	      if(den1%i == 0 && frac.getDenominator()%i ==0){
	    	  	  gcd=i;
	       }else{}//do nothing;
	   	}
	    cout << "______GCD is: " << gcd << endl;
	     lcd = (den1 * (frac.getDenominator())) / gcd;
	cout << "lcd is "<<lcd<<endl;

	int frac1Mult = lcd/den1;
	int frac2Mult = lcd/frac.getDenominator();

	num1*=frac1Mult;
	int num2=frac2Mult*frac.getNumerator();

	num1= num1+num2;
	den1 = lcd;
	Reduction();

	cout <<"this is num1 right before ss "<<num1<<endl;
	cout <<"this si den 1 right before ss "<<den1<<endl;
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
	cout <<"this is the value stored at answer: "<< answer<<endl;

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
		cout << answer<<endl;
}


int Fraction::getNumerator(){
	return num1;
}
//void Fraction::setNumerator(int a){
//	num1 = a;
//}
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
