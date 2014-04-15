#include "NobracketString.h"
#include "Logs.h"
#include "Integers.h"
#include "nthRoot.h"
#include "Pi.h"
#include "Exponential.h"
#include "Exponent.h"
#include "Fraction.h"


/*
update (4/8):
	1. This class will expected to receive a string of expression, (no brackets);
	and seperate them into two vectors. one stores value, the other store op;
	2.it will simplify each type of the value by creating a new type object.
	3. and it will recieve a new simplfy string from the correspoinding class.
	4. and then it will do the operator, check vector op first, if it contains'*', do the * operations, and then if it only has +,-, check vector somnumbs and find the same type and do the corresponding calculation.
	5. after checking all the types throught the type vectors, and we do all we can to calculater, the answer = somenumb[0]+type[0]+somenumb[1]+type[1]+....
	5. still working on it. =)
*/
/*
update(4/9)
	1. add findOpMutiPosition(), calculating() functions to the class
example:
log_3:4 + 2/3 * 7 + 9

somenumb	op		type	index

log_3:4		+		log		0
2/3			*		frac	1
7			+		int		2
9					int		3
	2.	in this case, first we need to find * , so the findOpMutiPosition() will handle this steps, if it has "*", it will return the index position of *,
	 		if it does not have, return -1;
	3.	and then the calculating () function will assign the calculation to each operator.
			#it check the return value of the findOpMutiPosition(),
				base on the return value, if it's a -1, it will compare type vector, one by one, if it has same type, or(frac, and int), depends on the op vector, if will call the corresponding operator function.

*/
/*
 * THIS CODE only can do Logs calculation because I don't have anyother type of class I can test.
 * Integer,Pi,E,NthRoot,Fraction class if you can provide any of these class will be great.
 * I will try to work on Integer class and then I can test integer and Logs type together.
 *
 */



NobracketString::NobracketString(string expression) {
	// TODO Auto-generated constructor stub
	this->expression=expression;

	separateString();
	simplifynumbers();
	calculating();
	formFinalAnser();
}

NobracketString::~NobracketString() {
	// TODO Auto-generated destructor stub
}

void NobracketString:: separateString(){
											//separateString and store them in the vector somenumbs


	string temp;
	bool hasTwoOp=false;

	string checkop ="";
	for(int i=0;i<expression.length();i++){


			if(expression[i]=='+'||expression[i]=='*'){
				op.push_back(expression[i]);

				somenumbs.push_back(temp);
				temp = "";
			}
			else if((expression[i]=='^'||expression[i]=='/')&& !hasTwoOp){

				if(expression[i]=='^'){					//if k is  ^, keep it to tem[;]

					for(int k=i;k<expression.length();k++){	//check after ^ if it has / or not;
						//check for if it has / or not.

						if(expression[k]=='/'){

							hasTwoOp=true;

						}else{


						}
					}
				}
				else{									//if k is /
					for(int k=i;k<expression.length();k++){	//check after ^ ifit has / or not;

						if(expression[k]=='^'){

							hasTwoOp=true;
						}else{

						}
					}
				}

			}
				if(hasTwoOp){

					if(expression[i]=='/'){				//if has / record,



						temp +=expression[i];

					}else{
						temp +=expression[i];
					}
				}
				else if(!hasTwoOp&&expression[i]!='+'&&expression[i]!='*'){

					temp +=expression[i];

				}

	}
	somenumbs.push_back(temp);




}

void NobracketString::simplifynumbers(){ //maybe need to delete the object I create here.
	for(int i = 0; i<somenumbs.size();i++){

	string tempnumb = somenumbs[i];

	if(tempnumb.find("^")<100 && tempnumb.find("log")>100){ /////this lines needs to go into
			Exponent* power = new Exponent(somenumbs[i]);
			somenumbs[i]=power->getAnswer();

			if(power->canSimplifyToInt()){
				type.push_back("int");
			}else if(power->canSimplifyToFrac()){
				type.push_back("frac");
			}else{
				type.push_back("exp");
			}
		}
	else if(tempnumb.find("rt")<100){
			nthRoot* power = new nthRoot(somenumbs[i]);
													//will do the simplification in constructor.
			somenumbs[i]=power->getSimp();		//get a string type


			if(power->canSimplifytoInt()){
				type.push_back("int");

			}
			else if(power->canSimpifytoFrac()){
				type.push_back("frac");
			}else{

				type.push_back("root");
			}
		}

	else if(tempnumb.find("/")<100 && tempnumb.find("p")>100){					//im each value, if it contains /,

		Fraction* fra = new Fraction(somenumbs[i]);
		somenumbs[i]=fra->getAnswer();	//change the vector number to the 		simplify number.

 		tempnumb = fra->getAnswer();



		if(fra->canSimplifytoInteger())	{		//if it simplifies to int

			type.push_back("int");	}		// put "int" in the vector type;
		else{

			type.push_back("frac");
		}
	}

	 else if(tempnumb.find("log")<100){
	    		Logs* lg = new Logs(somenumbs[i]);
	    		somenumbs[i]=lg->getSimplify();

	    		if(somenumbs[i]==expression){					//if user enter a log only and it cannot be simplify
	    //
	    			expression = lg->FinalSplit();				//try split it;

	    			if(somenumbs[i]==expression){
	    							//if the log cannot be split, do nothing.
	    			}else{
	    				somenumbs.erase(somenumbs.begin());
	    				type.clear();

	    				separateString();

	    				simplifynumbers();
	    			}
	    		}

	    		if(lg->canSimplifytoInt()){			//check if it can be simplified

	    			type.push_back("int");

	    											//if it simplifies to int, put "int" to vector type;
	    		}
	    		else if(lg->canSimplifytoFra()){
	    			type.push_back("frac");
	    				//else if it simplifies to fraction, put "fra" to vector type;
	    		}else{
	    				type.push_back("log");							////cout<<"in the log to log here"<<endl;
	    		}
	    	}
	else if(tempnumb.find("Pi")<100||tempnumb.find("pi")<100){
		type.push_back("pi");
	}
	else if(tempnumb.find("e")<100){
			type.push_back("e");
	}else{
			type.push_back("int");
		}
}


}

string NobracketString::getFinalAnswer(){
	return FiAnswer;
}


void NobracketString::add(string Anumb, string Atype, string Bnumb, string Btype){ 		//does not need to handle differen type here only handel same type or (fraction and integer)
	if(Atype==Btype){						//if they are the same type;
		if(Atype == "frac")
		{

			Fraction* fra = new Fraction(Anumb);
			Fraction* frb = new Fraction(Bnumb);
			fra->Addition(*frb);
			opAnswer = fra->getAnswer();

			isReturnOneNumb = true;
										//same type fraction should always return one numb
												//delete[] fra;				// here may need to delete the object.
		}
		else if(Atype == "int")
		{
			Integers* intnumbA = new Integers(Anumb);
			Integers* intnumbB = new Integers(Bnumb);
			intnumbA->Add(*intnumbB);
			opAnswer = intnumbA->getAnswer();
					////							//delete[] intnumb;
			isReturnOneNumb = true;
		}
		else if(Atype=="log")
		{

			Logs* lgA = new Logs(Anumb);
			Logs* lgB = new Logs(Bnumb);
			lgA->add(*lgB);
			opAnswer = lgA->getAnswer();
												//delete[] lg;
			if(opAnswer.find("+")<100)			//if the opanswer string contains "+", means it return a complex expression
				isReturnOneNumb = false;
			else
				isReturnOneNumb = true;
		}
		else if(Atype=="root")
		{
			nthRoot* nthNumb = new nthRoot(Anumb);
			nthRoot* B = new nthRoot(Bnumb);
			nthNumb->add(*B);
			opAnswer = nthNumb->getAns();

			if(opAnswer.find("+")<100)			//if the opanswer string contains "+", means it return a complex expression
				isReturnOneNumb = false;
			else
				isReturnOneNumb = true;
		}//it is handled in the calculating()
		else if(Atype=="pi"){
//
			isReturnOneNumb = true;
		}
		else if(Atype=="e"){
			Exponential* p = new Exponential(Anumb);
			p->Add(*p);
			opAnswer = p->getAnswer();
			isReturnOneNumb = true;
		}else if(Atype=="exp"){

		}
	}else{	//if not the same type

			 if((Atype=="root"&&Btype=="int")||(Btype=="int"&&Atype=="root")){

				nthRoot* nthNumb = new nthRoot(Anumb);
				nthRoot* B = new nthRoot(Bnumb);
				nthNumb->add(*B);

				opAnswer = nthNumb->getAns();

							if(opAnswer.find("*")<100)			//if the opanswer string contains "+", means it return a complex expression
								isReturnOneNumb = true;
							else
								isReturnOneNumb = true;
						}
		}
}

void NobracketString::substract(string Anumb,string Atype, string Bnumb, string Btype){				//does not need to handle differen type here only handel same type or (fraction and integer)

	isReturnOneNumb = false;
		if(Atype==Btype){						//if they are the same type;
			if(Atype == "frac")
			{
				Fraction* fra = new Fraction(Anumb);
				Fraction* frb = new Fraction(Bnumb);
				//fra->Subtraction(*frb);
				opAnswer = fra->getAnswer();
				isReturnOneNumb = true;				// here may need to delete the object.
			}
			else if(Atype == "int")
			{
				Integers* intnumbA = new Integers(Anumb);
				Integers* intnumbB = new Integers(Bnumb);
				intnumbA->Subtract(*intnumbB);

				opAnswer = intnumbA->getAnswer();

									////							//delete[] intnumb;
				isReturnOneNumb = true;
			}
			else if(Atype=="log")
			{
				Logs* lgA = new Logs(Anumb);
				Logs* lgB = new Logs(Bnumb);
				lgA->substract(*lgB);
				opAnswer = lgA->getAnswer();
											//delete[] lg;
				if(opAnswer.find("-")<100)
				{								//if the opanswer string contains "+", means it return a complex expression
					isReturnOneNumb = false;
				}
				else
					isReturnOneNumb = true;
			}
			else if(Atype=="root")
			{
				nthRoot* nthNumb = new nthRoot(Anumb);
				nthRoot* B = new nthRoot(Bnumb);
				nthNumb->subtract(*B);
				opAnswer = nthNumb->getAns();
				if(opAnswer.find("-")<100)			//if the opanswer string contains "+", means it return a complex expression
					isReturnOneNumb = false;
				else
					isReturnOneNumb = true;
			}//it is handled in the calculating()
			else if(Atype=="pi"){
//				Pi* p = new Pi(Anumb);
//				p->Subtract(*p);
//				opAnswer = p->getAnswer();
				isReturnOneNumb = true;
			}
			else if(Atype=="e"){
				Exponential* p = new Exponential(Anumb);
				Exponential* b = new Exponential(Bnumb);
				//p->Subtract(*b);
				opAnswer = p->getAnswer();
				isReturnOneNumb = true;
			}
			else if(Atype=="exp"){
				Exponent* power = new Exponent(Anumb);
				Exponent* b = new Exponent(Bnumb);
				power->subtract(*b);
				opAnswer = power->getAnswer();
				if(opAnswer.find("-")<100)			//if the opanswer string contains "+", means it return a complex expression
					isReturnOneNumb = false;
				else
					isReturnOneNumb = true;
			}
		}else{	//if not the same type

		}
}
void NobracketString::divide(string Anumb,string Atype, string Bnumb, string Btype){			//need to handle different types calculation, basicly differen type just return as it is.

	isReturnOneNumb = false;
			if(Atype==Btype){						//if they are the same type;
				if(Atype == "frac")
				{
					Fraction* fra = new Fraction(Anumb);
					Fraction* frb = new Fraction(Bnumb);
					fra->Division(*frb);
					opAnswer = fra->getAnswer();
					isReturnOneNumb = true;				// here may need to delete the object.
				}
				else if(Atype == "int")
				{
					Integers* intnumbA = new Integers(Anumb);
					Integers* intnumbB = new Integers(Bnumb);
					intnumbA->Divide(*intnumbB);
					opAnswer = intnumbA->getAnswer();					//!!!!!here type has to be a "frac"!!!!!


							////							//delete[] intnumb;
//					if(opAnswer.find("/")<100)
//						isReturnOneNumb = false;
//					else
						isReturnOneNumb = true;
				}
				else if(Atype=="log")
				{
					Logs* lgA = new Logs(Anumb);
					Logs* lgB = new Logs(Bnumb);
					lgA->divide(*lgB);
					opAnswer = lgA->getAnswer();
												//delete[] lg;
					if(opAnswer.find("/")<100){			//if the opanswer string contains "+", means it return a complex expression

						isReturnOneNumb = false;}
					else
						isReturnOneNumb = true;
				}
				else if(Atype=="root")
				{
					nthRoot* nthNumb = new nthRoot(Anumb);
					nthRoot* B = new nthRoot(Bnumb);
					nthNumb->divide(*B);
					opAnswer = nthNumb->getAns();
					if(opAnswer.find("/")<100)			//if the opanswer string contains "+", means it return a complex expression
						isReturnOneNumb = false;
					else
						isReturnOneNumb = true;

				}//it is handled in the calculating()
				else if(Atype=="pi"){
//					Pi* p = new Pi(Anumb);
//					p->Divide(*p);
//					opAnswer = p->getAnswer();
					isReturnOneNumb = true;
				}
				else if(Atype=="e"){
					Exponential* p = new Exponential(Anumb);
					Exponential* b = new Exponential(Bnumb);
					p->Divide(*b);
					opAnswer = p->getAnswer();
					isReturnOneNumb = true;
				}else if(Atype=="exp"){
					Exponent* power = new Exponent(Anumb);
					Exponent* b = new Exponent(Bnumb);
					power->divide(*b);
					opAnswer = power->getAnswer();
					if(opAnswer.find("-")<100)			//if the opanswer string contains "+", means it return a complex expression
						isReturnOneNumb = false;
					else
						isReturnOneNumb = true;
				}
			}else{	//if not the same type

			}
}
 void NobracketString::Multip(string Anumb,string Atype, string Bnumb, string Btype){

		isReturnOneNumb = false;
			if(Atype==Btype){						//if they are the same type;
				if(Atype == "frac")
				{
					Fraction* fra = new Fraction(Anumb);
					Fraction* frb = new Fraction(Bnumb);
					fra->Multiplication(*frb);
					opAnswer = fra->getAnswer();
					isReturnOneNumb = true;				// here may need to delete the object.
				}
				else if(Atype == "int")
				{
					Integers* intnumbA = new Integers(Anumb);
					Integers* intnumbB = new Integers(Bnumb);
					intnumbA->Multiply(*intnumbB);
					opAnswer = intnumbA->getAnswer();
										////							//delete[] intnumb;
					isReturnOneNumb = true;
				}
				else if(Atype=="log")
				{
					Logs* lgA = new Logs(Anumb);
					Logs* lgB = new Logs(Bnumb);
					lgA->Multip(*lgB);
					opAnswer = lgA->getAnswer();
												//delete[] lg;
					if(opAnswer.find("*")<100)			//if the opanswer string contains "+", means it return a complex expression
						isReturnOneNumb = false;
					else
						isReturnOneNumb = true;
				}
				else if(Atype=="root")
				{
					nthRoot* nthNumb = new nthRoot(Anumb);
					nthRoot* B = new nthRoot(Bnumb);
					nthNumb->multiply(*B);
					opAnswer = nthNumb->getAns();
					if(opAnswer.find("*")<100)			//if the opanswer string contains "+", means it return a complex expression
						isReturnOneNumb = false;
					else
						isReturnOneNumb = true;
				}//it is handled in the calculating()
				else if(Atype=="pi"){
//					Pi* p = new Pi(Anumb);
//					p->Multiply(*p);
//					opAnswer = p->getAnswer();
					isReturnOneNumb = true;
				}
				else if(Atype=="e"){
					Exponential* p = new Exponential(Anumb);
					p->Multiply(*p);
					opAnswer = p->getAnswer();
					isReturnOneNumb = true;
				}else if(Atype=="exp"){
					Exponent* power = new Exponent(Anumb);
					Exponent* b = new Exponent(Bnumb);
					power->multiply(*b);
					opAnswer = power->getAnswer();
					if(opAnswer.find("-")<100)			//if the opanswer string contains "+", means it return a complex expression
						isReturnOneNumb = false;
					else
						isReturnOneNumb = true;
				}

			}
			else{

				if((Atype=="frac"&&Btype=="int")||(Btype=="frac"&&Atype=="int")){	//if not the same type


					Fraction* fra = new Fraction(Anumb);
					Fraction* frb = new Fraction(Bnumb);
					fra->Multiplication(*frb);
					opAnswer = fra->getAnswer();
					isReturnOneNumb = true;
				}else if((Atype=="int"&&Btype=="root")||(Btype=="int"&&Atype=="root")){

					nthRoot* nthNumb = new nthRoot(Anumb);

					nthRoot* B = new nthRoot(Bnumb);

					nthNumb->multiply(*B);

					opAnswer = nthNumb->getAns();

//					if(opAnswer.find("*")<100)			//if the opanswer string contains "+", means it return a complex expression
//						isReturnOneNumb = true;
//					else
						isReturnOneNumb = true;
				}
				else{

					isReturnOneNumb=false;
				}

			}
}

 void NobracketString::calculating(){

   	bool havesametype=false;
   	//check for mutipositio
   	int temporarySize=0;
   if(op.size()==0){

   }else{
   	for(int i = 0;i<=op.size();++i){							//check if op contains '*'

   		if(temporarySize != op.size()){
   		  		i = 0;
   		  	}
   		temporarySize= op.size();
   		if(op[i]=='/'){
   			if(i==0){
   				divide(somenumbs[0],type[0],somenumbs[1],type[1]);
   				if(isReturnOneNumb){									//if the answer == is return one value example: log_3:4;

   					somenumbs[i]=opAnswer;								//set the element i to the opAnser,
   				  	somenumbs.erase(somenumbs.begin()+1);			//erase the second element
   				  	op.erase(op.begin());							//erase the '*'
   				}else{
   					////cout<<"the '*' sign in the index 0 and the answer return more then one value"<<endl;
   				}
   			}else{

   				divide(somenumbs[i],type[i],somenumbs[i+1],type[i+1]);
   				if(isReturnOneNumb){									//if the answer == is return one value example: log_3:4;
   					somenumbs[i]=opAnswer;								//set the element i to the opAnser,
   					somenumbs.erase(somenumbs.begin()+(i+1));			//erase the second element
   					op.erase(op.begin()+(i));							//erase the '*'
 //  					cout<<"the mutip() get answer is now "<<somenumbs[i]<<endl;
 //  					cout<<"im in the calculating function delect '*' sign DOES NOT in the index 0"<<endl;
   				}
   				else{

   		}
   		}
   		if(op[i]=='*'){

   			if(i==0){

   				Multip(somenumbs[0],type[0],somenumbs[1],type[1]);		//do the mulip()
   				if(isReturnOneNumb){									//if the answer == is return one value example: log_3:4;
   					somenumbs[i]=opAnswer;								//set the element i to the opAnser,
   					somenumbs.erase(somenumbs.begin()+1);			//erase the second element
   					op.erase(op.begin());							//erase the '*'
 //
   				}
   				/*
   				 * for 3*sqrt:3+7*sqrt:3 this case;
   				 */
   				else{
   					//cout<<"the '*' sign in the index 0 and the answer return more then one value"<<endl;
   				}								// if the answer return more then one value, example 5*log_3:4;
 //  					somenumbs[i]=opAnswer;
 //  					somenumbs.erase(somenumbs.begin()+1);			//erase the second element
 //  					op.erase(op.begin());	//do the mulitify everything as it is.
   			}
   			else{
   				//cout<<"do the mulitify."<<endl;
   				Multip(somenumbs[i],type[i],somenumbs[i+1],type[i+1]);
   				if(isReturnOneNumb){									//if the answer == is return one value example: log_3:4;
   					somenumbs[i]=opAnswer;								//set the element i to the opAnser,
   					somenumbs.erase(somenumbs.begin()+(i+1));			//erase the second element
   					op.erase(op.begin()+(i));							//erase the '*'
 //
   				}
   				else{}												// if the answer return more then one value, example 5*log_3:4;
   																	//keep everything as it is.
   			}

   		}
   		else{}	//if(op[i]!='*', do nothing;
   	//if(temporarySize != op.size()){
   	//	i = 0;
   	//}
   	}					//end of checking '*'
   }



 for(int i=0;type.size()-1>=somenumbs.size();i++){
 	type.pop_back();

 }
 int tempSize=0;
   	for(int i=0;i<op.size();i++){				//start to check if they have the same type; ad do the calculation
   		for(int j=i+1;j<op.size()+1;j++)
   		{
   			tempSize=op.size();

   				if((type[i]==type[j]&&op[j]=='*')||(type[i]==type[j]&&op[i]=='*')){		//if the op is a *, skip
   					//do nothing;

   				}
   				else if(type[i]==type[j]&&op[j-1]!='*'&&op[j-1]!='*'){				//if it has same type, and op does not have *,check for operator

   					havesametype = true;
   					if(op[j-1]=='+')
   					{				//only have two case +,-
   						add(somenumbs[j],type[j],somenumbs[i],type[i]);

   						if(isReturnOneNumb)
   						{

   							somenumbs[i]=opAnswer;
   							if(somenumbs.size()==2&&type.size()==2&&type[1]!=type[0])//set the element i to the opAnser,
   							{
   								isReturnOneNumb=false;
   								havesametype = false;

   							}else{
   								somenumbs.erase(somenumbs.begin()+(j));	//erase the second element
   								type.erase(type.begin()+j);
   								op.erase(op.begin()+(j-1));				//erase the op

   							}


   						}
   						else
   						{
   							//don't change anything.
   						}
   								// here need to do something with vectors somenumb and type
   								// 3 + 7 = 10, 10 will replace 3 in somenumb vector and delete 7 and + from somenumb and type;
   								// log_3:8 + log_3:7 will return as it is, so the vectors does not change, keep as it is.
   					}
   					else					//containts "-"l
   					{
   						substract(somenumbs[j],type[j],somenumbs[i],type[i]);
   						if(isReturnOneNumb)
   						{
   							somenumbs[i]=opAnswer;							//set the element i to the opAnser,
   							somenumbs.erase(somenumbs.begin()+(j));			//erase the second element
   						 	op.erase(op.begin()+(j-1));				//erase the op

   						}
   						else
   						{
   							 //don't change anything.
   						}
   					}
   				}
   				else if((type[i]=="frac"&&type[j]=="int") || (type[j]=="frac"&&type[i]=="int"))
   				{

   					// handle one numb is fraction, one numb is integer
   					havesametype =true;
   					if(op[j-1]=='+')
   					{			//only have two case +,-

   						add(somenumbs[j],"frac",somenumbs[i],"frac");
   						if(isReturnOneNumb)
   						   	{
   						   		somenumbs[i]=opAnswer;							//set the element i to the opAnser,
   						   		somenumbs.erase(somenumbs.begin()+(j));			//erase the second element
   						   		op.erase(op.begin()+(j-1));				//erase the op
   						   		   						   	}
   						   	else
   						   	{
   						   		 //don't change anything.
   						   	}
   					}
   					else
   					{
   						substract(somenumbs[j],"frac",somenumbs[i],"frac");
   						if(isReturnOneNumb)
   		   				{
   		   					somenumbs[i]=opAnswer;							//set the element i to the opAnser,
   		   					somenumbs.erase(somenumbs.begin()+(j));			//erase the second element
   		   					op.erase(op.begin()+(j-1));				//erase the op

   		   				}
   		   				else
   		   				{
   		   					 //don't change anything.
   		   				}
   					}
   				}							//check continue comparing the next type[i+1];

   				if(tempSize != op.size()){
   					j=0;
   				}
   				//after loop if we cannot find the same type;
   			}//end of the int j loop
 //  					//cout<<"end check for type here"<<j<<endl;
   		}//end of the int i loop
   }
 }

void NobracketString::formFinalAnser(){
	int i = 0;

	if(op.size()==0){
		FiAnswer += somenumbs[0];

	}
	else{
	for(i;i<op.size();i++){
		FiAnswer += (somenumbs[i]+op[i]);

	}
	FiAnswer += somenumbs[i];
	}
}

bool NobracketString::ansIsComplex(){
	if(somenumbs.size()==1){
		//isnt complex
		return false;
	}
	else{
		//is complex
		return true;
	}
}


