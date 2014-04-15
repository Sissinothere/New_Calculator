#include "Logs.h"
#include <stdlib.h>





Logs::Logs(string str){
	somelog = str;
	string s = "";
	string tempbase = "";
	string tempnumb = "";
	string frontnumb = "";

	int i = 0;
	bool hasE = false;
	bool hasPi = false;
	double base;
	double numb;
	double frontIntNumb;
	if(str[0]=='l'){									//check the case 3log_3:3
		frontnumb = "1";
	}
	else if(str[0]=='-'&&str[1]=='l'){
		frontnumb = "-1";
	}
	else{
		for(i;str[i]!='l' &&i<=str.length();i++){		//convert string number to type int
			frontnumb += str[i];
		}
	}

	frontIntNumb = atoi(frontnumb.c_str());


	for(i; str[i]!='_' &&i<=str.length();i++){				//try to get ride of "log_"
		s += str[i];
	}
	i++;
	//check if user enter a right format;
	if(s.find("log")<20) {}//do nothing;
	else{

		return; //exist from the function;
	}

	for(i;str[i]!=':';i++){									//to get the base from log
		if(str[i]=='e')
			hasE = true;
		if(str[i]=='p'||str[i]=='P'&&str[i+1]=='i')
			hasPi= true;
		tempbase += str[i];
	}
	strbase = tempbase;
	i++;
	for(i;i<str.length();i++){//to get the numb from log
		tempnumb += str[i];
	}
	strnumb = tempnumb;

	if(hasE)
		base = 2.71; //if base is e
	else if(hasPi)
		base = 3.14;//if base is pi
	else
		base = atoi(tempbase.c_str());				//convert string number to type int

	numb = atoi(tempnumb.c_str());



	this->numb = numb;
	this->base = base;
	this->frontIntNumb = frontIntNumb;

	if(canSimplifytoFra()||canSimplifytoInt()){

		Simplify();
	}else{

	}
}

bool Logs::canSimplifytoInt(){

	double result;
	result= log(numb)/log(base);

	if(ceil(result)==floor(result)){
		return true;
	}
	else{
		return false;
	}
 }

bool Logs::canSimplifytoFra(){

	double result;
	result= log(base)/log(numb);

	if(ceil(result)==floor(result))
		return true;
	else
		return false;
}

void Logs::Simplify(){

	double result;
	string value;


	if(canSimplifytoInt()){
		result= log(numb)/log(base);
		ss<<result;
		ss>>value;
		ss<<getFrontIntNumb();
		somelog = value;
	}
	else if(canSimplifytoFra()){
		result = log(base)/log(numb);
		ss<<result;
		ss>>value;
		value ="1/"+value;
		somelog = value;
	}
	else{}
	cout <<"str base is "<< strbase<<endl;
	cout <<"str numb is "<<strnumb<<endl;
}

string Logs::getSimplify(){
	string temp;

	ss.clear();
	ss<<getFrontIntNumb();
	ss>>temp;
	if(canSimplifytoFra()||canSimplifytoInt()){
		if(getFrontIntNumb()==1){
			cout <<"this is strnumb[2]"<< strnumb[2]<<endl;
				if (strbase[0]=='e'&& strnumb[0]=='e'&&strnumb.length()>2){
					somelog = strnumb[2];
				}
				if (strbase[0]=='p'&& strnumb[0]=='p'&&strnumb.length()>3){
									somelog = strnumb[3];
								}
				if(strbase == strnumb){
					somelog = "1";
				}
			return somelog;
		}else if(getFrontIntNumb()==-1){
			return "-"+somelog;
		}

	}
	else{
		temp =somelog;
		cout <<"this is strnumb[2]"<< strnumb[2]<<endl;

	}


	return temp;
}

string Logs::FinalSplit(){
	string tempString;
	int two=0;
	int three = 0;
	int five = 0;
	int seven = 0;
	int eleven = 0;
	int thirteen = 0;
	int temp = (int)numb;
	bool cansplit = false;

	if(temp%2==0){//if i1 can divide by two
		cansplit = true;
		for(temp; temp>=2&&temp%2==0;temp/=2){
			two++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":2";//here need overloading
		}

	}if(temp%5==0){//if it can divide by 5
		cansplit = true;
		for(temp; (temp>=5&&temp%5==0);temp/=5){
			five++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":5";//here needs overloading.
		}

	}if(temp%3==0){ //if it can divide by 3
		cansplit = true;
		for(temp; temp>=3&&temp%3==0;temp/=3){
			three++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":3";
		}

	}if(temp%11==0){//if it can devide by 11
		cansplit = true;
		for(temp;temp>=11&&temp%11==0;temp/=11){
			eleven++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":11";
		}

	}if(temp%7==0){ //if it can divide by 7
		cansplit = true;
		for(temp;temp>=7&&temp%7==0;temp/=7){
			seven++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":7";
		}
	 }if(temp%13==0){ //if it can divide  by 7
		 cansplit = true;
		for(temp;temp>=13&&temp%13==0;temp/=13){
			thirteen++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":13";
		}
	 }
	 if(!cansplit){ //non of these case, return as it is.
		 return somelog;
	 }
//
	 //here I return a new string Final, but I can alwasy let somelog = Final
	 // and change the value using pointer., no need to return.
	 string Final = "";//get ride of first '+' sign
	 for(int i = 1; i < tempString.length();i++){
		 Final+=tempString[i];
	 }

	 somelog=Final;
	 return Final;
}

double Logs::getBase(){
	return base;
}
double Logs::getNumb(){
	return numb;
}
double Logs::getFrontIntNumb(){
	return frontIntNumb;
}
string Logs::getAnswer(){


	return somelog;
}


void Logs::FormNewLog(){
	string newlog;
	ss<<frontIntNumb;			//conver front number to string
	ss>>strfronumb;
	ss.clear();
	ss<<numb;					//conver numb to string
	ss>>strnumb;
	ss.clear();
	ss<<base;					//conver base to string
	ss>>strbase;
	ss.clear();
	if(canSimplifytoInt()&&canSimplifytoFra()){	//if newlog is a integer or a fraction
		//do nothing
	}
	else{
		newlog = strfronumb + "log_" + strbase;
		newlog += ":" + strnumb;
	}
	somelog=newlog;

}

void Logs::add(Logs& lg){ //need to conver double to string.
	if(frontIntNumb<0||lg.getFrontIntNumb()<0){
		substract(lg);

	}
	else if(lg.getBase()==base&&lg.getNumb()==numb){

		frontIntNumb +=lg.getFrontIntNumb();
		FormNewLog();

	}

	else if(lg.getBase()==base){

		this->numb *= lg.getNumb();
		FormNewLog();//update

	}
	else{
		somelog += "+" + lg.getAnswer();//two string can add tegether.
	}
}

void Logs::substract(Logs& lg){
	if(lg.getBase()==base&&lg.getNumb()==numb){


		frontIntNumb +=lg.getFrontIntNumb();
		FormNewLog();
	}else{
		somelog += "-" + lg.getAnswer();//two string can add tegether.
	}
}
void Logs::divide(Logs& lg){ // if
	 if(lg.getBase()==base&&lg.getNumb()==numb){
		frontIntNumb /=lg.getFrontIntNumb();
		FormNewLog();
 	}else if(base == lg.getBase()){
 		this->numb /= lg.getNumb();
 		FormNewLog();
 	}
	 else{
		somelog += "/" + lg.getAnswer();
	}
}
void Logs::Multip(Logs& lg){
	 if(lg.getBase()==base&&lg.getNumb()==numb){
		frontIntNumb *=lg.getFrontIntNumb();
 		FormNewLog();
 	}else{
		somelog += "*" + lg.getAnswer();
	}
}
