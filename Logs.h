/*
 * Logs.h
 *
 *  Created on: Apr 6, 2014
 *      Author: Sissi
 */

/*
	Update(4/6):
	1. this class expects to receive a string type input.
	2. in the constructorit will check if it receive the right format 		"log_x:y".
		*I assume x,y are correct input.I did not check here.*
	3. It also get the number x, y and convert them to integer type
	4. can receive e, and pi as a base, I set they as 2.718281, and 3.141592.
	5. canSimplify() function will check if the log can be simplify to a integer. if it can, it will return as a integer to the Calculator class.
		* Example: log_3:9=2 *
	6. FinalSplit class will split one log into two logs format.
		* log_2:15 = log_2:3 + log_2:5;
		* if cannot split it will keep as it is.
	7. IntSimplify() only use when canSimplify() return true, otherwise it will give a decimal value;
	8.  void add(log lg);
		void substract(log lg);
		void divide(log lg);
		void Multip(log lg);
		every time doing these operation, lg need to do lg.canSimplify() first.
	9.everything change base, and numb value, need to call FormNewLog() function to refresh string type log.
	10. thses function exist bug, log_3:(3^2), this case need to convert 3^2 = 9 first, and then do the calculation. need help from nthRoot class.
	11. basicly finish.
 */
/*
	Update(4/8):
	1. put Simplify() to the constructor, so then when calling the  constractor, it will do the simplify first.
	2. add getSimplify() function, so it can
	3. add a function canSimplifytoFra(), this will return a fraction.
	4. because it can simplify to both int and fra, so here I have two bool function();
	5.fix the simplify error here.

 */
#ifndef LOGS_H_
#define LOGS_H_

#include <strstream>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

class Logs{
	strstream ss;
	string somelog;
	string strbase;
	string strnumb;
	string strfronumb;
	//this suposse to be a pointer, change this will also change the function.
	double base;
	double numb;//only can be an integer at this point.
	double frontIntNumb;

public:
	Logs(string str);
	~Logs();
	bool canSimplifytoInt();
	bool canSimplifytoFra();
	void Simplify();
	string FinalSplit();
	//assume these log lg cannot be simplify;
	//it has to be type log, has base and numb;
	void add(Logs& lg);
	void substract(Logs& lg);
	void divide(Logs& lg);
	void Multip(Logs& lg);

	//string getStrfronstrNumb();
	double getFrontIntNumb();
	double getBase();
	double getNumb();
	string getAnswer();//return one string
	string getSimplify();//return simplify value;
	void FormNewLog();//everytime change base and numb need to use this function.
};

#endif /* LOGS_H_ */
